#pragma once
#include "TribesGame.TrDeployable.h"
#include "TribesGame.TrGameObjective.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployable_BackupGenerator : public TrDeployable
	{
	public:
		ADD_OBJECT(TrGameObjective, m_PoweredFriend, 1524)
		void DeployComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.DeployComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MainGeneratorIsOnline()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_BackupGenerator.MainGeneratorIsOnline");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[4] = { NULL };
			*(class TrDeployable**)&params[0] = dep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
