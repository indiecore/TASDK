#pragma once
#include "Engine.AnimNodeBlend.h"
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
	class AnimNodeBlendPerBone : public AnimNodeBlend
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, BranchStartBoneName, 264)
		ADD_STRUCT(ScriptArray<float>, Child2PerBoneWeight, 276)
		ADD_STRUCT(ScriptArray<byte>, LocalToCompReqBones, 288)
		ADD_BOOL(bForceLocalSpaceBlend, 260, 0x1)
		void SetBlendTarget(float BlendTarget, float BlendTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10886);
			byte params[8] = { NULL };
			*(float*)params = BlendTarget;
			*(float*)&params[4] = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
