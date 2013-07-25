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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
