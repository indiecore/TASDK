#pragma once
#include "UDKBase.UDKGameSettingsCommon.h"
#include "Engine.GameInfo.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGameSettingsCommon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTGameSettingsCommon : public UDKGameSettingsCommon
	{
	public:
		ADD_VAR(::IntProperty, MaxPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinNetPlayers, 0xFFFFFFFF)
		void SetCustomMapName(ScriptArray<wchar_t> MapName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetCustomMapName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = MapName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOfficialMutatorBitmask(int MutatorBitmask)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetOfficialMutatorBitmask");
			byte* params = (byte*)malloc(4);
			*(int*)params = MutatorBitmask;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BuildURL(ScriptArray<wchar_t>& OutURL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.BuildURL");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = OutURL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutURL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void UpdateFromURL(ScriptArray<wchar_t>& URL, class GameInfo* Game)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.UpdateFromURL");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = URL;
			*(class GameInfo**)(params + 12) = Game;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void SetMutators(ScriptArray<wchar_t>& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetMutators");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		int GenerateMutatorBitmaskFromURL(class UTUIDataStore_MenuItems* MenuDataStore, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& MutatorClassNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.GenerateMutatorBitmaskFromURL");
			byte* params = (byte*)malloc(20);
			*(class UTUIDataStore_MenuItems**)params = MenuDataStore;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = MutatorClassNames;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MutatorClassNames = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetCustomMutators(class UTUIDataStore_MenuItems* MenuDataStore, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& MutatorClassNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetCustomMutators");
			byte* params = (byte*)malloc(16);
			*(class UTUIDataStore_MenuItems**)params = MenuDataStore;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = MutatorClassNames;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MutatorClassNames = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
	};
}
#undef ADD_VAR
