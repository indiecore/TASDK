#pragma once
#include "UTGame.UTGFxTweenableMoviePlayer.h"
namespace UnrealScript
{
	class GFxTrUI_VehicleMenu : public UTGFxTweenableMoviePlayer
	{
	public:
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.Start");
			byte params[8] = { NULL };
			*(bool*)&params[0] = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConfigureOptions(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.ConfigureOptions");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleOptionsComplete(int Credits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.VehicleOptionsComplete");
			byte params[4] = { NULL };
			*(int*)&params[0] = Credits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleOptionsClear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.VehicleOptionsClear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVehicleOption(ScriptString* ClassName, ScriptString* DisplayName, int Cost, int nIconIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.SetVehicleOption");
			byte params[32] = { NULL };
			*(ScriptString**)&params[0] = ClassName;
			*(ScriptString**)&params[12] = DisplayName;
			*(int*)&params[24] = Cost;
			*(int*)&params[28] = nIconIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSelectedVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.GetSelectedVehicle");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void OnVehicleScreenFinished()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.OnVehicleScreenFinished");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
