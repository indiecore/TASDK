#pragma once
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrRibbonManager : public Object
	{
	public:
		class RibbonData
		{
		public:
			ADD_STRUCT(int, Ribbon, 8)
			ADD_STRUCT(int, Type, 4)
			ADD_STRUCT(int, Id, 0)
		};
		ADD_BOOL(bDirty, 68, 0x1)
		ADD_BOOL(bHaveUnlocks, 68, 0x2)
		ADD_BOOL(bOnlyUnlocks, 68, 0x4)
		ADD_BOOL(bHaveUpgrades, 68, 0x8)
		ADD_BOOL(bOnlyUpgrades, 68, 0x10)
		ADD_STRUCT(ScriptArray<TrRibbonManager::RibbonData>, ClassRibbons, 72)
		ADD_STRUCT(ScriptArray<TrRibbonManager::RibbonData>, TypeRibbons, 84)
		ADD_STRUCT(ScriptArray<TrRibbonManager::RibbonData>, EquipRibbons, 96)
		ADD_STRUCT(int, PreviousGold, 64)
		ADD_STRUCT(int, PreviousXP, 60)
		int GetClassRibbon(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.GetClassRibbon");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetTypeRibbon(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.GetTypeRibbon");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetEquipRibbon(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.GetEquipRibbon");
			byte params[8] = { NULL };
			*(int*)&params[0] = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void CalculateRibbons(int Gold, int XP, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRibbonManager.CalculateRibbons");
			byte params[12] = { NULL };
			*(int*)&params[0] = Gold;
			*(int*)&params[4] = XP;
			*(bool*)&params[8] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
