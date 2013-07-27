#pragma once
#include "GFxUI.GFxObject.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "Engine.WorldInfo.h"
#include "TribesGame.GfxTrHud.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrReticules : public GFxObject
	{
	public:
		ADD_STRUCT(int, m_nCurrentReticuleIndex, 160)
		ADD_BOOL(m_bVisible, 156, 0x1)
		ADD_STRUCT(float, LastReticuleDepth, 152)
		ADD_STRUCT(float, LastHitEnemyTime, 148)
		ADD_STRUCT(float, LastAccuracy, 144)
		ADD_STRUCT(int, LastCrossMode, 140)
		ADD_OBJECT(Weapon, LastWeapon, 136)
		ADD_OBJECT(GFxObject, ActiveReticule, 132)
		ADD_OBJECT(GFxObject, ReticulesMC, 128)
		ADD_OBJECT(WorldInfo, ThisWorld, 124)
		ADD_OBJECT(GfxTrHud, HUD, 120)
		void CallShowReticule(int nIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallShowReticule");
			byte params[4] = { NULL };
			*(int*)&params[0] = nIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallSetReticuleColor(int nType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallSetReticuleColor");
			byte params[4] = { NULL };
			*(int*)&params[0] = nType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_SetCustomReticule(class GFxObject* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.ASC_SetCustomReticule");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallSetReticuleDepth(float fDepth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallSetReticuleDepth");
			byte params[4] = { NULL };
			*(float*)&params[0] = fDepth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeReticule(int nIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.ChangeReticule");
			byte params[4] = { NULL };
			*(int*)&params[0] = nIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetCustomReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetCustomReticule");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetCurrentReticuleIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.GetCurrentReticuleIndex");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void CallSetAccuracy(int nAccuracy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallSetAccuracy");
			byte params[4] = { NULL };
			*(int*)&params[0] = nAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallShowHit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallShowHit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableVehicleAmmoClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.DisableVehicleAmmoClip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableVehicleAmmoClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.EnableVehicleAmmoClip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVehicleAmmoClip(ScriptString* AmmoCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetVehicleAmmoClip");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = AmmoCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetPowerupPercentage");
			byte params[4] = { NULL };
			*(int*)&params[0] = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLaserPowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetLaserPowerupPercentage");
			byte params[4] = { NULL };
			*(int*)&params[0] = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVehiclePowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetVehiclePowerupPercentage");
			byte params[4] = { NULL };
			*(int*)&params[0] = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetGenericPowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetGenericPowerupPercentage");
			byte params[4] = { NULL };
			*(int*)&params[0] = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Init(class GfxTrHud* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.Init");
			byte params[4] = { NULL };
			*(class GfxTrHud**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetReticuleVisible(bool bNewVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetReticuleVisible");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateReticule(class Pawn* pPawn, bool bForceUpdate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.UpdateReticule");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = pPawn;
			*(bool*)&params[4] = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
