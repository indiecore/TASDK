#pragma once
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVideoSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVideoSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVideoSettings : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, m_Cached_Resolution, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_VideoSettingsCount, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, m_VideoSettingsList)
		ADD_VAR(::IntProperty, m_ResolutionCount, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, m_ResolutionList)
		ADD_VAR(::IntProperty, m_Cached_ShadowDetail, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_Cached_TextureDetail, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_Cached_ScreenType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_Cached_MotionBlur, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_Cached_VerticalSync, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_Cached_SmoothFramerate, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetCurrentSettingValue'
		// Here lies the not-yet-implemented method 'GetSmoothFramerateValue'
		// Here lies the not-yet-implemented method 'GetAllowedResolutions'
		// Here lies the not-yet-implemented method 'ApplyVideoSettings'
		// Here lies the not-yet-implemented method 'ChangeScreenType'
		// Here lies the not-yet-implemented method 'ChangeResolution'
		// Here lies the not-yet-implemented method 'ChangeShadowDetail'
		// Here lies the not-yet-implemented method 'ChangeTextureDetail'
		// Here lies the not-yet-implemented method 'GetResolutions'
		// Here lies the not-yet-implemented method 'SetVSync'
		// Here lies the not-yet-implemented method 'SetMotionBlur'
		// Here lies the not-yet-implemented method 'LoadVideoSettings'
		// Here lies the not-yet-implemented method 'AddVideoSettingToList'
		// Here lies the not-yet-implemented method 'LoadVideoResolutions'
		// Here lies the not-yet-implemented method 'LoadResolutions'
		// Here lies the not-yet-implemented method 'AddResolutionToList'
		// Here lies the not-yet-implemented method 'GetSettingNameFromType'
		// Here lies the not-yet-implemented method 'GetSettingTypeFromName'
		// Here lies the not-yet-implemented method 'CacheVideoSetting'
		// Here lies the not-yet-implemented method 'SetSmoothFramerateValue'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
