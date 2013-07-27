#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
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
	class SeqAct_AIMoveToActor : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(ScriptArray<class Actor*>, Destination, 252)
		ADD_STRUCT(int, LastDestinationChoice, 272)
		ADD_OBJECT(Actor, LookAt, 268)
		ADD_STRUCT(float, MovementSpeedModifier, 264)
		ADD_BOOL(bPickClosest, 248, 0x2)
		ADD_BOOL(bInterruptable, 248, 0x1)
		class Actor* PickDestination(class Actor* Requestor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_AIMoveToActor.PickDestination");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Requestor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_AIMoveToActor.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
