#pragma once
#include "TribesGame__TrDeployable.h"
#include "TribesGame__TrGameObjective.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployable_BackupGenerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_BackupGenerator : public TrDeployable
	{
	public:
		ADD_OBJECT(TrGameObjective, m_PoweredFriend)
		// Here lies the not-yet-implemented method 'DeployComplete'
		// Here lies the not-yet-implemented method 'MainGeneratorIsOnline'
		// Here lies the not-yet-implemented method 'PowerNearestFriend'
		// Here lies the not-yet-implemented method 'ReleasePoweredFriend'
		// Here lies the not-yet-implemented method 'PulseBackupGenerators'
		// Here lies the not-yet-implemented method 'AsynchPowerCheck'
		// Here lies the not-yet-implemented method 'DoPowerCheck'
		// Here lies the not-yet-implemented method 'OnPowerStatusChanged'
		// Here lies the not-yet-implemented method 'DoPowerUpdate'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
	};
}
#undef ADD_OBJECT
