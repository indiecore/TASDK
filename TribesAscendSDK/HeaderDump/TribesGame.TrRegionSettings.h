#pragma once
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRegionSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRegionSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRegionSettings : public GFxObject
	{
	public:
		ADD_OBJECT(GFxObject, m_RegionSettingsList)
		ADD_VAR(::IntProperty, m_RegionSettingsCount, 0xFFFFFFFF)
		int GetPreferredSiteId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetPreferredSiteId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> LoadRegionSetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.LoadRegionSetting");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetRegionName(int siteId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetRegionName");
			byte* params = (byte*)malloc(16);
			*(int*)params = siteId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetRegionIdAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetRegionIdAtIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetRegionIndexByName(ScriptArray<wchar_t> regionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetRegionIndexByName");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = regionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void LoadRegions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.LoadRegions");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPreferredSiteId(int siteId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.SetPreferredSiteId");
			byte* params = (byte*)malloc(4);
			*(int*)params = siteId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadRegionLabels(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.LoadRegionLabels");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPreferredRegion(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.SetPreferredRegion");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddRegion(ScriptArray<wchar_t> regionName, int Id, bool bCustomOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.AddRegion");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = regionName;
			*(int*)(params + 12) = Id;
			*(bool*)(params + 16) = bCustomOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddSetting(ScriptName regionName, int Id)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.AddSetting");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = regionName;
			*(int*)(params + 8) = Id;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
