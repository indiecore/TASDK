#pragma once
#include "GFxUI.GFxObject.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrHUDSettings : public GFxObject
	{
	public:
		enum EHUDSettingType : byte
		{
			EHST_HEROTEXT = 0,
			EHST_COMBATLOG = 1,
			EHST_CREDITS = 2,
			EHST_CHAT = 3,
			EHST_SCORES = 4,
			EHST_ACCOLADES = 5,
			EHST_BADGES = 6,
			EHST_VISOR = 7,
			EHST_KILLBOX = 8,
			EHST_DEATHCAM = 9,
			EHST_PROMPTPANEL = 10,
			EHST_RESPAWNTIMER = 11,
			EHST_HEALTHBAR = 12,
			EHST_RETICULE = 13,
			EHST_SKIBARS = 14,
			EHST_FRIENDCOLOR = 15,
			EHST_CRACKS = 16,
			EHST_MAX = 17,
		};
		ADD_STRUCT(int, SettingsCount, 120)
		ADD_OBJECT(GFxObject, SettingsList, 124)
		float GetCurrentValue(TrHUDSettings::EHUDSettingType Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59226);
			byte params[5] = { NULL };
			*(TrHUDSettings::EHUDSettingType*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void SaveSetting(int Index, float val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96612);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(float*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
