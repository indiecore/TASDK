#pragma once
#include "Core__Object.h"
namespace UnrealScript
{
	class TrInventoryHelper : public Object
	{
	public:
		ScriptClass* GetEquipClass(int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryHelper.GetEquipClass");
			byte* params = (byte*)malloc(8);
			*(int*)params = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetFamilyClass(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryHelper.GetFamilyClass");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetSkinClass(int skinId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryHelper.GetSkinClass");
			byte* params = (byte*)malloc(8);
			*(int*)params = skinId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
