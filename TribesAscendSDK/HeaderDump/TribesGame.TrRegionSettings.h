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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54608);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptString* LoadRegionSetting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54701);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetRegionName(int siteId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58570);
			byte params[16] = { NULL };
			*(int*)params = siteId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int GetRegionIdAtIndex(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60425);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetRegionIndexByName(ScriptString* regionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(60435);
			byte params[16] = { NULL };
			*(ScriptString**)params = regionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void LoadRegions()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110496);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPreferredSiteId(int siteId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110497);
			byte params[4] = { NULL };
			*(int*)params = siteId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadRegionLabels(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110499);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPreferredRegion(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110509);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRegion(ScriptString* regionName, int Id, bool bCustomOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110511);
			byte params[20] = { NULL };
			*(ScriptString**)params = regionName;
			*(int*)&params[12] = Id;
			*(bool*)&params[16] = bCustomOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSetting(ScriptName regionName, int Id)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110517);
			byte params[12] = { NULL };
			*(ScriptName*)params = regionName;
			*(int*)&params[8] = Id;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
