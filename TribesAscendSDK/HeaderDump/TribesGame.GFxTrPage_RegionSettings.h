#pragma once
#include "TribesGame.GFxTrPage.h"
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_RegionSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_RegionSettings : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bFilter, 0x1)
		ADD_VAR(::BoolProperty, bForceChoose, 0x4)
		ADD_VAR(::BoolProperty, bServer, 0x2)
		ADD_VAR(::IntProperty, CurrFilterIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrFilterSite, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrRegion, 0xFFFFFFFF)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RegionSettings.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RegionSettings.FillData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RegionSettings.TakeAction");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActionIndex;
			*(class GFxObject**)(params + 4) = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_RegionSettings.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
