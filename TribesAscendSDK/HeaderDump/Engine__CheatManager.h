#pragma once
#include "Core__Object.h"
#include "Engine__DebugCameraController.h"
#include "Engine__Weapon.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CheatManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CheatManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CheatManager : public Object
	{
	public:
		ADD_VAR(::StrProperty, OwnCamera, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ViewingFrom, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DebugCameraControllerClass)
		ADD_OBJECT(DebugCameraController, DebugCameraControllerRef)
		// Here lies the not-yet-implemented method 'FXPlay'
		// Here lies the not-yet-implemented method 'FXStop'
		// Here lies the not-yet-implemented method 'DebugAI'
		// Here lies the not-yet-implemented method 'EditAIByTrace'
		// Here lies the not-yet-implemented method 'DebugPause'
		// Here lies the not-yet-implemented method 'ListDynamicActors'
		// Here lies the not-yet-implemented method 'FreezeFrame'
		// Here lies the not-yet-implemented method 'WriteToLog'
		// Here lies the not-yet-implemented method 'KillViewedActor'
		// Here lies the not-yet-implemented method 'Teleport'
		// Here lies the not-yet-implemented method 'ChangeSize'
		// Here lies the not-yet-implemented method 'EndPath'
		// Here lies the not-yet-implemented method 'Amphibious'
		// Here lies the not-yet-implemented method 'Fly'
		// Here lies the not-yet-implemented method 'Walk'
		// Here lies the not-yet-implemented method 'Ghost'
		// Here lies the not-yet-implemented method 'AllAmmo'
		// Here lies the not-yet-implemented method 'God'
		// Here lies the not-yet-implemented method 'Slomo'
		// Here lies the not-yet-implemented method 'SetJumpZ'
		// Here lies the not-yet-implemented method 'SetGravity'
		// Here lies the not-yet-implemented method 'SetSpeed'
		// Here lies the not-yet-implemented method 'KillAll'
		// Here lies the not-yet-implemented method 'KillAllPawns'
		// Here lies the not-yet-implemented method 'KillPawns'
		// Here lies the not-yet-implemented method 'Avatar'
		// Here lies the not-yet-implemented method 'Summon'
		// Here lies the not-yet-implemented method 'GiveWeapon'
		// Here lies the not-yet-implemented method 'PlayersOnly'
		// Here lies the not-yet-implemented method 'DestroyFractures'
		// Here lies the not-yet-implemented method 'FractureAllMeshes'
		// Here lies the not-yet-implemented method 'FractureAllMeshesToMaximizeMemoryUsage'
		// Here lies the not-yet-implemented method 'RememberSpot'
		// Here lies the not-yet-implemented method 'ViewSelf'
		// Here lies the not-yet-implemented method 'ViewPlayer'
		// Here lies the not-yet-implemented method 'ViewActor'
		// Here lies the not-yet-implemented method 'ViewBot'
		// Here lies the not-yet-implemented method 'ViewClass'
		// Here lies the not-yet-implemented method 'Loaded'
		// Here lies the not-yet-implemented method 'AllWeapons'
		// Here lies the not-yet-implemented method 'SetLevelStreamingStatus'
		// Here lies the not-yet-implemented method 'EnableDebugCamera'
		// Here lies the not-yet-implemented method 'InitCheatManager'
		// Here lies the not-yet-implemented method 'LogPlaySoundCalls'
		// Here lies the not-yet-implemented method 'LogParticleActivateSystemCalls'
		// Here lies the not-yet-implemented method 'VerifyNavMeshObjects'
		// Here lies the not-yet-implemented method 'DrawUnsupportingEdges'
		// Here lies the not-yet-implemented method 'PrintNavMeshObstacles'
		// Here lies the not-yet-implemented method 'DumpCoverStats'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
