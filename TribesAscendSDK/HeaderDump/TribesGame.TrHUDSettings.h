#pragma once
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHUDSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrHUDSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrHUDSettings : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, SettingsCount, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, SettingsList)
		float GetCurrentValue(byte Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDSettings.GetCurrentValue");
			byte* params = (byte*)malloc(5);
			*params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void SaveSetting(int Index, float val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUDSettings.SaveSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(float*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
