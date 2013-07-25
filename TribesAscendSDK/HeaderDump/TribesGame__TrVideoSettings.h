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
		int GetCurrentSettingValue(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetCurrentSettingValue");
			byte* params = (byte*)malloc(5);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetSmoothFramerateValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetSmoothFramerateValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void GetAllowedResolutions(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ResolutionList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetAllowedResolutions");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = ResolutionList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ResolutionList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void ApplyVideoSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ApplyVideoSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeScreenType(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeScreenType");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeResolution(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeResolution");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeShadowDetail(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeShadowDetail");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeTextureDetail(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeTextureDetail");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetResolutions(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ResolutionList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetResolutions");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = ResolutionList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ResolutionList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void SetVSync(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.SetVSync");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMotionBlur(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.SetMotionBlur");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadVideoSettings(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.LoadVideoSettings");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVideoSettingToList(ScriptArray<wchar_t> SettingName, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.AddVideoSettingToList");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = SettingName;
			*(int*)(params + 12) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadVideoResolutions(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.LoadVideoResolutions");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadResolutions(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.LoadResolutions");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddResolutionToList(ScriptArray<wchar_t> Resolution)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.AddResolutionToList");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Resolution;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetSettingNameFromType(byte Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetSettingNameFromType");
			byte* params = (byte*)malloc(13);
			*params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		byte GetSettingTypeFromName(ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetSettingTypeFromName");
			byte* params = (byte*)malloc(13);
			*(ScriptArray<wchar_t>*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 12);
			free(params);
			return returnVal;
		}
		void CacheVideoSetting(int Index, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.CacheVideoSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSmoothFramerateValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.SetSmoothFramerateValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
