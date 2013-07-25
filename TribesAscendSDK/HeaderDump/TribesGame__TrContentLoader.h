#pragma once
#include "Core__Object.h"
namespace UnrealScript
{
	class TrContentLoader : public Object
	{
	public:
		bool StartLoadingDeviceContentPackage(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrContentLoader.StartLoadingDeviceContentPackage");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StartLoadingPlayerSkin(int ClassId, int skinId, bool bLoad1PData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrContentLoader.StartLoadingPlayerSkin");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = skinId;
			*(bool*)(params + 8) = bLoad1PData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
