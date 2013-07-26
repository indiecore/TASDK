#pragma once
#include "GameFramework.GameCrowdDestination.h"
#include "GameFramework.GameCrowdGroup.h"
#include "Engine.CrowdAgentBase.h"
#include "Engine.NavigationHandle.h"
#include "Core.Object.Vector.h"
#include "Engine.Canvas.h"
#include "GameFramework.GameCrowdAgentBehavior.h"
#include "Engine.SoundCue.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Texture2D.h"
#include "Engine.Actor.h"
#include "Engine.HUD.h"
#include "Engine.LightComponent.LightingChannelContainer.h"
#include "GameFramework.SeqAct_PlayAgentAnimation.h"
#include "Engine.PlayerController.h"
#include "Core.Object.Rotator.h"
#include "Engine.Controller.h"
#include "Engine.Actor.TraceHitInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdAgent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameCrowdAgent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdAgent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdAgent : public CrowdAgentBase
	{
	public:
		ADD_VAR(::FloatProperty, InitialLastRenderTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SpawnOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxLOSLifeDistanceSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredGroupRadiusSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredGroupRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReachThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RandomBehaviorInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SeePlayerInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSeePlayerDistSq, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdAgentBehavior, CurrentBehavior)
		ADD_OBJECT(SoundCue, AmbientSoundCue)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, BeaconColor, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, BeaconTexture)
		ADD_STRUCT(::VectorProperty, BeaconOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BeaconMaxDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRunningSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxWalkingSpeed, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdAgent, MyArchetype)
		ADD_VAR(::FloatProperty, NotVisibleTickScalingFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NotVisibleLifeSpan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPathingAttempt, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WalkableFloorZ, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ObstacleCheckCount, 0xFFFFFFFF)
		ADD_OBJECT(NavigationHandle, NavigationHandle)
		ADD_OBJECT(ScriptClass, NavigationHandleClass)
		ADD_STRUCT(::VectorProperty, SearchExtent, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, IntermediatePoint, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroundOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastKnownGoodPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VisibleProximityLODDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProximityLODDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EyeZOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MeshMaxScale3D, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MeshMinScale3D, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxYawRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotateToTargetSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VelocityDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FollowPathStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MatchVelStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroupAttractionStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AvoidOtherRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AvoidPlayerStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AvoidOtherStrength, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AwareUpdateInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwareRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastGroundZ, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentConformTraceInterval, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConformTraceInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConformTraceDist, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ConformType, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdGroup, MyGroup)
		ADD_VAR(::BoolProperty, bIsInSpawnPool, 0x8000)
		ADD_VAR(::BoolProperty, bHasNotifiedSpawner, 0x4000)
		ADD_VAR(::BoolProperty, bPreferVisibleDestinationOnSpawn, 0x2000)
		ADD_VAR(::BoolProperty, bPreferVisibleDestination, 0x1000)
		ADD_VAR(::BoolProperty, bWantsGroupIdle, 0x800)
		ADD_VAR(::BoolProperty, bIsPanicked, 0x400)
		ADD_VAR(::BoolProperty, bPotentialEncounter, 0x200)
		ADD_VAR(::BoolProperty, bClampMovementSpeed, 0x100)
		ADD_VAR(::BoolProperty, bSimulateThisTick, 0x80)
		ADD_VAR(::BoolProperty, bBadHitNormal, 0x40)
		ADD_VAR(::BoolProperty, bHitObstacle, 0x20)
		ADD_VAR(::BoolProperty, bAllowPitching, 0x10)
		ADD_VAR(::BoolProperty, bWantsSeePlayerNotification, 0x8)
		ADD_VAR(::BoolProperty, bUseNavMeshPathing, 0x4)
		ADD_VAR(::BoolProperty, bCheckForObstacles, 0x2)
		ADD_VAR(::BoolProperty, bUniformScale, 0x1)
		ADD_VAR(::IntProperty, AwareUpdateFrameCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConformTraceFrameCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeadBodyDuration, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Health, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InterpZTranslation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ExternalForce, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdDestination, PreviousDestination)
		ADD_OBJECT(GameCrowdDestination, BehaviorDestination)
		ADD_OBJECT(GameCrowdDestination, CurrentDestination)
		ADD_VAR(::FloatProperty, AvoidanceShare, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PreferredVelocity, 0xFFFFFFFF)
		bool PickBehaviorFrom(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* BehaviorList, Vector BestCameraLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.PickBehaviorFrom");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = BehaviorList;
			*(Vector*)(params + 12) = BestCameraLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsPanicked()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.IsPanicked");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetPanic(class Actor* PanicActor, bool bNewPanic)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.SetPanic");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = PanicActor;
			*(bool*)(params + 4) = bNewPanic;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WaitForGroupMembers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.WaitForGroupMembers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCurrentDestination(class GameCrowdDestination* NewDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.SetCurrentDestination");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdDestination**)params = NewDest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMaxSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.SetMaxSpeed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillAgent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.KillAgent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetPooledAgent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.ResetPooledAgent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void SetLighting(bool bEnableLightEnvironment, LightingChannelContainer AgentLightingChannel, bool bCastShadows)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.SetLighting");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bEnableLightEnvironment;
			*(LightingChannelContainer*)(params + 4) = AgentLightingChannel;
			*(bool*)(params + 8) = bCastShadows;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitializeAgent(class Actor* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup, float AgentWarmupTime, bool bWarmupPosition, bool bCheckWarmupVisibility)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.InitializeAgent");
			byte* params = (byte*)malloc(24);
			*(class Actor**)params = SpawnLoc;
			*(class GameCrowdAgent**)(params + 4) = AgentTemplate;
			*(class GameCrowdGroup**)(params + 8) = NewGroup;
			*(float*)(params + 12) = AgentWarmupTime;
			*(bool*)(params + 16) = bWarmupPosition;
			*(bool*)(params + 20) = bCheckWarmupVisibility;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayAgentAnimation(class SeqAct_PlayAgentAnimation* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.OnPlayAgentAnimation");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_PlayAgentAnimation**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayIdleAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.PlayIdleAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopIdleAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.StopIdleAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandlePotentialAgentEncounter()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.HandlePotentialAgentEncounter");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlaySpawnBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.PlaySpawnBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifySeePlayer(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.NotifySeePlayer");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TryRandomBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.TryRandomBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetSeePlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.ResetSeePlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateBehavior(class GameCrowdAgentBehavior* NewBehaviorArchetype, class Actor* LookAtActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.ActivateBehavior");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdAgentBehavior**)params = NewBehaviorArchetype;
			*(class Actor**)(params + 4) = LookAtActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCurrentBehavior(class GameCrowdAgentBehavior* BehaviorArchetype)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.SetCurrentBehavior");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgentBehavior**)params = BehaviorArchetype;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActivateInstancedBehavior(class GameCrowdAgentBehavior* NewBehaviorObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.ActivateInstancedBehavior");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgentBehavior**)params = NewBehaviorObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.IsIdle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.CalcCamera");
			byte* params = (byte*)malloc(36);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void UpdateIntermediatePoint(class Actor* DestinationActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.UpdateIntermediatePoint");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDeath(Vector KillMomentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.PlayDeath");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = KillMomentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireDeathEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.FireDeathEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OverlappedActorEvent(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.OverlappedActorEvent");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitNavigationHandle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.InitNavigationHandle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GeneratePathToActor(class Actor* Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.GeneratePathToActor");
			byte* params = (byte*)malloc(24);
			*(class Actor**)params = Goal;
			*(float*)(params + 4) = WithinDistance;
			*(bool*)(params + 8) = bAllowPartialPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.NativePostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetDestString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.GetDestString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgent.GetBehaviorString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
