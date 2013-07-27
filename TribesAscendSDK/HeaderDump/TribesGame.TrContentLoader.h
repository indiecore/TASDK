#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class TrContentLoader : public Object
	{
	public:
		bool StartLoadingDeviceContentPackage(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77166);
			byte params[8] = { NULL };
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StartLoadingPlayerSkin(int ClassId, int skinId, bool bLoad1PData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78159);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = skinId;
			*(bool*)&params[8] = bLoad1PData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
