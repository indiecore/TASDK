#pragma once
#include "Engine.MaterialInstanceConstant.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.Canvas.h"
#include "TribesGame.TrCollisionProxy.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PlayerController.h"
#include "Engine.HUD.h"
#include "TribesGame.TrPawn.h"
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
	class TrFlagBase : public UTCarriedObject
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, MICArray, 776)
		ADD_STRUCT(float, m_fRageRadius, 928)
		ADD_STRUCT(float, m_fDamageMomentumDampingWhileFalling, 924)
		ADD_STRUCT(int, m_nDropFlagPingThreshold, 920)
		ADD_STRUCT(float, m_fTeammatePassMaxDistanceSq, 916)
		ADD_STRUCT(int, m_nNumBounces, 912)
		ADD_STRUCT(int, m_nNumBouncesBeforeSlide, 908)
		ADD_STRUCT(float, m_fIgnoreSameTeamTouch, 904)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC, 900)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxyLevel3, 896)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxyLevel2, 892)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxyLevel1, 888)
		ADD_STRUCT(float, m_fBounceDampingPercent, 884)
		ADD_STRUCT(float, m_fForwardThrowVelocity, 880)
		ADD_STRUCT(float, m_fInheritVelocityPct, 876)
		ADD_STRUCT(int, m_TimeAwaySeconds, 872)
		ADD_STRUCT(Object::Vector, LastCameraPos, 860)
		ADD_STRUCT(Object::Vector, LastCameraDir, 848)
		ADD_STRUCT(Object::Vector, LastScreenLoc, 836)
		ADD_STRUCT(float, m_FlagIconAlpha, 832)
		ADD_STRUCT(float, m_fFriction, 828)
		ADD_STRUCT(float, m_fMass, 824)
		ADD_STRUCT(float, LastLocationPingTime, 820)
		ADD_STRUCT(Object::Vector, HoverboardingClothVelClamp, 800)
		ADD_STRUCT(Object::Vector, RunningClothVelClamp, 788)
		ADD_BOOL(m_bPassToTeammatesEnabled, 772, 0x80)
		ADD_BOOL(m_bBounceSlideEnabled, 772, 0x40)
		ADD_BOOL(bWasFlagReturned, 772, 0x20)
		ADD_BOOL(bWasClothEnabled, 772, 0x10)
		ADD_BOOL(bRespawning, 772, 0x8)
		ADD_BOOL(bFadingOut, 772, 0x4)
		ADD_BOOL(bBringDownFromBright, 772, 0x2)
		ADD_BOOL(bBringUpBright, 772, 0x1)
		ADD_OBJECT(ParticleSystem, RespawnEffect, 768)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnBaseChainChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.OnBaseChainChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldMinimapRenderFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ShouldMinimapRenderFor");
			byte params[8] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ClientReturnedHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.SetHolder");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ValidHolder(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.ValidHolder");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SameTeamTouch(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.SameTeamTouch");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.EncroachedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Drop(class Controller* Killer, bool bNoThrow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.Drop");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(bool*)&params[4] = bNoThrow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetSpectatorDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.GetSpectatorDescription");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void OnCollisionProxyTouched(class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagBase.OnCollisionProxyTouched");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
