#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Volume.h"
#include "Core.Object.h"
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
	class SeqAct_Teleport : public SequenceAction
	{
	public:
		ADD_BOOL(bCheckOverlap, 232, 0x2)
		ADD_BOOL(bUpdateRotation, 232, 0x1)
		ADD_STRUCT(ScriptArray<class Volume*>, TeleportVolumes, 240)
		ADD_STRUCT(float, TeleportDistance, 236)
		bool ShouldTeleport(class Actor* TestActor, Object::Vector TeleportLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Teleport.ShouldTeleport");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = TestActor;
			*(Object::Vector*)&params[4] = TeleportLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Teleport.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
