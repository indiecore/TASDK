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
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ConfigureOptions(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.ConfigureOptions");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleOptionsComplete(int Credits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.VehicleOptionsComplete");
			byte* params = (byte*)malloc(4);
			*(int*)params = Credits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleOptionsClear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.VehicleOptionsClear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVehicleOption(ScriptArray<wchar_t> ClassName, ScriptArray<wchar_t> DisplayName, int Cost, int nIconIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.SetVehicleOption");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = ClassName;
			*(ScriptArray<wchar_t>*)(params + 12) = DisplayName;
			*(int*)(params + 24) = Cost;
			*(int*)(params + 28) = nIconIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetSelectedVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.GetSelectedVehicle");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void OnVehicleScreenFinished()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrUI_VehicleMenu.OnVehicleScreenFinished");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
