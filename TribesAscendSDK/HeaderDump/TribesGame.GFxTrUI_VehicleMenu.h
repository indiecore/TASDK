#pragma once
#include "UTGame.UTGFxTweenableMoviePlayer.h"
namespace UnrealScript
{
	class GFxTrUI_VehicleMenu : public UTGFxTweenableMoviePlayer
	{
	public:
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65218);
			byte params[8] = { NULL };
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConfigureOptions(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65221);
			byte params[4] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleOptionsComplete(int Credits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65233);
			byte params[4] = { NULL };
			*(int*)params = Credits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleOptionsClear()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65235);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVehicleOption(ScriptString* ClassName, ScriptString* DisplayName, int Cost, int nIconIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65236);
			byte params[32] = { NULL };
			*(ScriptString**)params = ClassName;
			*(ScriptString**)&params[12] = DisplayName;
			*(int*)&params[24] = Cost;
			*(int*)&params[28] = nIconIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSelectedVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65241);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void OnVehicleScreenFinished()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65243);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
