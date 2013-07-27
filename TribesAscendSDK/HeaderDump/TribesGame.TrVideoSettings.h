#pragma once
#include "PlatformCommon.TgPlayerProfile.h"
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
	class TrVideoSettings : public GFxObject
	{
	public:
		enum EVideoSettingType : byte
		{
			EVST_ShadowDetail = 0,
			EVST_TextureDetail = 1,
			EVST_ScreenType = 2,
			EVST_MotionBlur = 3,
			EVST_VerticalSync = 4,
			EVST_AntiAliasing = 5,
			EVST_Resolution = 6,
			EVST_SmoothFramerate = 7,
			EVST_MAX = 8,
		};
		enum EScreenFrameType : byte
		{
			ESFT_FullScreen = 0,
			ESFT_Windowed = 1,
			ESFT_Borderless = 2,
			ESFT_MAX = 3,
		};
		enum EAntiAliasing : byte
		{
			EAA_Off = 0,
			EAA_1X = 1,
			EAA_2X = 2,
			EAA_4X = 3,
			EAA_MAX = 4,
		};
		enum EVisualDetail : byte
		{
			EVQ_Off = 0,
			EVQ_Low = 1,
			EVQ_Med = 2,
			EVQ_High = 3,
			EVQ_VHigh = 4,
			EVQ_MAX = 5,
		};
		class ResolutionData
		{
		public:
			ADD_STRUCT(int, ResY, 4)
			ADD_STRUCT(int, ResX, 0)
		};
		ADD_STRUCT(int, m_Cached_Resolution, 156)
		ADD_STRUCT(int, m_VideoSettingsCount, 124)
		ADD_OBJECT(GFxObject, m_VideoSettingsList, 132)
		ADD_STRUCT(int, m_ResolutionCount, 120)
		ADD_OBJECT(GFxObject, m_ResolutionList, 128)
		ADD_STRUCT(int, m_Cached_ShadowDetail, 136)
		ADD_STRUCT(int, m_Cached_TextureDetail, 140)
		ADD_STRUCT(int, m_Cached_ScreenType, 144)
		ADD_STRUCT(int, m_Cached_MotionBlur, 148)
		ADD_STRUCT(int, m_Cached_VerticalSync, 152)
		ADD_STRUCT(int, m_Cached_SmoothFramerate, 160)
		int GetCurrentSettingValue(TrVideoSettings::EVideoSettingType Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetCurrentSettingValue");
			byte params[5] = { NULL };
			*(TrVideoSettings::EVideoSettingType*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetSmoothFramerateValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetSmoothFramerateValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void GetAllowedResolutions(ScriptArray<TrVideoSettings::ResolutionData>& ResolutionList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetAllowedResolutions");
			byte params[12] = { NULL };
			*(ScriptArray<TrVideoSettings::ResolutionData>*)&params[0] = ResolutionList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ResolutionList = *(ScriptArray<TrVideoSettings::ResolutionData>*)&params[0];
		}
		void ApplyVideoSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ApplyVideoSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeScreenType(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeScreenType");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeResolution(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeResolution");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeShadowDetail(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeShadowDetail");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeTextureDetail(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.ChangeTextureDetail");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetResolutions(ScriptArray<TgPlayerProfile::PropertyPair>& ResolutionList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetResolutions");
			byte params[12] = { NULL };
			*(ScriptArray<TgPlayerProfile::PropertyPair>*)&params[0] = ResolutionList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ResolutionList = *(ScriptArray<TgPlayerProfile::PropertyPair>*)&params[0];
		}
		void SetVSync(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.SetVSync");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMotionBlur(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.SetMotionBlur");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadVideoSettings(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.LoadVideoSettings");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVideoSettingToList(ScriptString* SettingName, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.AddVideoSettingToList");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = SettingName;
			*(int*)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadVideoResolutions(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.LoadVideoResolutions");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadResolutions(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.LoadResolutions");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddResolutionToList(ScriptString* Resolution)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.AddResolutionToList");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Resolution;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSettingNameFromType(TrVideoSettings::EVideoSettingType Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetSettingNameFromType");
			byte params[13] = { NULL };
			*(TrVideoSettings::EVideoSettingType*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		TrVideoSettings::EVideoSettingType GetSettingTypeFromName(ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.GetSettingTypeFromName");
			byte params[13] = { NULL };
			*(ScriptString**)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrVideoSettings::EVideoSettingType*)&params[12];
		}
		void CacheVideoSetting(int Index, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.CacheVideoSetting");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSmoothFramerateValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVideoSettings.SetSmoothFramerateValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
