#pragma once
#include "TribesGame.TrDeployable.h"
#include "TribesGame.TrGameObjective.h"
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
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MainGeneratorIsOnline()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.MainGeneratorIsOnline");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PowerNearestFriend()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.PowerNearestFriend");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleasePoweredFriend()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.ReleasePoweredFriend");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseBackupGenerators()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.PulseBackupGenerators");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AsynchPowerCheck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.AsynchPowerCheck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoPowerCheck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.DoPowerCheck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.OnPowerStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoPowerUpdate(class TrDeployable* dep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.DoPowerUpdate");
			byte* params = (byte*)malloc(4);
			*(class TrDeployable**)params = dep;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
