#pragma once
#include "Engine.ZoneInfo.h"
#include "Engine.GameInfo.h"
#include "Engine.EmitterPool.h"
#include "Engine.DecalManager.h"
#include "Core.Object.Color.h"
#include "Engine.GameReplicationInfo.h"
#include "Core.Object.Map_Mirror.h"
#include "Core.Object.Vector.h"
#include "Engine.ReverbVolume.InteriorSettings.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.FractureManager.h"
#include "Engine.MusicTrackDataStructures.MusicTrackStruct.h"
#include "Engine.CoverLink.h"
#include "Engine.ParticleEventManager.h"
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Engine.PostProcessChain.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.ReverbVolume.ReverbSettings.h"
#include "Engine.EnvironmentVolume.h"
#include "Engine.ReverbVolume.h"
#include "Engine.WorldInfo.WorldFractureSettings.h"
#include "Engine.Sequence.h"
#include "Core.Object.Double.h"
#include "Engine.BookMark.h"
#include "Engine.KismetBookMark.h"
#include "Engine.Texture2D.h"
#include "Engine.CrowdPopulationManagerBase.h"
#include "Engine.NavigationPoint.h"
#include "Engine.DefaultPhysicsVolume.h"
#include "Engine.Controller.h"
#include "Engine.WorldInfo.HostMigrationState.h"
#include "Engine.Pawn.h"
#include "Engine.Pylon.h"
#include "Engine.ObjectReferencer.h"
#include "Engine.MapInfo.h"
#include "Engine.ProcBuildingRuleset.h"
#include "Engine.WorldInfo.PhysXSceneProperties.h"
#include "Engine.WorldInfo.ApexModuleDestructibleSettings.h"
#include "Engine.PhysicsLODVerticalEmitter.h"
#include "Engine.WorldInfo.PhysXVerticalProperties.h"
#include "Core.Object.LinearColor.h"
#include "Engine.LightmassLevelSettings.h"
#include "Engine.WorldInfo.LightmassWorldInfoSettings.h"
#include "Engine.NavigationHandle.h"
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Core.Object.Guid.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.WorldInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.WorldInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.WorldInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WorldInfo : public ZoneInfo
	{
	public:
		ADD_VAR(::ByteProperty, NetMode, 0xFFFFFFFF)
		ADD_OBJECT(GameInfo, Game)
		ADD_VAR(::FloatProperty, TimeSeconds, 0xFFFFFFFF)
		ADD_OBJECT(GameReplicationInfo, GRI)
		ADD_STRUCT(::VectorProperty, DefaultColorScale, 0xFFFFFFFF)
		ADD_OBJECT(EmitterPool, MyEmitterPool)
		ADD_VAR(::FloatProperty, TimeDilation, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, Pauser)
		ADD_VAR(::FloatProperty, MoveRepSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPlayersOnly, 0x200)
		ADD_VAR(::FloatProperty, StallZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRequestedBlockOnAsyncLoading, 0x80)
		ADD_VAR(::FloatProperty, PauseDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WorldGravityZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPlayersOnlyPending, 0x400)
		ADD_VAR(::FloatProperty, DemoPlayTimeDilation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<MusicTrackStruct>, ReplicatedMusicTrack, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, NextTravelType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NextURL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NextSwitchCountdown, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EmitterPoolClassPath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DecalManagerClassPath, 0xFFFFFFFF)
		ADD_OBJECT(DecalManager, MyDecalManager)
		ADD_VAR(::StrProperty, FractureManagerClassPath, 0xFFFFFFFF)
		ADD_OBJECT(FractureManager, MyFractureManager)
		ADD_VAR(::StrProperty, ParticleEventManagerClassPath, 0xFFFFFFFF)
		ADD_OBJECT(ParticleEventManager, MyParticleEventManager)
		ADD_VAR(::BoolProperty, bUseConsoleInput, 0x20000)
		ADD_STRUCT(::NonArithmeticProperty<PostProcessSettings>, DefaultPostProcessSettings, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, WorldPostProcessChain)
		ADD_VAR(::BoolProperty, bPersistPostProcessToNextLevel, 0x1)
		ADD_VAR(::BoolProperty, bFogEnabled, 0x2)
		ADD_VAR(::BoolProperty, bBumpOffsetEnabled, 0x4)
		ADD_VAR(::BoolProperty, bMapNeedsLightingFullyRebuilt, 0x8)
		ADD_VAR(::BoolProperty, bMapHasDLEsOutsideOfImportanceVolume, 0x10)
		ADD_VAR(::BoolProperty, bMapHasMultipleDominantLightsAffectingOnePrimitive, 0x20)
		ADD_VAR(::BoolProperty, bMapHasPathingErrors, 0x40)
		ADD_VAR(::BoolProperty, bBegunPlay, 0x100)
		ADD_VAR(::BoolProperty, bDropDetail, 0x800)
		ADD_VAR(::BoolProperty, bAggressiveLOD, 0x1000)
		ADD_VAR(::BoolProperty, bStartup, 0x2000)
		ADD_VAR(::BoolProperty, bPathsRebuilt, 0x4000)
		ADD_VAR(::BoolProperty, bHasPathNodes, 0x8000)
		ADD_VAR(::BoolProperty, bIsMenuLevel, 0x10000)
		ADD_VAR(::BoolProperty, bNoDefaultInventoryForPlayer, 0x40000)
		ADD_VAR(::BoolProperty, bNoPathWarnings, 0x80000)
		ADD_VAR(::BoolProperty, bHighPriorityLoading, 0x100000)
		ADD_VAR(::BoolProperty, bHighPriorityLoadingLocal, 0x200000)
		ADD_VAR(::BoolProperty, bUseProcBuildingRulesetOverride, 0x400000)
		ADD_VAR(::BoolProperty, bSupportDoubleBufferedPhysics, 0x800000)
		ADD_VAR(::BoolProperty, bEnableChanceOfPhysicsChunkOverride, 0x1000000)
		ADD_VAR(::BoolProperty, bLimitExplosionChunkSize, 0x2000000)
		ADD_VAR(::BoolProperty, bLimitDamageChunkSize, 0x4000000)
		ADD_VAR(::BoolProperty, bPrecomputeVisibility, 0x8000000)
		ADD_VAR(::BoolProperty, bPlaceCellsOnSurfaces, 0x10000000)
		ADD_VAR(::BoolProperty, bAllowLightEnvSphericalHarmonicLights, 0x20000000)
		ADD_VAR(::BoolProperty, bAllowModulateBetterShadows, 0x40000000)
		ADD_VAR(::BoolProperty, bIncreaseFogNearPrecision, 0x80000000)
		ADD_VAR(::BoolProperty, bUseGlobalIllumination, 0x1)
		ADD_VAR(::BoolProperty, bForceNoPrecomputedLighting, 0x2)
		ADD_VAR(::BoolProperty, bSimpleLightmapsStoredInLinearSpace, 0x4)
		ADD_VAR(::BoolProperty, bHaveActiveCrowd, 0x8)
		ADD_VAR(::BoolProperty, bAllowHostMigration, 0x10)
		ADD_VAR(::FloatProperty, SquintModeKernelSize, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessVolume, HighestPriorityPostProcessVolume)
		ADD_STRUCT(::NonArithmeticProperty<ReverbSettings>, DefaultReverbSettings, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InteriorSettings>, DefaultAmbientZoneSettings, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FogStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FogEnd, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, FogColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BumpEnd, 0xFFFFFFFF)
		ADD_OBJECT(ReverbVolume, HighestPriorityReverbVolume)
		ADD_STRUCT(::NonArithmeticProperty<Double>, LastTimeUnbuiltLightingWasEncountered, 0xFFFFFFFF)
		ADD_OBJECT(BookMark, BookMarks)
		ADD_OBJECT(KismetBookMark, KismetBookMarks)
		ADD_VAR(::FloatProperty, RealTimeSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AudioTimeSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeltaSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RealTimeToUnPause, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VisibleGroups, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SelectedGroups, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DefaultTexture)
		ADD_OBJECT(Texture2D, WireframeTexture)
		ADD_OBJECT(Texture2D, WhiteSquareTexture)
		ADD_OBJECT(Texture2D, LargeVertex)
		ADD_OBJECT(Texture2D, BSPVertex)
		ADD_VAR(::ByteProperty, VisibilityAggressiveness, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LevelLightingQuality, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ComputerName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EngineVersion, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MinNetVersion, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultGravityZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GlobalGravityZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RBPhysicsGravityScaling, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, NavigationPointList)
		ADD_OBJECT(Controller, ControllerList)
		ADD_OBJECT(Pawn, PawnList)
		ADD_OBJECT(CoverLink, CoverList)
		ADD_OBJECT(Pylon, PylonList)
		ADD_VAR(::IntProperty, PackedLightAndShadowMapTextureSize, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, GameTypeForPIE)
		ADD_VAR(::NameProperty, CommittedPersistentLevelName, 0xFFFFFFFF)
		ADD_OBJECT(ObjectReferencer, PersistentMapForcedObjects)
		ADD_STRUCT(::NonArithmeticProperty<MusicTrackStruct>, CurrentMusicTrack, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Author, 0xFFFFFFFF)
		ADD_OBJECT(MapInfo, MyMapInfo)
		ADD_OBJECT(ProcBuildingRuleset, ProcBuildingRulesetOverride)
		ADD_VAR(::FloatProperty, MaxPhysicsDeltaTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPhysicsSubsteps, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PhysXSceneProperties>, PhysicsProperties, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultSkinWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ApexLODResourceBudget, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ApexModuleDestructibleSettings>, DestructibleSettings, 0xFFFFFFFF)
		ADD_OBJECT(PhysicsLODVerticalEmitter, EmitterVertical)
		ADD_STRUCT(::NonArithmeticProperty<PhysXVerticalProperties>, VerticalProperties, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ChanceOfPhysicsChunkOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxExplosionChunkSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDamageChunkSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FractureExplosionVelScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxNumFacturedChunksToSpawnInAFrame, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumFacturedChunksSpawnedThisFrame, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FracturedMeshWeaponDamage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VisibilityCellSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterLitIndirectBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterLitIndirectContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterShadowedIndirectBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterShadowedIndirectContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharacterLightingContrastFactor, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, ImageReflectionEnvironmentTexture)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ImageReflectionEnvironmentColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImageReflectionEnvironmentRotation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Map_Mirror>, ScreenMessages, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxTrianglesPerLeaf, 0xFFFFFFFF)
		ADD_OBJECT(LightmassLevelSettings, LMLevelSettings)
		ADD_STRUCT(::NonArithmeticProperty<LightmassWorldInfoSettings>, LightmassSettings, 0xFFFFFFFF)
		ADD_OBJECT(CrowdPopulationManagerBase, PopulationManager)
		ADD_STRUCT(::NonArithmeticProperty<HostMigrationState>, PeerHostMigration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HostMigrationTimeout, 0xFFFFFFFF)
		class Sequence* GetGameSequence()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetGameSequence");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Sequence**)params;
			free(params);
			return returnVal;
		}
		void AllControllers(ScriptClass* BaseClass, class Controller*& C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AllControllers");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = BaseClass;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			C = *(class Controller**)(params + 4);
			free(params);
		}
		bool IsConsoleBuild(byte ConsoleType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsConsoleBuild");
			byte* params = (byte*)malloc(5);
			*params = ConsoleType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class WorldInfo* GetWorldInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetWorldInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class WorldInfo**)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetMapName(bool bIncludePrefix)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetMapName");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bIncludePrefix;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetGameClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetGameClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		void AllNavigationPoints(ScriptClass* BaseClass, class NavigationPoint*& N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AllNavigationPoints");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = BaseClass;
			*(class NavigationPoint**)(params + 4) = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			N = *(class NavigationPoint**)(params + 4);
			free(params);
		}
		void ForceGarbageCollection(bool bFullPurge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ForceGarbageCollection");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFullPurge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsPreparingMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPreparingMapChange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PrepareMapChange(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& LevelNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.PrepareMapChange");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = LevelNames;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			LevelNames = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ConstraintClass;
			*(class NavigationHandle**)(params + 4) = Requestor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavMeshPathConstraint**)(params + 8);
			free(params);
			return returnVal;
		}
		class NavMeshPathGoalEvaluator* GetNavMeshPathGoalEvaluatorFromCache(ScriptClass* GoalEvalClass, class NavigationHandle* Requestor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetNavMeshPathGoalEvaluatorFromCache");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = GoalEvalClass;
			*(class NavigationHandle**)(params + 4) = Requestor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavMeshPathGoalEvaluator**)(params + 8);
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateMusicTrack(MusicTrackStruct NewMusicTrack)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.UpdateMusicTrack");
			byte* params = (byte*)malloc(36);
			*(MusicTrackStruct*)params = NewMusicTrack;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddOnScreenDebugMessage(int Key, float TimeToDisplay, Color DisplayColor, ScriptArray<wchar_t> DebugMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AddOnScreenDebugMessage");
			byte* params = (byte*)malloc(24);
			*(int*)params = Key;
			*(float*)(params + 4) = TimeToDisplay;
			*(Color*)(params + 8) = DisplayColor;
			*(ScriptArray<wchar_t>*)(params + 12) = DebugMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsMenuLevel(ScriptArray<wchar_t> MapName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsMenuLevel");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MapName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetGravityZ()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetGravityZ");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetAllRootSequences()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetAllRootSequences");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		void SetLevelRBGravity(Vector NewGrav)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SetLevelRBGravity");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewGrav;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetLocalURL()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetLocalURL");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool IsDemoBuild()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsDemoBuild");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsPlayInEditor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPlayInEditor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsPlayInPreview()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPlayInPreview");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void VerifyNavList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.VerifyNavList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetAddressURL()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetAddressURL");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ServerTravel(ScriptArray<wchar_t> URL, bool bAbsolute, bool bShouldSkipGameNotify)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ServerTravel");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = URL;
			*(bool*)(params + 12) = bAbsolute;
			*(bool*)(params + 16) = bShouldSkipGameNotify;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsInSeamlessTravel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsInSeamlessTravel");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ThisIsNeverExecuted(class DefaultPhysicsVolume* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ThisIsNeverExecuted");
			byte* params = (byte*)malloc(4);
			*(class DefaultPhysicsVolume**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void RadiusNavigationPoints(ScriptClass* BaseClass, class NavigationPoint*& N, Vector Point, float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.RadiusNavigationPoints");
			byte* params = (byte*)malloc(24);
			*(ScriptClass**)params = BaseClass;
			*(class NavigationPoint**)(params + 4) = N;
			*(Vector*)(params + 8) = Point;
			*(float*)(params + 20) = Radius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			N = *(class NavigationPoint**)(params + 4);
			free(params);
		}
		void NavigationPointCheck(Vector Point, Vector Extent, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Navs, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Specs)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.NavigationPointCheck");
			byte* params = (byte*)malloc(48);
			*(Vector*)params = Point;
			*(Vector*)(params + 12) = Extent;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24) = Navs;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 36) = Specs;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Navs = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24);
			Specs = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 36);
			free(params);
		}
		void AllPawns(ScriptClass* BaseClass, class Pawn*& P, Vector TestLocation, float TestRadius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.AllPawns");
			byte* params = (byte*)malloc(24);
			*(ScriptClass**)params = BaseClass;
			*(class Pawn**)(params + 4) = P;
			*(Vector*)(params + 8) = TestLocation;
			*(float*)(params + 20) = TestRadius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			P = *(class Pawn**)(params + 4);
			free(params);
		}
		void NotifyMatchStarted(bool bShouldActivateLevelStartupEvents, bool bShouldActivateLevelBeginningEvents, bool bShouldActivateLevelLoadedEvents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.NotifyMatchStarted");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bShouldActivateLevelStartupEvents;
			*(bool*)(params + 4) = bShouldActivateLevelBeginningEvents;
			*(bool*)(params + 8) = bShouldActivateLevelLoadedEvents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsMapChangeReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsMapChangeReady");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SeamlessTravel(ScriptArray<wchar_t> URL, bool bAbsolute, Guid MapPackageGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SeamlessTravel");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = URL;
			*(bool*)(params + 12) = bAbsolute;
			*(Guid*)(params + 16) = MapPackageGuid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSeamlessTravelMidpointPause(bool bNowPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SetSeamlessTravelMidpointPause");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class MapInfo* GetMapInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetMapInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MapInfo**)params;
			free(params);
			return returnVal;
		}
		void SetMapInfo(class MapInfo* NewMapInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.SetMapInfo");
			byte* params = (byte*)malloc(4);
			*(class MapInfo**)params = NewMapInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetDetailMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetDetailMode");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool IsRecordingDemo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsRecordingDemo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsPlayingDemo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.IsPlayingDemo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void GetDemoFrameInfo(int& CurrentFrame, int& TotalFrames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetDemoFrameInfo");
			byte* params = (byte*)malloc(8);
			*(int*)params = CurrentFrame;
			*(int*)(params + 4) = TotalFrames;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CurrentFrame = *(int*)params;
			TotalFrames = *(int*)(params + 4);
			free(params);
		}
		bool GetDemoRewindPoints(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutRewindPoints)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetDemoRewindPoints");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = OutRewindPoints;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutRewindPoints = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void DoMemoryTracking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.DoMemoryTracking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		WorldFractureSettings GetWorldFractureSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.GetWorldFractureSettings");
			byte* params = (byte*)malloc(28);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(WorldFractureSettings*)params;
			free(params);
			return returnVal;
		}
		class EnvironmentVolume* FindEnvironmentVolume(Vector TestLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.FindEnvironmentVolume");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = TestLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class EnvironmentVolume**)(params + 12);
			free(params);
			return returnVal;
		}
		bool BeginHostMigration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.BeginHostMigration");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ToggleHostMigration(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ToggleHostMigration");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPhysicsPools()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.WorldInfo.ClearPhysicsPools");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
