#pragma once
#include "TribesGame__TrDeployable_Sensor.h"
#include "Engine__Texture2D.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Controller.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_RadarSensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_RadarSensor : public TrDeployable_Sensor
	{
	public:
		ADD_VAR(::FloatProperty, m_fBlipIntervalTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'ReceivesPowerFromGenerator'
		// Here lies the not-yet-implemented method 'SpawnHelpTextCollisionProxy'
		// Here lies the not-yet-implemented method 'ShouldShowHelpText'
		// Here lies the not-yet-implemented method 'GetMarker'
		// Here lies the not-yet-implemented method 'SetPowered'
		// Here lies the not-yet-implemented method 'RadarBlip'
		// Here lies the not-yet-implemented method 'IsDeployed'
		// Here lies the not-yet-implemented method 'GiveDestroyAccolade'
		// Here lies the not-yet-implemented method 'ReleaseOutOfSightEnemies'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'AwardUpgradeAssists'
	};
}
#undef ADD_VAR
