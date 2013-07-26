#pragma once
#include "Core.Object.Vector.h"
#include "TribesGame.TrSubDevice.h"
namespace UnrealScript
{
	class TrSubDevice_Turret : public TrSubDevice
	{
	public:
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSubDevice_Turret.GetPhysicalFireStartLoc");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSubDevice_Turret.GetFireInterval");
			byte* params = (byte*)malloc(5);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
