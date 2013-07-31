#pragma once
#include "Engine.AnimNode.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeBlendBase : public AnimNode
	{
	public:
		struct AnimBlendChild
		{
		public:
			ADD_OBJECT(AnimNode, Anim, 8)
			ADD_STRUCT(int, DrawY, 24)
			ADD_BOOL(bIsAdditive, 20, 0x2)
			ADD_BOOL(bMirrorSkeleton, 20, 0x1)
			ADD_STRUCT(float, BlendWeight, 16)
			ADD_STRUCT(float, Weight, 12)
			ADD_STRUCT(ScriptName, Name, 0)
		};
		ADD_STRUCT(ScriptArray<AnimNodeBlendBase::AnimBlendChild>, Children, 224)
		ADD_STRUCT(Object::AlphaBlendType, BlendType, 240)
		ADD_BOOL(bFixNumChildren, 236, 0x1)
		void PlayAnim(bool bLoop, float Rate, float StartTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10708);
			byte params[12] = { NULL };
			*(bool*)params = bLoop;
			*(float*)&params[4] = Rate;
			*(float*)&params[8] = StartTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10712);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplayAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10713);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
