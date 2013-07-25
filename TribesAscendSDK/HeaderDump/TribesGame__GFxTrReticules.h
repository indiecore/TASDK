#pragma once
#include "GFxUI__GFxObject.h"
#include "Engine__Weapon.h"
#include "Engine__WorldInfo.h"
#include "TribesGame__GfxTrHud.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrReticules." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrReticules." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrReticules : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, m_nCurrentReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bVisible, 0x1)
		ADD_VAR(::FloatProperty, LastReticuleDepth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAccuracy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastCrossMode, 0xFFFFFFFF)
		ADD_OBJECT(Weapon, LastWeapon)
		ADD_OBJECT(GFxObject, ActiveReticule)
		ADD_OBJECT(GFxObject, ReticulesMC)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GfxTrHud, HUD)
		void CallShowReticule(int nIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallShowReticule");
			byte* params = (byte*)malloc(4);
			*(int*)params = nIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CallSetReticuleColor(int nType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallSetReticuleColor");
			byte* params = (byte*)malloc(4);
			*(int*)params = nType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_SetCustomReticule(class GFxObject* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.ASC_SetCustomReticule");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CallSetReticuleDepth(float fDepth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallSetReticuleDepth");
			byte* params = (byte*)malloc(4);
			*(float*)params = fDepth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeReticule(int nIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.ChangeReticule");
			byte* params = (byte*)malloc(4);
			*(int*)params = nIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetCustomReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetCustomReticule");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetCurrentReticuleIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.GetCurrentReticuleIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void CallSetAccuracy(int nAccuracy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.CallSetAccuracy");
			byte* params = (byte*)malloc(4);
			*(int*)params = nAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void SetVehicleAmmoClip(ScriptArray<wchar_t> AmmoCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetVehicleAmmoClip");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = AmmoCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetPowerupPercentage");
			byte* params = (byte*)malloc(4);
			*(int*)params = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLaserPowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetLaserPowerupPercentage");
			byte* params = (byte*)malloc(4);
			*(int*)params = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVehiclePowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetVehiclePowerupPercentage");
			byte* params = (byte*)malloc(4);
			*(int*)params = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetGenericPowerupPercentage(int pPercentage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetGenericPowerupPercentage");
			byte* params = (byte*)malloc(4);
			*(int*)params = pPercentage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Init(class GfxTrHud* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.Init");
			byte* params = (byte*)malloc(4);
			*(class GfxTrHud**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetReticuleVisible(bool bNewVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.SetReticuleVisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateReticule(class Pawn* pPawn, bool bForceUpdate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrReticules.UpdateReticule");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = pPawn;
			*(bool*)(params + 4) = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
