#pragma once
#include "UTGame__UTPickupFactory.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTItemPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTItemPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTItemPickupFactory : public UTPickupFactory
	{
	public:
		ADD_VAR(::StrProperty, PickupMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UseHintMessage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PickupSound)
		// Here lies the not-yet-implemented method 'InitializePickup'
		// Here lies the not-yet-implemented method 'GetLocalString'
		// Here lies the not-yet-implemented method 'SpawnCopyFor'
		// Here lies the not-yet-implemented method 'SetRespawn'
		// Here lies the not-yet-implemented method 'GetRespawnTime'
		// Here lies the not-yet-implemented method 'BotDesireability'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
