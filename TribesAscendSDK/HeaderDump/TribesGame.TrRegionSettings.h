#pragma once
#include "GFxUI.GFxObject.h"
#include "GameFramework.SeqAct_ModifyProperty.h"
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
	class TrRegionSettings : public GFxObject
	{
	public:
		ADD_STRUCT(ScriptArray<SeqAct_ModifyProperty::PropertyInfo>, AvailableRegions, 128)
		ADD_OBJECT(GFxObject, m_RegionSettingsList, 124)
		ADD_STRUCT(int, m_RegionSettingsCount, 120)
		int GetPreferredSiteId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetPreferredSiteId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptString* LoadRegionSetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.LoadRegionSetting");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetRegionName(int siteId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetRegionName");
			byte params[16] = { NULL };
			*(int*)&params[0] = siteId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int GetRegionIdAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetRegionIdAtIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetRegionIndexByName(ScriptString* regionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.GetRegionIndexByName");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = regionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void LoadRegions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.LoadRegions");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPreferredSiteId(int siteId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.SetPreferredSiteId");
			byte params[4] = { NULL };
			*(int*)&params[0] = siteId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadRegionLabels(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.LoadRegionLabels");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPreferredRegion(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.SetPreferredRegion");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRegion(ScriptString* regionName, int Id, bool bCustomOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.AddRegion");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = regionName;
			*(int*)&params[12] = Id;
			*(bool*)&params[16] = bCustomOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSetting(ScriptName regionName, int Id)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRegionSettings.AddSetting");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = regionName;
			*(int*)&params[8] = Id;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
