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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.PlayOneShotAnim");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = AnimSeqName;
			*(float*)&params[8] = BlendInTime;
			*(float*)&params[12] = BlendOutTime;
			*(bool*)&params[16] = bDontBlendOut;
			*(float*)&params[20] = Rate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BlendToLoopingAnim(ScriptName AnimSeqName, float BlendInTime, float Rate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.BlendToLoopingAnim");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = AnimSeqName;
			*(float*)&params[8] = BlendInTime;
			*(float*)&params[12] = Rate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetAnimName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.GetAnimName");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		class AnimNodeSequence* GetActiveChild()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeCrossfader.GetActiveChild");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
