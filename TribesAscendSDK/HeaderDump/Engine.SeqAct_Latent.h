#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
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
	class SeqAct_Latent : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<class Actor*>, LatentActors, 232)
		ADD_BOOL(bAborted, 244, 0x1)
		void AbortFor(class Actor* latentActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25540);
			byte params[4] = { NULL };
			*(class Actor**)params = latentActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Update(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25542);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
