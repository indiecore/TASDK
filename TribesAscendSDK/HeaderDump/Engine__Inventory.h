#pragma once
#include "Engine__Actor.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "Engine__InventoryManager.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Inventory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Inventory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Inventory : public Actor
	{
	public:
		ADD_OBJECT(ScriptClass, DroppedPickupClass)
		ADD_VAR(::StrProperty, PickupForce, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PickupSound)
		ADD_VAR(::StrProperty, PickupMessage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPredictRespawns, 0x4)
		ADD_VAR(::BoolProperty, bDelayedSpawn, 0x2)
		ADD_VAR(::BoolProperty, bDropOnDeath, 0x1)
		ADD_VAR(::StrProperty, ItemName, 0xFFFFFFFF)
		ADD_OBJECT(InventoryManager, InvManager)
		ADD_OBJECT(Inventory, Inventory)
		// Here lies the not-yet-implemented method 'DetourWeight'
		// Here lies the not-yet-implemented method 'GiveTo'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'BotDesireability'
		// Here lies the not-yet-implemented method 'AnnouncePickup'
		// Here lies the not-yet-implemented method 'GivenTo'
		// Here lies the not-yet-implemented method 'ClientGivenTo'
		// Here lies the not-yet-implemented method 'ItemRemovedFromInvManager'
		// Here lies the not-yet-implemented method 'DenyPickupQuery'
		// Here lies the not-yet-implemented method 'DropFrom'
		// Here lies the not-yet-implemented method 'GetLocalString'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
