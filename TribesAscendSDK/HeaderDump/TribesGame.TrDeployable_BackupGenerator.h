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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79904);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MainGeneratorIsOnline()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79905);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PowerNearestFriend()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79909);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleasePoweredFriend()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79914);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseBackupGenerators()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79915);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AsynchPowerCheck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79916);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoPowerCheck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79917);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79918);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoPowerUpdate(class TrDeployable* dep)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79919);
			byte params[4] = { NULL };
			*(class TrDeployable**)params = dep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79921);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79922);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
