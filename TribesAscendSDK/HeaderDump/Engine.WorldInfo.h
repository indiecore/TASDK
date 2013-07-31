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
		struct NavMeshPathGoalEvaluatorCacheDatum
		{
		public:
			ADD_STRUCT(int, ListIdx, 0)
			ADD_OBJECT(NavMeshPathGoalEvaluator, List, 4)
		};
		struct WorldFractureSettings
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
		struct NavMeshPathConstraintCacheDatum
		{
		public:
			ADD_STRUCT(int, ListIdx, 0)
			ADD_OBJECT(NavMeshPathConstraint, List, 4)
		};
		struct LightmassWorldInfoSettings
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
		struct ScreenMessageString
		{
		public:
			ADD_STRUCT(QWord, Key, 0)
			ADD_STRUCT(ScriptString*, ScreenMessage, 8)
			ADD_STRUCT(Object::Color, DisplayColor, 20)
			ADD_STRUCT(float, TimeToDisplay, 24)
			ADD_STRUCT(float, CurrentTimeDisplayed, 28)
		};
		struct PhysXEmitterVerticalProperties
		{
		public:
			ADD_BOOL(bDisableLod, 0, 0x1)
			ADD_STRUCT(int, ParticlesLodMin, 4)
			ADD_STRUCT(int, ParticlesLodMax, 8)
			ADD_STRUCT(int, PacketsPerPhysXParticleSystemMax, 12)
			ADD_BOOL(bApplyCylindricalPacketCulling, 16, 0x1)
			ADD_STRUCT(float, SpawnLodVsFifoBias, 20)
		};
		struct ApexModuleDestructibleSettings
		{
		public:
			ADD_STRUCT(int, MaxChunkIslandCount, 0)
			ADD_STRUCT(int, MaxRrbActorCount, 4)
			ADD_STRUCT(float, MaxChunkSeparationLOD, 8)
			ADD_BOOL(bOverrideMaxChunkSeparationLOD, 12, 0x1)
		};
		struct PhysXSimulationProperties
		{
		public:
			ADD_BOOL(bUseHardware, 0, 0x1)
			ADD_BOOL(bFixedTimeStep, 0, 0x2)
			ADD_STRUCT(float, TimeStep, 4)
			ADD_STRUCT(int, MaxSubSteps, 8)
		};
		struct CompartmentRunList
		{
		public:
			ADD_BOOL(RigidBody, 0, 0x1)
			ADD_BOOL(Fluid, 0, 0x2)
			ADD_BOOL(Cloth, 0, 0x4)
			ADD_BOOL(SoftBody, 0, 0x8)
		};
		struct NetViewer
		{
		public:
			ADD_OBJECT(PlayerController, InViewer, 0)
			ADD_OBJECT(Actor, Viewer, 4)
			ADD_STRUCT(Vector, ViewLocation, 8)
			ADD_STRUCT(Vector, ViewDir, 20)
		};
		struct HostMigrationState
		{
		public:
			ADD_BOOL(bHostMigrationEnabled, 24, 0x1)
			ADD_STRUCT(ScriptString*, HostMigrationTravelURL, 12)
			ADD_STRUCT(float, HostMigrationTravelCountdown, 8)
			ADD_STRUCT(float, HostMigrationElapsedTime, 4)
			ADD_STRUCT(WorldInfo::EHostMigrationProgress, HostMigrationProgress, 0)
		};
		struct PhysXVerticalProperties
		{
		public:
			ADD_STRUCT(WorldInfo::PhysXEmitterVerticalProperties, Emitters, 0)
		};
		struct PhysXSceneProperties
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
		ADD_STRUCT(Vector, DefaultColorScale, 1168)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4289);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Sequence**)params;
		}
		void AllControllers(ScriptClass* BaseClass, class Controller*& C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5715);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			C = *(class Controller**)&params[4];
		}
		bool IsConsoleBuild(WorldInfo::EConsoleType ConsoleType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5728);
			byte params[5] = { NULL };
			*(WorldInfo::EConsoleType*)params = ConsoleType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class WorldInfo* GetWorldInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7283);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class WorldInfo**)params;
		}
		ScriptString* GetMapName(bool bIncludePrefix)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7713);
			byte params[16] = { NULL };
			*(bool*)params = bIncludePrefix;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptClass* GetGameClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7715);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		void AllNavigationPoints(ScriptClass* BaseClass, class NavigationPoint*& N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8413);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class NavigationPoint**)&params[4] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			N = *(class NavigationPoint**)&params[4];
		}
		void ForceGarbageCollection(bool bFullPurge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9153);
			byte params[4] = { NULL };
			*(bool*)params = bFullPurge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPreparingMapChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9175);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PrepareMapChange(ScriptArray<ScriptName>& LevelNames)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9177);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptName>*)params = LevelNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LevelNames = *(ScriptArray<ScriptName>*)params;
		}
		void CommitMapChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9179);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CancelPendingMapChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9181);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseCachedConstraintsAndEvaluators()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16085);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class NavMeshPathConstraint* GetNavMeshPathConstraintFromCache(ScriptClass* ConstraintClass, class NavigationHandle* Requestor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16086);
			byte params[12] = { NULL };
			*(ScriptClass**)params = ConstraintClass;
			*(class NavigationHandle**)&params[4] = Requestor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathConstraint**)&params[8];
		}
		class NavMeshPathGoalEvaluator* GetNavMeshPathGoalEvaluatorFromCache(ScriptClass* GoalEvalClass, class NavigationHandle* Requestor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16090);
			byte params[12] = { NULL };
			*(ScriptClass**)params = GoalEvalClass;
			*(class NavigationHandle**)&params[4] = Requestor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathGoalEvaluator**)&params[8];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16094);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateMusicTrack(MusicTrackDataStructures::MusicTrackStruct NewMusicTrack)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16096);
			byte params[36] = { NULL };
			*(MusicTrackDataStructures::MusicTrackStruct*)params = NewMusicTrack;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddOnScreenDebugMessage(int Key, float TimeToDisplay, Object::Color DisplayColor, ScriptString* DebugMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16098);
			byte params[24] = { NULL };
			*(int*)params = Key;
			*(float*)&params[4] = TimeToDisplay;
			*(Object::Color*)&params[8] = DisplayColor;
			*(ScriptString**)&params[12] = DebugMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMenuLevel(ScriptString* MapName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16103);
			byte params[16] = { NULL };
			*(ScriptString**)params = MapName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		float GetGravityZ()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16116);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		ScriptArray<class Sequence*> GetAllRootSequences()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16118);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class Sequence*>*)params;
		}
		void SetLevelRBGravity(Vector NewGrav)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16121);
			byte params[12] = { NULL };
			*(Vector*)params = NewGrav;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLocalURL()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16123);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool IsDemoBuild()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16125);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsPlayInEditor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16130);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsPlayInPreview()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16132);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void VerifyNavList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16135);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetAddressURL()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16136);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ServerTravel(ScriptString* URL, bool bAbsolute, bool bShouldSkipGameNotify)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16138);
			byte params[20] = { NULL };
			*(ScriptString**)params = URL;
			*(bool*)&params[12] = bAbsolute;
			*(bool*)&params[16] = bShouldSkipGameNotify;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInSeamlessTravel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16145);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ThisIsNeverExecuted(class DefaultPhysicsVolume* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16147);
			byte params[4] = { NULL };
			*(class DefaultPhysicsVolume**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16149);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16161);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16163);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RadiusNavigationPoints(ScriptClass* BaseClass, class NavigationPoint*& N, Vector Point, float Radius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16166);
			byte params[24] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class NavigationPoint**)&params[4] = N;
			*(Vector*)&params[8] = Point;
			*(float*)&params[20] = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			N = *(class NavigationPoint**)&params[4];
		}
		void NavigationPointCheck(Vector Point, Vector Extent, ScriptArray<class NavigationPoint*>& Navs, ScriptArray<class ReachSpec*>& Specs)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16171);
			byte params[48] = { NULL };
			*(Vector*)params = Point;
			*(Vector*)&params[12] = Extent;
			*(ScriptArray<class NavigationPoint*>*)&params[24] = Navs;
			*(ScriptArray<class ReachSpec*>*)&params[36] = Specs;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Navs = *(ScriptArray<class NavigationPoint*>*)&params[24];
			Specs = *(ScriptArray<class ReachSpec*>*)&params[36];
		}
		void AllPawns(ScriptClass* BaseClass, class Pawn*& P, Vector TestLocation, float TestRadius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16180);
			byte params[24] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Pawn**)&params[4] = P;
			*(Vector*)&params[8] = TestLocation;
			*(float*)&params[20] = TestRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			P = *(class Pawn**)&params[4];
		}
		void NotifyMatchStarted(bool bShouldActivateLevelStartupEvents, bool bShouldActivateLevelBeginningEvents, bool bShouldActivateLevelLoadedEvents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16185);
			byte params[12] = { NULL };
			*(bool*)params = bShouldActivateLevelStartupEvents;
			*(bool*)&params[4] = bShouldActivateLevelBeginningEvents;
			*(bool*)&params[8] = bShouldActivateLevelLoadedEvents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMapChangeReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16191);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SeamlessTravel(ScriptString* URL, bool bAbsolute, Object::Guid MapPackageGuid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16193);
			byte params[32] = { NULL };
			*(ScriptString**)params = URL;
			*(bool*)&params[12] = bAbsolute;
			*(Object::Guid*)&params[16] = MapPackageGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSeamlessTravelMidpointPause(bool bNowPaused)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16198);
			byte params[4] = { NULL };
			*(bool*)params = bNowPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MapInfo* GetMapInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16200);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MapInfo**)params;
		}
		void SetMapInfo(class MapInfo* NewMapInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16202);
			byte params[4] = { NULL };
			*(class MapInfo**)params = NewMapInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Scene::EDetailMode GetDetailMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16205);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Scene::EDetailMode*)params;
		}
		bool IsRecordingDemo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16207);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsPlayingDemo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16209);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void GetDemoFrameInfo(int& CurrentFrame, int& TotalFrames)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16211);
			byte params[8] = { NULL };
			*(int*)params = CurrentFrame;
			*(int*)&params[4] = TotalFrames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CurrentFrame = *(int*)params;
			TotalFrames = *(int*)&params[4];
		}
		bool GetDemoRewindPoints(ScriptArray<int>& OutRewindPoints)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16214);
			byte params[16] = { NULL };
			*(ScriptArray<int>*)params = OutRewindPoints;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutRewindPoints = *(ScriptArray<int>*)params;
			return *(bool*)&params[12];
		}
		void DoMemoryTracking()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16218);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		WorldInfo::WorldFractureSettings GetWorldFractureSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16219);
			byte params[28] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(WorldInfo::WorldFractureSettings*)params;
		}
		class EnvironmentVolume* FindEnvironmentVolume(Vector TestLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16230);
			byte params[16] = { NULL };
			*(Vector*)params = TestLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class EnvironmentVolume**)&params[12];
		}
		bool BeginHostMigration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16233);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ToggleHostMigration(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16235);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPhysicsPools()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16237);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
