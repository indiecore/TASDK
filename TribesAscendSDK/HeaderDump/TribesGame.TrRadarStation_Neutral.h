#pragma once
#include "TribesGame.TrDeployable_RadarSensor.h"
#include "TribesGame.TrHelpTextManager.h"
#include "Engine.Texture2D.h"
namespace UnrealScript
{
	class TrRadarStation_Neutral : public TrDeployable_RadarSensor
	{
	public:
		bool ShouldShowHelpText(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110376);
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110379);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
