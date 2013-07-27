#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class TrContentLoader : public Object
	{
	public:
		bool StartLoadingDeviceContentPackage(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrContentLoader.StartLoadingDeviceContentPackage");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StartLoadingPlayerSkin(int ClassId, int skinId, bool bLoad1PData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrContentLoader.StartLoadingPlayerSkin");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = skinId;
			*(bool*)&params[8] = bLoad1PData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
