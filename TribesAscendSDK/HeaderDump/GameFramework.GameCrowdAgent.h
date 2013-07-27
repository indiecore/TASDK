#pragma once
#include "GameFramework.GameCrowdGroup.h"
#include "Engine.CrowdAgentBase.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "GameFramework.GameCrowdForcePoint.h"
#include "Engine.Canvas.h"
#include "GameFramework.GameCrowdAgentBehavior.h"
#include "Engine.SoundCue.h"
#include "Engine.Texture2D.h"
#include "Engine.NavigationHandle.h"
#include "GameFramework.GameCrowdDestination.h"
#include "Engine.HUD.h"
#include "Engine.LightComponent.h"
#include "GameFramework.SeqAct_PlayAgentAnimation.h"
#include "Engine.PlayerController.h"
#include "Engine.Controller.h"
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
	class GameCrowdAgent : public CrowdAgentBase
	{
	public:
		enum EConformType : byte
		{
			CFM_NavMesh = 0,
			CFM_BSP = 1,
			CFM_World = 2,
			CFM_None = 3,
			CFM_MAX = 4,
		};
		struct RecentInteraction
		{
		public:
			ADD_STRUCT(float, InteractionDelay, 8)
			ADD_STRUCT(ScriptName, InteractionTag, 0)
		};
		struct BehaviorEntry
		{
		public:
			ADD_BOOL(bCanBeUsed, 12, 0x4)
			ADD_BOOL(bHasBeenUsed, 12, 0x2)
			ADD_BOOL(bNeverRepeat, 12, 0x1)
			ADD_STRUCT(float, BehaviorFrequency, 8)
			ADD_OBJECT(Actor, LookAtActor, 4)
			ADD_OBJECT(GameCrowdAgentBehavior, BehaviorArchetype, 0)
		};
		ADD_STRUCT(ScriptArray<class Actor*>, NearbyDynamics, 548)
		ADD_STRUCT(ScriptArray<class GameCrowdForcePoint*>, RelevantAttractors, 560)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::RecentInteraction>, RecentInteractions, 764)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, EncounterAgentBehaviors, 824)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, SeePlayerBehaviors, 836)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, SpawnBehaviors, 856)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, PanicBehaviors, 868)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, RandomBehaviors, 880)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, TakeDamageBehaviors, 892)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, GroupWaitingBehaviors, 916)
		ADD_STRUCT(float, InitialLastRenderTime, 960)
		ADD_STRUCT(Vector, SpawnOffset, 948)
		ADD_STRUCT(float, MaxLOSLifeDistanceSq, 936)
		ADD_STRUCT(float, DesiredGroupRadiusSq, 932)
		ADD_STRUCT(float, DesiredGroupRadius, 928)
		ADD_STRUCT(float, ReachThreshold, 912)
		ADD_STRUCT(float, ForceUpdateTime, 908)
		ADD_STRUCT(float, RandomBehaviorInterval, 904)
		ADD_STRUCT(float, SeePlayerInterval, 852)
		ADD_STRUCT(float, MaxSeePlayerDistSq, 848)
		ADD_OBJECT(GameCrowdAgentBehavior, CurrentBehavior, 820)
		ADD_OBJECT(SoundCue, AmbientSoundCue, 812)
		ADD_STRUCT(Object::LinearColor, BeaconColor, 796)
		ADD_OBJECT(Texture2D, BeaconTexture, 792)
		ADD_STRUCT(Vector, BeaconOffset, 780)
		ADD_STRUCT(float, BeaconMaxDist, 776)
		ADD_STRUCT(float, MaxSpeed, 760)
		ADD_STRUCT(float, MaxRunningSpeed, 756)
		ADD_STRUCT(float, MaxWalkingSpeed, 752)
		ADD_OBJECT(GameCrowdAgent, MyArchetype, 748)
		ADD_STRUCT(float, NotVisibleTickScalingFactor, 744)
		ADD_STRUCT(float, NotVisibleLifeSpan, 740)
		ADD_STRUCT(float, LastUpdateTime, 736)
		ADD_STRUCT(float, LastPathingAttempt, 732)
		ADD_STRUCT(float, WalkableFloorZ, 728)
		ADD_STRUCT(int, ObstacleCheckCount, 724)
		ADD_OBJECT(NavigationHandle, NavigationHandle, 720)
		ADD_OBJECT(ScriptClass, NavigationHandleClass, 716)
		ADD_STRUCT(Vector, SearchExtent, 704)
		ADD_STRUCT(Vector, IntermediatePoint, 692)
		ADD_STRUCT(float, GroundOffset, 688)
		ADD_STRUCT(Vector, LastKnownGoodPosition, 676)
		ADD_STRUCT(float, VisibleProximityLODDist, 672)
		ADD_STRUCT(float, ProximityLODDist, 668)
		ADD_STRUCT(float, EyeZOffset, 664)
		ADD_STRUCT(Vector, MeshMaxScale3D, 652)
		ADD_STRUCT(Vector, MeshMinScale3D, 640)
		ADD_STRUCT(float, MaxYawRate, 636)
		ADD_STRUCT(float, RotateToTargetSpeed, 632)
		ADD_STRUCT(float, VelocityDamping, 628)
		ADD_STRUCT(float, FollowPathStrength, 624)
		ADD_STRUCT(float, MatchVelStrength, 620)
		ADD_STRUCT(float, GroupAttractionStrength, 616)
		ADD_STRUCT(float, AvoidOtherRadius, 612)
		ADD_STRUCT(float, AvoidPlayerStrength, 608)
		ADD_STRUCT(float, AvoidOtherStrength, 604)
		ADD_STRUCT(int, AwareUpdateInterval, 600)
		ADD_STRUCT(float, AwareRadius, 596)
		ADD_STRUCT(float, LastGroundZ, 592)
		ADD_STRUCT(int, CurrentConformTraceInterval, 588)
		ADD_STRUCT(int, ConformTraceInterval, 584)
		ADD_STRUCT(float, ConformTraceDist, 580)
		ADD_STRUCT(GameCrowdAgent::EConformType, ConformType, 576)
		ADD_OBJECT(GameCrowdGroup, MyGroup, 480)
		ADD_BOOL(bIsInSpawnPool, 572, 0x8000)
		ADD_BOOL(bHasNotifiedSpawner, 572, 0x4000)
		ADD_BOOL(bPreferVisibleDestinationOnSpawn, 572, 0x2000)
		ADD_BOOL(bPreferVisibleDestination, 572, 0x1000)
		ADD_BOOL(bWantsGroupIdle, 572, 0x800)
		ADD_BOOL(bIsPanicked, 572, 0x400)
		ADD_BOOL(bPotentialEncounter, 572, 0x200)
		ADD_BOOL(bClampMovementSpeed, 572, 0x100)
		ADD_BOOL(bSimulateThisTick, 572, 0x80)
		ADD_BOOL(bBadHitNormal, 572, 0x40)
		ADD_BOOL(bHitObstacle, 572, 0x20)
		ADD_BOOL(bAllowPitching, 572, 0x10)
		ADD_BOOL(bWantsSeePlayerNotification, 572, 0x8)
		ADD_BOOL(bUseNavMeshPathing, 572, 0x4)
		ADD_BOOL(bCheckForObstacles, 572, 0x2)
		ADD_BOOL(bUniformScale, 572, 0x1)
		ADD_STRUCT(int, AwareUpdateFrameCount, 544)
		ADD_STRUCT(int, ConformTraceFrameCount, 540)
		ADD_STRUCT(float, DeadBodyDuration, 532)
		ADD_STRUCT(int, Health, 528)
		ADD_STRUCT(float, InterpZTranslation, 524)
		ADD_STRUCT(Vector, ExternalForce, 512)
		ADD_OBJECT(GameCrowdDestination, PreviousDestination, 508)
		ADD_OBJECT(GameCrowdDestination, BehaviorDestination, 504)
		ADD_OBJECT(GameCrowdDestination, CurrentDestination, 500)
		ADD_STRUCT(float, AvoidanceShare, 496)
		ADD_STRUCT(Vector, PreferredVelocity, 484)
		bool PickBehaviorFrom(ScriptArray<GameCrowdAgent::BehaviorEntry> BehaviorList, Vector BestCameraLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30495);
			byte params[28] = { NULL };
			*(ScriptArray<GameCrowdAgent::BehaviorEntry>*)params = BehaviorList;
			*(Vector*)&params[12] = BestCameraLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30941);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPanicked()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30943);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetPanic(class Actor* PanicActor, bool bNewPanic)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30945);
			byte params[8] = { NULL };
			*(class Actor**)params = PanicActor;
			*(bool*)&params[4] = bNewPanic;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WaitForGroupMembers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30961);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCurrentDestination(class GameCrowdDestination* NewDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30964);
			byte params[4] = { NULL };
			*(class GameCrowdDestination**)params = NewDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMaxSpeed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30966);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30967);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillAgent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30972);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetPooledAgent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30975);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30976);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30977);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void SetLighting(bool bEnableLightEnvironment, LightComponent::LightingChannelContainer AgentLightingChannel, bool bCastShadows)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30983);
			byte params[12] = { NULL };
			*(bool*)params = bEnableLightEnvironment;
			*(LightComponent::LightingChannelContainer*)&params[4] = AgentLightingChannel;
			*(bool*)&params[8] = bCastShadows;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitializeAgent(class Actor* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup, float AgentWarmupTime, bool bWarmupPosition, bool bCheckWarmupVisibility)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30987);
			byte params[24] = { NULL };
			*(class Actor**)params = SpawnLoc;
			*(class GameCrowdAgent**)&params[4] = AgentTemplate;
			*(class GameCrowdGroup**)&params[8] = NewGroup;
			*(float*)&params[12] = AgentWarmupTime;
			*(bool*)&params[16] = bWarmupPosition;
			*(bool*)&params[20] = bCheckWarmupVisibility;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayAgentAnimation(class SeqAct_PlayAgentAnimation* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31012);
			byte params[4] = { NULL };
			*(class SeqAct_PlayAgentAnimation**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayIdleAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31014);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopIdleAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31015);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandlePotentialAgentEncounter()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31016);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlaySpawnBehavior()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31017);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifySeePlayer(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31018);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TryRandomBehavior()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetSeePlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31025);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateBehavior(class GameCrowdAgentBehavior* NewBehaviorArchetype, class Actor* LookAtActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31026);
			byte params[8] = { NULL };
			*(class GameCrowdAgentBehavior**)params = NewBehaviorArchetype;
			*(class Actor**)&params[4] = LookAtActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentBehavior(class GameCrowdAgentBehavior* BehaviorArchetype)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31029);
			byte params[4] = { NULL };
			*(class GameCrowdAgentBehavior**)params = BehaviorArchetype;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActivateInstancedBehavior(class GameCrowdAgentBehavior* NewBehaviorObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31030);
			byte params[4] = { NULL };
			*(class GameCrowdAgentBehavior**)params = NewBehaviorObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31032);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsIdle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31034);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31036);
			byte params[36] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		void UpdateIntermediatePoint(class Actor* DestinationActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31044);
			byte params[4] = { NULL };
			*(class Actor**)params = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDeath(Vector KillMomentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31048);
			byte params[12] = { NULL };
			*(Vector*)params = KillMomentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireDeathEvent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31050);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31051);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OverlappedActorEvent(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31059);
			byte params[4] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitNavigationHandle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31061);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GeneratePathToActor(class Actor* Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31062);
			byte params[24] = { NULL };
			*(class Actor**)params = Goal;
			*(float*)&params[4] = WithinDistance;
			*(bool*)&params[8] = bAllowPartialPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31068);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31073);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDestString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31089);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31092);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
