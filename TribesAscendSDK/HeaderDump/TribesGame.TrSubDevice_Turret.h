#pragma once
#include "TribesGame.TrSubDevice.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class TrSubDevice_Turret : public TrSubDevice
	{
	public:
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113009);
			byte params[24] = { NULL };
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		float GetFireInterval(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113012);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
	};
}
