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
namespace UnrealScript
{
	class AnimNodeAdditiveBlending : public AnimNodeBlend
	{
	public:
		ADD_BOOL(bPassThroughWhenNotRendered, 260, 0x1)
		void SetBlendTarget(float BlendTarget, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeAdditiveBlending.SetBlendTarget");
			byte params[8] = { NULL };
			*(float*)&params[0] = BlendTarget;
			*(float*)&params[4] = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
