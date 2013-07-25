#pragma once
#include "Engine__Info.h"
#include "TribesGame__TrVehicle.h"
#include "TribesGame__TrDevice_SaberLauncher.h"
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__TrProj_TrackingMissile.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSeekingMissileManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSeekingMissileManager : public Info
	{
	public:
		ADD_VAR(::IntProperty, RepCounter, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'AddSaberLauncher'
		// Here lies the not-yet-implemented method 'RemoveSaberLauncher'
		// Here lies the not-yet-implemented method 'GetNumSaberLaunchersTargetingController'
		// Here lies the not-yet-implemented method 'GetNumSaberLaunchersTargetingVehicle'
		// Here lies the not-yet-implemented method 'AddMissile'
		// Here lies the not-yet-implemented method 'RemoveMissile'
		// Here lies the not-yet-implemented method 'GetNumMissilesTrackingController'
		// Here lies the not-yet-implemented method 'GetNumMissilesTrackingVehicle'
		// Here lies the not-yet-implemented method 'VictimControllerUpdated'
		// Here lies the not-yet-implemented method 'TargetVehicleUpdated'
		// Here lies the not-yet-implemented method 'BeginSaberLauncherTargeting'
		// Here lies the not-yet-implemented method 'StopSaberLauncherTargeting'
		// Here lies the not-yet-implemented method 'BeginMissileTracking'
		// Here lies the not-yet-implemented method 'StopMissileTracking'
		// Here lies the not-yet-implemented method 'PawnLeftVehicle'
		// Here lies the not-yet-implemented method 'PawnEnteredVehicle'
	};
}
#undef ADD_VAR
