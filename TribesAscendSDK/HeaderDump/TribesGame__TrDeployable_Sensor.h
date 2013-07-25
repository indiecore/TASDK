#pragma once
#include "TribesGame__TrDeployable.h"
#include "Engine__Pawn.h"
#include "Engine__Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_Sensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_Sensor : public TrDeployable
	{
	public:
		ADD_VAR(::FloatProperty, m_fDetectionZOffset, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'CheckLOS'
		// Here lies the not-yet-implemented method 'DeployComplete'
		// Here lies the not-yet-implemented method 'ModifyDetectedPawn'
		// Here lies the not-yet-implemented method 'SetPowered'
		// Here lies the not-yet-implemented method 'AddDetectedPawn'
		// Here lies the not-yet-implemented method 'RemoveDetectedPawn'
		// Here lies the not-yet-implemented method 'ReleaseAllDetectedPawns'
		// Here lies the not-yet-implemented method 'ManageEnemiesOutOfSight'
		// Here lies the not-yet-implemented method 'ReleaseOutOfSightEnemies'
		// Here lies the not-yet-implemented method 'ShouldDetectPawn'
		// Here lies the not-yet-implemented method 'OnPawnDetectedByCollisionProxy'
		// Here lies the not-yet-implemented method 'IsInRange'
		// Here lies the not-yet-implemented method 'OnPawnExitedCollisionProxy'
		// Here lies the not-yet-implemented method 'IsDeployed'
		// Here lies the not-yet-implemented method 'ScanTargets'
		// Here lies the not-yet-implemented method 'OnPowerStatusChanged'
		// Here lies the not-yet-implemented method 'GetMarker'
	};
}
#undef ADD_VAR
