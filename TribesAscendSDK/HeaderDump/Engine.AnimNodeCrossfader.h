#pragma once
#include "Engine.AnimNodeBlend.h"
#include "Engine.AnimNodeSequence.h"
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
namespace UnrealScript
{
	class AnimNodeCrossfader : public AnimNodeBlend
	{
	public:
		ADD_STRUCT(float, PendingBlendOutTimeOneShot, 272)
		ADD_BOOL(bDontBlendOutOneShot, 268, 0x1)
		ADD_STRUCT(ScriptName, DefaultAnimSeqName, 260)
		void PlayOneShotAnim(ScriptName AnimSeqName, float BlendInTime, float BlendOutTime, bool bDontBlendOut, float Rate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10892);
			byte params[24] = { NULL };
			*(ScriptName*)params = AnimSeqName;
			*(float*)&params[8] = BlendInTime;
			*(float*)&params[12] = BlendOutTime;
			*(bool*)&params[16] = bDontBlendOut;
			*(float*)&params[20] = Rate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BlendToLoopingAnim(ScriptName AnimSeqName, float BlendInTime, float Rate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10898);
			byte params[16] = { NULL };
			*(ScriptName*)params = AnimSeqName;
			*(float*)&params[8] = BlendInTime;
			*(float*)&params[12] = Rate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetAnimName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10902);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		class AnimNodeSequence* GetActiveChild()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10904);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
