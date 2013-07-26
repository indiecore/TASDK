#pragma once
#include "Engine.MaterialInstanceConstant.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.Canvas.h"
#include "TribesGame.TrCollisionProxy.h"
#include "Core.Object.Vector.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PlayerController.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.HUD.h"
#include "TribesGame.TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrFlagBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrFlagBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrFlagBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrFlagBase : public UTCarriedObject
	{
	public:
		ADD_VAR(::FloatProperty, m_fRageRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDamageMomentumDampingWhileFalling, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nDropFlagPingThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTeammatePassMaxDistanceSq, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumBounces, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumBouncesBeforeSlide, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fIgnoreSameTeamTouch, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxyLevel3)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxyLevel2)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxyLevel1)
		ADD_VAR(::FloatProperty, m_fBounceDampingPercent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fForwardThrowVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInheritVelocityPct, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_TimeAwaySeconds, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastCameraPos, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastCameraDir, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastScreenLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_FlagIconAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFriction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMass, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastLocationPingTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HoverboardingClothVelClamp, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RunningClothVelClamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bPassToTeammatesEnabled, 0x80)
		ADD_VAR(::BoolProperty, m_bBounceSlideEnabled, 0x40)
		ADD_VAR(::BoolProperty, bWasFlagReturned, 0x20)
		ADD_VAR(::BoolProperty, bWasClothEnabled, 0x10)
		ADD_VAR(::BoolProperty, bRespawning, 0x8)
		ADD_VAR(::BoolProperty, bFadingOut, 0x4)
		ADD_VAR(::BoolProperty, bBringDownFromBright, 0x2)
		ADD_VAR(::BoolProperty, bBringUpBright, 0x1)
		ADD_OBJECT(ParticleSystem, RespawnEffect)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnBaseChainChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.OnBaseChainChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldMinimapRenderFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ShouldMinimapRenderFor");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ClientReturnedHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.SetHolder");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ValidHolder(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ValidHolder");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SameTeamTouch(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.SameTeamTouch");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CustomRespawnEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.CustomRespawnEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void bringUpBrightOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.bringUpBrightOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CustomFadeOutEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.CustomFadeOutEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.EncroachedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Drop(class Controller* Killer, bool bNoThrow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.Drop");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(bool*)(params + 4) = bNoThrow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlagPropertiesToStationaryFlagState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.SetFlagPropertiesToStationaryFlagState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFlagDynamicLightToNotBeDynamic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.SetFlagDynamicLightToNotBeDynamic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSpectatorDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.GetSpectatorDescription");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void OnCollisionProxyTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.OnCollisionProxyTouched");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = TRP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
