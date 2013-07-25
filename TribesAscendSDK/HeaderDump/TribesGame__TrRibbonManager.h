#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRibbonManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrRibbonManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bDirty, 0x1)
		ADD_VAR(::BoolProperty, bHaveUnlocks, 0x2)
		ADD_VAR(::BoolProperty, bOnlyUnlocks, 0x4)
		ADD_VAR(::BoolProperty, bHaveUpgrades, 0x8)
		ADD_VAR(::BoolProperty, bOnlyUpgrades, 0x10)
		ADD_VAR(::IntProperty, PreviousGold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PreviousXP, 0xFFFFFFFF)
		int GetClassRibbon(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.GetClassRibbon");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetTypeRibbon(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.GetTypeRibbon");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetEquipRibbon(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.GetEquipRibbon");
			byte* params = (byte*)malloc(8);
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void CalculateRibbons(int Gold, int XP, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.CalculateRibbons");
			byte* params = (byte*)malloc(12);
			*(int*)params = Gold;
			*(int*)(params + 4) = XP;
			*(bool*)(params + 8) = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
