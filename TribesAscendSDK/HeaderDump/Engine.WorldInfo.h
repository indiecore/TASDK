#pragma once
#include "Engine.ZoneInfo.h"
#include "Engine.ClipPadEntry.h"
#include "Engine.GameInfo.h"
#include "Engine.EmitterPool.h"
#include "Engine.MusicTrackDataStructures.h"
#include "Engine.LevelStreaming.h"
#include "Engine.GameReplicationInfo.h"
#include "Engine.Actor.h"
#include "Engine.MassiveLODOverrideVolume.h"
#include "Core.Object.h"
#include "Engine.FractureManager.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.DecalManager.h"
#include "Engine.CoverLink.h"
#include "Engine.ParticleEventManager.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.PostProcessChain.h"
#include "Engine.EnvironmentVolume.h"
#include "Engine.ReverbVolume.h"
#include "Engine.PortalVolume.h"
#include "Engine.BookMark.h"
#include "Engine.KismetBookMark.h"
#include "Engine.Texture2D.h"
#include "Engine.EngineTypes.h"
#include "Engine.CrowdPopulationManagerBase.h"
#include "Engine.NavigationPoint.h"
#include "Engine.DefaultPhysicsVolume.h"
#include "Engine.Controller.h"
#include "Engine.Pawn.h"
#include "Engine.Pylon.h"
#include "Engine.ObjectReferencer.h"
#include "Engine.MapInfo.h"
#include "Engine.ProcBuildingRuleset.h"
#include "Engine.PhysicsLODVerticalEmitter.h"
#include "Engine.LightmassLevelSettings.h"
#include "Engine.SeqAct_Latent.h"
#include "Engine.Sequence.h"
#include "Engine.Scene.h"
#include "Engine.NavigationHandle.h"
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Engine.ReachSpec.h"
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
	class WorldInfo : public ZoneInfo
	{
	public:
		static const auto MAX_INSTANCES_PER_CLASS = 5;
		enum EHostMigrationProgress : byte
		{
			HostMigration_None = 0,
			HostMigration_FindingNewHost = 1,
			HostMigration_MigratingAsHost = 2,
			HostMigration_MigratingAsClient = 3,
			HostMigration_HostReadyToTravel = 4,
			HostMigration_MAX = 5,
		};
		enum EConsoleType : byte
		{
			CONSOLE_Any = 0,
			CONSOLE_Xbox360 = 1,
			CONSOLE_PS3 = 2,
			CONSOLE_Mobile = 3,
			CONSOLE_IPhone = 4,
			CONSOLE_Android = 5,
			CONSOLE_MAX = 6,
		};
		enum EVisibilityAggressiveness : byte
		{
			VIS_LeastAggressive = 0,
			VIS_ModeratelyAggressive = 1,
			VIS_MostAggressive = 2,
			VIS_Max = 3,
		};
		enum ENetMode : byte
		{
			NM_Standalone = 0,
			NM_DedicatedServer = 1,
			NM_ListenServer = 2,
			NM_Client = 3,
			NM_MAX = 4,
		};
		class NavMeshPathGoalEvaluatorCacheDatum
		{
		public:
			ADD_STRUCT(int, ListIdx, 0)
			ADD_OBJECT(NavMeshPathGoalEvaluator, List, 4)
		};
		class WorldFractureSettings
		{
		public:
			ADD_STRUCT(float, ChanceOfPhysicsChunkOverride, 0)
			ADD_BOOL(bEnableChanceOfPhysicsChunkOverride, 4, 0x1)
			ADD_BOOL(bLimitExplosionChunkSize, 4, 0x2)
			ADD_STRUCT(float, MaxExplosionChunkSize, 8)
			ADD_BOOL(bLimitDamageChunkSize, 12, 0x1)
			ADD_STRUCT(float, MaxDamageChunkSize, 16)
			ADD_STRUCT(int, MaxNumFacturedChunksToSpawnInAFrame, 20)
			ADD_STRUCT(float, FractureExplosionVelScale, 24)
		};
		class NavMeshPathConstraintCacheDatum
		{
		public:
			ADD_STRUCT(int, ListIdx, 0)
			ADD_OBJECT(NavMeshPathConstraint, List, 4)
		};
		class LightmassWorldInfoSettings
		{
		public:
			ADD_STRUCT(float, StaticLightingLevelScale, 0)
			ADD_STRUCT(int, NumIndirectLightingBounces, 4)
			ADD_STRUCT(Object::Color, EnvironmentColor, 8)
			ADD_STRUCT(float, EnvironmentIntensity, 12)
			ADD_STRUCT(float, EmissiveBoost, 16)
			ADD_STRUCT(float, DiffuseBoost, 20)
			ADD_STRUCT(float, SpecularBoost, 24)
			ADD_STRUCT(float, IndirectNormalInfluenceBoost, 28)
			ADD_BOOL(bUseNormalMapsForSimpleLightMaps, 32, 0x1)
			ADD_BOOL(bUseAmbientOcclusion, 32, 0x2)
			ADD_BOOL(bEnableImageReflectionShadowing, 32, 0x4)
			ADD_STRUCT(float, DirectIlluminationOcclusionFraction, 36)
			ADD_STRUCT(float, IndirectIlluminationOcclusionFraction, 40)
			ADD_STRUCT(float, OcclusionExponent, 44)
			ADD_STRUCT(float, FullyOccludedSamplesFraction, 48)
			ADD_STRUCT(float, MaxOcclusionDistance, 52)
			ADD_BOOL(bVisualizeMaterialDiffuse, 56, 0x1)
			ADD_BOOL(bVisualizeAmbientOcclusion, 56, 0x2)
		};
		class ScreenMessageString
		{
		public:
			ADD_STRUCT(Object::QWord, Key, 0)
			ADD_STRUCT(ScriptString*, ScreenMessage, 8)
			ADD_STRUCT(Object::Color, DisplayColor, 20)
			ADD_STRUCT(float, TimeToDisplay, 24)
			ADD_STRUCT(float, CurrentTimeDisplayed, 28)
		};
		class PhysXEmitterVerticalProperties
		{
		public:
			ADD_BOOL(bDisableLod, 0, 0x1)
			ADD_STRUCT(int, ParticlesLodMin, 4)
			ADD_STRUCT(int, ParticlesLodMax, 8)
			ADD_STRUCT(int, PacketsPerPhysXParticleSystemMax, 12)
			ADD_BOOL(bApplyCylindricalPacketCulling, 16, 0x1)
			ADD_STRUCT(float, SpawnLodVsFifoBias, 20)
		};
		class ApexModuleDestructibleSettings
		{
		public:
			ADD_STRUCT(int, MaxChunkIslandCount, 0)
			ADD_STRUCT(int, MaxRrbActorCount, 4)
			ADD_STRUCT(float, MaxChunkSeparationLOD, 8)
			ADD_BOOL(bOverrideMaxChunkSeparationLOD, 12, 0x1)
		};
		class PhysXSimulationProperties
		{
		public:
			ADD_BOOL(bUseHardware, 0, 0x1)
			ADD_BOOL(bFixedTimeStep, 0, 0x2)
			ADD_STRUCT(float, TimeStep, 4)
			ADD_STRUCT(int, MaxSubSteps, 8)
		};
		class CompartmentRunList
		{
		public:
			ADD_BOOL(RigidBody, 0, 0x1)
			ADD_BOOL(Fluid, 0, 0x2)
			ADD_BOOL(Cloth, 0, 0x4)
			ADD_BOOL(SoftBody, 0, 0x8)
		};
		class NetViewer
		{
		public:
			ADD_OBJECT(PlayerController, InViewer, 0)
			ADD_OBJECT(Actor, Viewer, 4)
			ADD_STRUCT(Object::Vector, ViewLocation, 8)
			ADD_STRUCT(Object::Vector, ViewDir, 20)
		};
		class HostMigrationState
		{
		public:
			ADD_BOOL(bHostMigrationEnabled, 24, 0x1)
			ADD_STRUCT(ScriptString*, HostMigrationTravelURL, 12)
			ADD_STRUCT(float, HostMigrationTravelCountdown, 8)
			ADD_STRUCT(float, HostMigrationElapsedTime, 4)
			ADD_STRUCT(WorldInfo::EHostMigrationProgress, HostMigrationProgress, 0)
		};
		class PhysXVerticalProperties
		{
		public:
			ADD_STRUCT(WorldInfo::PhysXEmitterVerticalProperties, Emitters, 0)
		};
		class PhysXSceneProperties
		{
		public:
			ADD_STRUCT(WorldInfo::PhysXSimulationProperties, PrimaryScene, 0)
			ADD_STRUCT(WorldInfo::PhysXSimulationProperties, CompartmentRigidBody, 12)
			ADD_STRUCT(WorldInfo::PhysXSimulationProperties, CompartmentFluid, 24)
			ADD_STRUCT(WorldInfo::PhysXSimulationProperties, CompartmentCloth, 36)
			ADD_STRUCT(WorldInfo::PhysXSimulationProperties, CompartmentSoftBody, 48)
		};
		ADD_STRUCT(WorldInfo::ENetMode, NetMode, 1048)
		ADD_OBJECT(GameInfo, Game, 1088)
		ADD_STRUCT(float, TimeSeconds, 960)
		ADD_OBJECT(GameReplicationInfo, GRI, 1044)
		ADD_STRUCT(Object::Vector, DefaultColorScale, 1168)
		ADD_OBJECT(EmitterPool, MyEmitterPool, 1348)
		ADD_STRUCT(float, TimeDilation, 952)
		ADD_OBJECT(PlayerReplicationInfo, Pauser, 984)
		ADD_STRUCT(float, MoveRepSize, 1132)
		ADD_BOOL(bPlayersOnly, 716, 0x200)
		ADD_STRUCT(float, StallZ, 1092)
		ADD_BOOL(bRequestedBlockOnAsyncLoading, 716, 0x80)
		ADD_STRUCT(ScriptArray<class LevelStreaming*>, StreamingLevels, 840)
		ADD_STRUCT(float, PauseDelay, 976)
		ADD_STRUCT(float, WorldGravityZ, 1096)
		ADD_BOOL(bPlayersOnlyPending, 716, 0x400)
		ADD_STRUCT(float, DemoPlayTimeDilation, 956)
		ADD_STRUCT(MusicTrackDataStructures::MusicTrackStruct, ReplicatedMusicTrack, 1272)
		ADD_STRUCT(Actor::ETravelType, NextTravelType, 1049)
		ADD_STRUCT(ScriptString*, NextURL, 1148)
		ADD_STRUCT(float, NextSwitchCountdown, 1160)
		ADD_STRUCT(ScriptString*, EmitterPoolClassPath, 1336)
		ADD_STRUCT(ScriptString*, DecalManagerClassPath, 1352)
		ADD_OBJECT(DecalManager, MyDecalManager, 1364)
		ADD_STRUCT(ScriptString*, FractureManagerClassPath, 1368)
		ADD_OBJECT(FractureManager, MyFractureManager, 1380)
		ADD_STRUCT(ScriptString*, ParticleEventManagerClassPath, 1384)
		ADD_OBJECT(ParticleEventManager, MyParticleEventManager, 1396)
		ADD_BOOL(bUseConsoleInput, 716, 0x20000)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, DefaultPostProcessSettings, 492)
		ADD_OBJECT(PostProcessChain, WorldPostProcessChain, 712)
		ADD_BOOL(bPersistPostProcessToNextLevel, 716, 0x1)
		ADD_BOOL(bFogEnabled, 716, 0x2)
		ADD_BOOL(bBumpOffsetEnabled, 716, 0x4)
		ADD_BOOL(bMapNeedsLightingFullyRebuilt, 716, 0x8)
		ADD_BOOL(bMapHasDLEsOutsideOfImportanceVolume, 716, 0x10)
		ADD_BOOL(bMapHasMultipleDominantLightsAffectingOnePrimitive, 716, 0x20)
		ADD_BOOL(bMapHasPathingErrors, 716, 0x40)
		ADD_BOOL(bBegunPlay, 716, 0x100)
		ADD_BOOL(bDropDetail, 716, 0x800)
		ADD_BOOL(bAggressiveLOD, 716, 0x1000)
		ADD_BOOL(bStartup, 716, 0x2000)
		ADD_BOOL(bPathsRebuilt, 716, 0x4000)
		ADD_BOOL(bHasPathNodes, 716, 0x8000)
		ADD_BOOL(bIsMenuLevel, 716, 0x10000)
		ADD_BOOL(bNoDefaultInventoryForPlayer, 716, 0x40000)
		ADD_BOOL(bNoPathWarnings, 716, 0x80000)
		ADD_BOOL(bHighPriorityLoading, 716, 0x100000)
		ADD_BOOL(bHighPriorityLoadingLocal, 716, 0x200000)
		ADD_BOOL(bUseProcBuildingRulesetOverride, 716, 0x400000)
		ADD_BOOL(bSupportDoubleBufferedPhysics, 716, 0x800000)
		ADD_BOOL(bEnableChanceOfPhysicsChunkOverride, 716, 0x1000000)
		ADD_BOOL(bLimitExplosionChunkSize, 716, 0x2000000)
		ADD_BOOL(bLimitDamageChunkSize, 716, 0x4000000)
		ADD_BOOL(bPrecomputeVisibility, 716, 0x8000000)
		ADD_BOOL(bPlaceCellsOnSurfaces, 716, 0x10000000)
		ADD_BOOL(bAllowLightEnvSphericalHarmonicLights, 716, 0x20000000)
		ADD_BOOL(bAllowModulateBetterShadows, 716, 0x40000000)
		ADD_BOOL(bIncreaseFogNearPrecision, 716, 0x80000000)
		ADD_BOOL(bUseGlobalIllumination, 720, 0x1)
		ADD_BOOL(bForceNoPrecomputedLighting, 720, 0x2)
		ADD_BOOL(bSimpleLightmapsStoredInLinearSpace, 720, 0x4)
		ADD_BOOL(bHaveActiveCrowd, 720, 0x8)
		ADD_BOOL(bAllowHostMigration, 720, 0x10)
		ADD_STRUCT(float, SquintModeKernelSize, 724)
		ADD_OBJECT(PostProcessVolume, HighestPriorityPostProcessVolume, 728)
		ADD_STRUCT(ReverbVolume::ReverbSettings, DefaultReverbSettings, 732)
		ADD_STRUCT(ReverbVolume::InteriorSettings, DefaultAmbientZoneSettings, 748)
		ADD_STRUCT(float, FogStart, 784)
		ADD_STRUCT(float, FogEnd, 788)
		ADD_STRUCT(Object::Color, FogColor, 792)
		ADD_STRUCT(float, BumpEnd, 796)
		ADD_OBJECT(ReverbVolume, HighestPriorityReverbVolume, 800)
		ADD_STRUCT(ScriptArray<class MassiveLODOverrideVolume*>, MassiveLODOverrideVolumes, 804)
		ADD_STRUCT(ScriptArray<class PortalVolume*>, PortalVolumes, 816)
		ADD_STRUCT(ScriptArray<class EnvironmentVolume*>, EnvironmentVolumes, 828)
		ADD_STRUCT(Object::Double, LastTimeUnbuiltLightingWasEncountered, 852)
		ADD_OBJECT(BookMark, BookMarks, 860)
		ADD_OBJECT(KismetBookMark, KismetBookMarks, 900)
		ADD_STRUCT(ScriptArray<class ClipPadEntry*>, ClipPadEntries, 940)
		ADD_STRUCT(float, RealTimeSeconds, 964)
		ADD_STRUCT(float, AudioTimeSeconds, 968)
		ADD_STRUCT(float, DeltaSeconds, 972)
		ADD_STRUCT(float, RealTimeToUnPause, 980)
		ADD_STRUCT(ScriptString*, VisibleGroups, 988)
		ADD_STRUCT(ScriptString*, SelectedGroups, 1000)
		ADD_OBJECT(Texture2D, DefaultTexture, 1012)
		ADD_OBJECT(Texture2D, WireframeTexture, 1016)
		ADD_OBJECT(Texture2D, WhiteSquareTexture, 1020)
		ADD_OBJECT(Texture2D, LargeVertex, 1024)
		ADD_OBJECT(Texture2D, BSPVertex, 1028)
		ADD_STRUCT(ScriptArray<ScriptString*>, DeferredExecs, 1032)
		ADD_STRUCT(WorldInfo::EVisibilityAggressiveness, VisibilityAggressiveness, 1050)
		ADD_STRUCT(EngineTypes::ELightingBuildQuality, LevelLightingQuality, 1051)
		ADD_STRUCT(ScriptString*, ComputerName, 1052)
		ADD_STRUCT(ScriptString*, EngineVersion, 1064)
		ADD_STRUCT(ScriptString*, MinNetVersion, 1076)
		ADD_STRUCT(float, DefaultGravityZ, 1100)
		ADD_STRUCT(float, GlobalGravityZ, 1104)
		ADD_STRUCT(float, RBPhysicsGravityScaling, 1108)
		ADD_OBJECT(NavigationPoint, NavigationPointList, 1112)
		ADD_OBJECT(Controller, ControllerList, 1116)
		ADD_OBJECT(Pawn, PawnList, 1120)
		ADD_OBJECT(CoverLink, CoverList, 1124)
		ADD_OBJECT(Pylon, PylonList, 1128)
		ADD_STRUCT(ScriptArray<WorldInfo::NetViewer>, ReplicationViewers, 1136)
		ADD_STRUCT(int, PackedLightAndShadowMapTextureSize, 1164)
		ADD_STRUCT(ScriptArray<ScriptClass*>, GameTypesSupportedOnThisMap, 1180)
		ADD_OBJECT(ScriptClass, GameTypeForPIE, 1192)
		ADD_STRUCT(ScriptArray<class Object*>, ClientDestroyedActorContent, 1196)
		ADD_STRUCT(ScriptArray<ScriptName>, PreparingLevelNames, 1208)
		ADD_STRUCT(ScriptName, CommittedPersistentLevelName, 1220)
		ADD_OBJECT(ObjectReferencer, PersistentMapForcedObjects, 1228)
		ADD_STRUCT(MusicTrackDataStructures::MusicTrackStruct, CurrentMusicTrack, 1236)
		ADD_STRUCT(ScriptString*, Title, 1308)
		ADD_STRUCT(ScriptString*, Author, 1320)
		ADD_OBJECT(MapInfo, MyMapInfo, 1332)
		ADD_OBJECT(ProcBuildingRuleset, ProcBuildingRulesetOverride, 1400)
		ADD_STRUCT(float, MaxPhysicsDeltaTime, 1404)
		ADD_STRUCT(int, MaxPhysicsSubsteps, 1408)
		ADD_STRUCT(WorldInfo::PhysXSceneProperties, PhysicsProperties, 1412)
		ADD_STRUCT(ScriptArray<WorldInfo::CompartmentRunList>, CompartmentRunFrames, 1472)
		ADD_STRUCT(float, DefaultSkinWidth, 1484)
		ADD_STRUCT(float, ApexLODResourceBudget, 1488)
		ADD_STRUCT(WorldInfo::ApexModuleDestructibleSettings, DestructibleSettings, 1492)
		ADD_OBJECT(PhysicsLODVerticalEmitter, EmitterVertical, 1508)
		ADD_STRUCT(WorldInfo::PhysXVerticalProperties, VerticalProperties, 1512)
		ADD_STRUCT(float, ChanceOfPhysicsChunkOverride, 1536)
		ADD_STRUCT(float, MaxExplosionChunkSize, 1540)
		ADD_STRUCT(float, MaxDamageChunkSize, 1544)
		ADD_STRUCT(float, FractureExplosionVelScale, 1548)
		ADD_STRUCT(int, MaxNumFacturedChunksToSpawnInAFrame, 1552)
		ADD_STRUCT(int, NumFacturedChunksSpawnedThisFrame, 1556)
		ADD_STRUCT(float, FracturedMeshWeaponDamage, 1560)
		ADD_STRUCT(int, VisibilityCellSize, 1564)
		ADD_STRUCT(float, CharacterLitIndirectBrightness, 1568)
		ADD_STRUCT(float, CharacterLitIndirectContrastFactor, 1572)
		ADD_STRUCT(float, CharacterShadowedIndirectBrightness, 1576)
		ADD_STRUCT(float, CharacterShadowedIndirectContrastFactor, 1580)
		ADD_STRUCT(float, CharacterLightingContrastFactor, 1584)
		ADD_OBJECT(Texture2D, ImageReflectionEnvironmentTexture, 1588)
		ADD_STRUCT(Object::LinearColor, ImageReflectionEnvironmentColor, 1592)
		ADD_STRUCT(float, ImageReflectionEnvironmentRotation, 1608)
		ADD_STRUCT(Object::Map_Mirror, ScreenMessages, 1612)
		ADD_STRUCT(ScriptArray<WorldInfo::ScreenMessageString>, PriorityScreenMessages, 1672)
		ADD_STRUCT(int, MaxTrianglesPerLeaf, 1684)
		ADD_OBJECT(LightmassLevelSettings, LMLevelSettings, 1688)
		ADD_STRUCT(WorldInfo::LightmassWorldInfoSettings, LightmassSettings, 1692)
		ADD_OBJECT(CrowdPopulationManagerBase, PopulationManager, 1872)
		ADD_STRUCT(ScriptArray<class SeqAct_Latent*>, CrowdSpawnerActions, 1876)
		ADD_STRUCT(WorldInfo::HostMigrationState, PeerHostMigration, 1888)
		ADD_STRUCT(float, HostMigrationTimeout, 1916)
		class Sequence* GetGameSequence()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetGameSequence");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Sequence**)&params[0];
		}
		void AllControllers(ScriptClass* BaseClass, class Controller*& C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AllControllers");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			C = *(class Controller**)&params[4];
		}
		bool IsConsoleBuild(WorldInfo::EConsoleType ConsoleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsConsoleBuild");
			byte params[5] = { NULL };
			*(WorldInfo::EConsoleType*)&params[0] = ConsoleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class WorldInfo* GetWorldInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetWorldInfo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class WorldInfo**)&params[0];
		}
		ScriptString* GetMapName(bool bIncludePrefix)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetMapName");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bIncludePrefix;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptClass* GetGameClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetGameClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		void AllNavigationPoints(ScriptClass* BaseClass, class NavigationPoint*& N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AllNavigationPoints");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class NavigationPoint**)&params[4] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			N = *(class NavigationPoint**)&params[4];
		}
		void ForceGarbageCollection(bool bFullPurge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ForceGarbageCollection");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bFullPurge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPreparingMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPreparingMapChange");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PrepareMapChange(ScriptArray<ScriptName>& LevelNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.PrepareMapChange");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptName>*)&params[0] = LevelNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LevelNames = *(ScriptArray<ScriptName>*)&params[0];
		}
		void CommitMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.CommitMapChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CancelPendingMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.CancelPendingMapChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseCachedConstraintsAndEvaluators()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ReleaseCachedConstraintsAndEvaluators");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class NavMeshPathConstraint* GetNavMeshPathConstraintFromCache(ScriptClass* ConstraintClass, class NavigationHandle* Requestor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetNavMeshPathConstraintFromCache");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = ConstraintClass;
			*(class NavigationHandle**)&params[4] = Requestor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathConstraint**)&params[8];
		}
		class NavMeshPathGoalEvaluator* GetNavMeshPathGoalEvaluatorFromCache(ScriptClass* GoalEvalClass, class NavigationHandle* Requestor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetNavMeshPathGoalEvaluatorFromCache");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = GoalEvalClass;
			*(class NavigationHandle**)&params[4] = Requestor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathGoalEvaluator**)&params[8];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateMusicTrack(MusicTrackDataStructures::MusicTrackStruct NewMusicTrack)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.UpdateMusicTrack");
			byte params[36] = { NULL };
			*(MusicTrackDataStructures::MusicTrackStruct*)&params[0] = NewMusicTrack;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddOnScreenDebugMessage(int Key, float TimeToDisplay, Object::Color DisplayColor, ScriptString* DebugMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AddOnScreenDebugMessage");
			byte params[24] = { NULL };
			*(int*)&params[0] = Key;
			*(float*)&params[4] = TimeToDisplay;
			*(Object::Color*)&params[8] = DisplayColor;
			*(ScriptString**)&params[12] = DebugMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMenuLevel(ScriptString* MapName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsMenuLevel");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = MapName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		float GetGravityZ()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetGravityZ");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		ScriptArray<class Sequence*> GetAllRootSequences()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetAllRootSequences");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class Sequence*>*)&params[0];
		}
		void SetLevelRBGravity(Object::Vector NewGrav)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SetLevelRBGravity");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewGrav;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLocalURL()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetLocalURL");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool IsDemoBuild()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsDemoBuild");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsPlayInEditor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPlayInEditor");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsPlayInPreview()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPlayInPreview");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void VerifyNavList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.VerifyNavList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetAddressURL()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetAddressURL");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void ServerTravel(ScriptString* URL, bool bAbsolute, bool bShouldSkipGameNotify)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ServerTravel");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = URL;
			*(bool*)&params[12] = bAbsolute;
			*(bool*)&params[16] = bShouldSkipGameNotify;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInSeamlessTravel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsInSeamlessTravel");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ThisIsNeverExecuted(class DefaultPhysicsVolume* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ThisIsNeverExecuted");
			byte params[4] = { NULL };
			*(class DefaultPhysicsVolume**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RadiusNavigationPoints(ScriptClass* BaseClass, class NavigationPoint*& N, Object::Vector Point, float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.RadiusNavigationPoints");
			byte params[24] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class NavigationPoint**)&params[4] = N;
			*(Object::Vector*)&params[8] = Point;
			*(float*)&params[20] = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			N = *(class NavigationPoint**)&params[4];
		}
		void NavigationPointCheck(Object::Vector Point, Object::Vector Extent, ScriptArray<class NavigationPoint*>& Navs, ScriptArray<class ReachSpec*>& Specs)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.NavigationPointCheck");
			byte params[48] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(Object::Vector*)&params[12] = Extent;
			*(ScriptArray<class NavigationPoint*>*)&params[24] = Navs;
			*(ScriptArray<class ReachSpec*>*)&params[36] = Specs;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Navs = *(ScriptArray<class NavigationPoint*>*)&params[24];
			Specs = *(ScriptArray<class ReachSpec*>*)&params[36];
		}
		void AllPawns(ScriptClass* BaseClass, class Pawn*& P, Object::Vector TestLocation, float TestRadius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AllPawns");
			byte params[24] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Pawn**)&params[4] = P;
			*(Object::Vector*)&params[8] = TestLocation;
			*(float*)&params[20] = TestRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			P = *(class Pawn**)&params[4];
		}
		void NotifyMatchStarted(bool bShouldActivateLevelStartupEvents, bool bShouldActivateLevelBeginningEvents, bool bShouldActivateLevelLoadedEvents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.NotifyMatchStarted");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bShouldActivateLevelStartupEvents;
			*(bool*)&params[4] = bShouldActivateLevelBeginningEvents;
			*(bool*)&params[8] = bShouldActivateLevelLoadedEvents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMapChangeReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsMapChangeReady");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SeamlessTravel(ScriptString* URL, bool bAbsolute, Object::Guid MapPackageGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SeamlessTravel");
			byte params[32] = { NULL };
			*(ScriptString**)&params[0] = URL;
			*(bool*)&params[12] = bAbsolute;
			*(Object::Guid*)&params[16] = MapPackageGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSeamlessTravelMidpointPause(bool bNowPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SetSeamlessTravelMidpointPause");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MapInfo* GetMapInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetMapInfo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MapInfo**)&params[0];
		}
		void SetMapInfo(class MapInfo* NewMapInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SetMapInfo");
			byte params[4] = { NULL };
			*(class MapInfo**)&params[0] = NewMapInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Scene::EDetailMode GetDetailMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetDetailMode");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Scene::EDetailMode*)&params[0];
		}
		bool IsRecordingDemo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsRecordingDemo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsPlayingDemo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPlayingDemo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void GetDemoFrameInfo(int& CurrentFrame, int& TotalFrames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetDemoFrameInfo");
			byte params[8] = { NULL };
			*(int*)&params[0] = CurrentFrame;
			*(int*)&params[4] = TotalFrames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CurrentFrame = *(int*)&params[0];
			TotalFrames = *(int*)&params[4];
		}
		bool GetDemoRewindPoints(ScriptArray<int>& OutRewindPoints)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetDemoRewindPoints");
			byte params[16] = { NULL };
			*(ScriptArray<int>*)&params[0] = OutRewindPoints;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutRewindPoints = *(ScriptArray<int>*)&params[0];
			return *(bool*)&params[12];
		}
		void DoMemoryTracking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.DoMemoryTracking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		WorldInfo::WorldFractureSettings GetWorldFractureSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetWorldFractureSettings");
			byte params[28] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(WorldInfo::WorldFractureSettings*)&params[0];
		}
		class EnvironmentVolume* FindEnvironmentVolume(Object::Vector TestLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.FindEnvironmentVolume");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = TestLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class EnvironmentVolume**)&params[12];
		}
		bool BeginHostMigration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.BeginHostMigration");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ToggleHostMigration(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ToggleHostMigration");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPhysicsPools()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ClearPhysicsPools");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
