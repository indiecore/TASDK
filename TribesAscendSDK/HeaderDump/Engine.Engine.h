#pragma once
#include "Engine.GameViewportClient.h"
#include "Core.Subsystem.h"
#include "Engine.ApexDestructibleDamageParameters.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Font.h"
#include "Engine.Texture2D.h"
#include "Core.Object.h"
#include "Engine.Material.h"
#include "Engine.Client.h"
#include "Engine.TranslationContext.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.Texture.h"
#include "Engine.PostProcessChain.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.StaticMesh.h"
#include "Engine.AudioDevice.h"
#include "Engine.WorldInfo.h"
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
	class Engine : public Subsystem
	{
	public:
		enum ETransitionType : byte
		{
			TT_None = 0,
			TT_Paused = 1,
			TT_Loading = 2,
			TT_Saving = 3,
			TT_Connecting = 4,
			TT_Precaching = 5,
			TT_MAX = 6,
		};
		struct DropNoteInfo
		{
		public:
			ADD_STRUCT(ScriptString*, Comment, 24)
			ADD_STRUCT(Rotator, Rotation, 12)
			ADD_STRUCT(Vector, Location, 0)
		};
		struct StatColorMapEntry
		{
		public:
			ADD_STRUCT(Object::Color, Out, 4)
			ADD_STRUCT(float, In, 0)
		};
		struct StatColorMapping
		{
		public:
			ADD_STRUCT(ScriptArray<Engine::StatColorMapEntry>, ColorMap, 12)
			ADD_BOOL(DisableBlend, 24, 0x1)
			ADD_STRUCT(ScriptString*, StatName, 0)
		};
		ADD_STRUCT(ScriptArray<class LocalPlayer*>, GamePlayers, 1152)
		ADD_STRUCT(ScriptArray<class Font*>, AdditionalFonts, 144)
		ADD_STRUCT(ScriptArray<ScriptString*>, AdditionalFontNames, 156)
		ADD_STRUCT(ScriptArray<Object::Color>, LightComplexityColors, 692)
		ADD_STRUCT(ScriptArray<Object::LinearColor>, ShaderComplexityColors, 704)
		ADD_STRUCT(ScriptArray<Engine::StatColorMapping>, StatColorMappings, 784)
		ADD_STRUCT(ScriptArray<ScriptString*>, DeferredCommands, 1168)
		ADD_STRUCT(ScriptArray<Engine::DropNoteInfo>, PendingDroppedNotes, 1360)
		ADD_STRUCT(ScriptArray<ScriptName>, IgnoreSimulatedFuncWarnings, 1460)
		ADD_OBJECT(TranslationContext, GlobalTranslationContext, 1480)
		ADD_STRUCT(Object::Pointer, ScreenSaverInhibitor, 1476)
		ADD_STRUCT(int, ScreenSaverInhibitorSemaphore, 1472)
		ADD_STRUCT(Object::LinearColor, UnselectedMaterialColor, 1444)
		ADD_STRUCT(Object::LinearColor, SelectedMaterialColor, 1428)
		ADD_STRUCT(Object::LinearColor, DefaultHoveredMaterialColor, 1412)
		ADD_STRUCT(Object::LinearColor, DefaultSelectedMaterialColor, 1396)
		ADD_STRUCT(float, TrackedOcclusionStepSize, 1392)
		ADD_STRUCT(float, MaxTrackedOcclusionIncrement, 1388)
		ADD_STRUCT(float, NetClientTicksPerSecond, 1384)
		ADD_STRUCT(ScriptString*, DynamicCoverMeshComponentName, 1372)
		ADD_STRUCT(int, BeginUPTryCount, 1356)
		ADD_STRUCT(int, MaxParticleSubUVCount, 1352)
		ADD_STRUCT(int, MaxParticleSpriteCount, 1348)
		ADD_STRUCT(int, MaxParticleVertexMemory, 1344)
		ADD_STRUCT(int, MaxParticleResizeWarn, 1340)
		ADD_STRUCT(int, MaxParticleResize, 1336)
		ADD_STRUCT(float, FluidSimulationTimeLimit, 1332)
		ADD_STRUCT(int, MaxFluidNumVerts, 1328)
		ADD_STRUCT(float, MaxOcclusionPixelsFraction, 1324)
		ADD_STRUCT(float, PercentUnoccludedRequeries, 1320)
		ADD_STRUCT(float, PrimitiveProbablyVisibleTime, 1316)
		ADD_STRUCT(float, CameraTranslationThreshold, 1312)
		ADD_STRUCT(float, CameraRotationThreshold, 1308)
		ADD_STRUCT(float, MeshLODRange, 1304)
		ADD_STRUCT(ScriptString*, TransitionGameType, 1292)
		ADD_STRUCT(ScriptString*, TransitionDescription, 1280)
		ADD_STRUCT(Engine::ETransitionType, TransitionType, 1276)
		ADD_STRUCT(ScriptString*, ScoutClassName, 1264)
		ADD_STRUCT(float, StreamingDistanceFactor, 1260)
		ADD_STRUCT(Object::Color, C_BrushShape, 1256)
		ADD_STRUCT(Object::Color, C_Volume, 1252)
		ADD_STRUCT(Object::Color, C_OrthoBackground, 1248)
		ADD_STRUCT(Object::Color, C_BSPCollision, 1244)
		ADD_STRUCT(Object::Color, C_VolumeCollision, 1240)
		ADD_STRUCT(Object::Color, C_ScaleBoxHi, 1236)
		ADD_STRUCT(Object::Color, C_WireBackground, 1232)
		ADD_STRUCT(Object::Color, C_NonSolidWire, 1228)
		ADD_STRUCT(Object::Color, C_SemiSolidWire, 1224)
		ADD_STRUCT(Object::Color, C_SubtractWire, 1220)
		ADD_STRUCT(Object::Color, C_AddWire, 1216)
		ADD_STRUCT(Object::Color, C_BrushWire, 1212)
		ADD_STRUCT(Object::Color, C_WorldBox, 1208)
		ADD_STRUCT(Object::Pointer, MobileMaterialEmulator, 1204)
		ADD_STRUCT(Object::Pointer, RemoteControlExec, 1200)
		ADD_STRUCT(float, MinSmoothedFrameRate, 1196)
		ADD_STRUCT(float, MaxSmoothedFrameRate, 1192)
		ADD_STRUCT(int, ClientCycles, 1188)
		ADD_STRUCT(int, GameCycles, 1184)
		ADD_STRUCT(int, TickCycles, 1180)
		ADD_OBJECT(GameViewportClient, GameViewport, 1164)
		ADD_OBJECT(Client, Client, 1148)
		ADD_STRUCT(float, TimeBetweenPurgingPendingKillObjects, 1144)
		ADD_STRUCT(ScriptString*, DefaultSoundName, 1132)
		ADD_OBJECT(SoundNodeWave, DefaultSound, 1128)
		ADD_STRUCT(ScriptString*, LightMapDensityNormalName, 1116)
		ADD_OBJECT(Texture2D, LightMapDensityNormal, 1112)
		ADD_STRUCT(ScriptString*, LightMapDensityTextureName, 1100)
		ADD_OBJECT(Texture2D, LightMapDensityTexture, 1096)
		ADD_STRUCT(ScriptString*, WeightMapPlaceholderTextureName, 1084)
		ADD_OBJECT(Texture, WeightMapPlaceholderTexture, 1080)
		ADD_STRUCT(ScriptString*, RandomMirrorDiscTextureName, 1068)
		ADD_OBJECT(Texture2D, RandomMirrorDiscTexture, 1064)
		ADD_STRUCT(ScriptString*, RandomNormalTextureName, 1052)
		ADD_OBJECT(Texture2D, RandomNormalTexture, 1048)
		ADD_STRUCT(ScriptString*, RandomAngleTextureName, 1036)
		ADD_OBJECT(Texture2D, RandomAngleTexture, 1032)
		ADD_STRUCT(ScriptString*, ScreenDoorNoiseTextureName, 1020)
		ADD_OBJECT(Texture2D, ScreenDoorNoiseTexture, 1016)
		ADD_STRUCT(ScriptString*, SceneCaptureCubeActorMaterialName, 1004)
		ADD_OBJECT(Material, SceneCaptureCubeActorMaterial, 1000)
		ADD_STRUCT(ScriptString*, SceneCaptureReflectActorMaterialName, 988)
		ADD_OBJECT(Material, SceneCaptureReflectActorMaterial, 984)
		ADD_STRUCT(ScriptString*, DefaultUICaretMaterialName, 972)
		ADD_OBJECT(Material, DefaultUICaretMaterial, 968)
		ADD_STRUCT(ScriptString*, DefaultUIScenePostProcessName, 956)
		ADD_OBJECT(PostProcessChain, DefaultUIScenePostProcess, 952)
		ADD_STRUCT(ScriptString*, ThumbnailMaterialPostProcessName, 940)
		ADD_OBJECT(PostProcessChain, ThumbnailMaterialPostProcess, 936)
		ADD_STRUCT(ScriptString*, ThumbnailParticleSystemPostProcessName, 924)
		ADD_OBJECT(PostProcessChain, ThumbnailParticleSystemPostProcess, 920)
		ADD_STRUCT(ScriptString*, ThumbnailSkeletalMeshPostProcessName, 908)
		ADD_OBJECT(PostProcessChain, ThumbnailSkeletalMeshPostProcess, 904)
		ADD_STRUCT(ScriptString*, DefaultPostProcessName, 892)
		ADD_OBJECT(PostProcessChain, DefaultPostProcess, 888)
		ADD_STRUCT(ScriptString*, DefaultOnlineSubsystemName, 876)
		ADD_OBJECT(ScriptClass, OnlineSubsystemClass, 872)
		ADD_STRUCT(float, TerrainTessellationCheckDistance, 868)
		ADD_STRUCT(int, TerrainTessellationCheckCount, 864)
		ADD_STRUCT(int, TerrainMaterialMaxTextureCount, 860)
		ADD_STRUCT(ScriptString*, TerrainErrorMaterialName, 848)
		ADD_OBJECT(Material, TerrainErrorMaterial, 844)
		ADD_STRUCT(ScriptString*, ApexDamageParamsName, 832)
		ADD_OBJECT(ApexDestructibleDamageParameters, ApexDamageParams, 828)
		ADD_STRUCT(ScriptString*, DefaultPhysMaterialName, 816)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysMaterial, 812)
		ADD_STRUCT(ScriptString*, EditorBrushMaterialName, 800)
		ADD_OBJECT(Material, EditorBrushMaterial, 796)
		ADD_STRUCT(Object::LinearColor, LightMapDensitySelectedColor, 768)
		ADD_STRUCT(Object::LinearColor, LightMapDensityVertexMappedColor, 752)
		ADD_STRUCT(float, RenderLightMapDensityColorScale, 748)
		ADD_STRUCT(float, RenderLightMapDensityGrayscaleScale, 744)
		ADD_STRUCT(float, MaxLightMapDensity, 740)
		ADD_STRUCT(float, IdealLightMapDensity, 736)
		ADD_STRUCT(float, MinLightMapDensity, 732)
		ADD_STRUCT(float, MaxTextureDensity, 728)
		ADD_STRUCT(float, IdealTextureDensity, 724)
		ADD_STRUCT(float, MinTextureDensity, 720)
		ADD_STRUCT(float, MaxPixelShaderAdditiveComplexityCount, 716)
		ADD_STRUCT(Object::LinearColor, LightingOnlyBrightness, 676)
		ADD_STRUCT(int, ImageReflectionTextureSize, 672)
		ADD_STRUCT(float, MaxRMSDForCombiningMappings, 668)
		ADD_BOOL(bDisableAILogging, 664, 0x40000000)
		ADD_BOOL(bCookSeparateSharedMPGameContent, 664, 0x20000000)
		ADD_BOOL(bSuppressMapWarnings, 664, 0x10000000)
		ADD_BOOL(bEnableOnScreenDebugMessagesDisplay, 664, 0x8000000)
		ADD_BOOL(bEnableOnScreenDebugMessages, 664, 0x4000000)
		ADD_BOOL(bEmulateMobileRendering, 664, 0x2000000)
		ADD_BOOL(bHasPendingGlobalReattach, 664, 0x1000000)
		ADD_BOOL(bAreConstraintsDirty, 664, 0x800000)
		ADD_BOOL(bEnableColorClear, 664, 0x400000)
		ADD_BOOL(bCheckParticleRenderSize, 664, 0x200000)
		ADD_BOOL(bPauseOnLossOfFocus, 664, 0x100000)
		ADD_BOOL(bDisablePhysXHardwareSupport, 664, 0x80000)
		ADD_BOOL(bRenderTerrainCollisionAsOverlay, 664, 0x40000)
		ADD_BOOL(bAllowMatureLanguage, 664, 0x20000)
		ADD_BOOL(bEnableKismetLogging, 664, 0x10000)
		ADD_BOOL(bOnScreenKismetWarnings, 664, 0x8000)
		ADD_BOOL(bUsePostProcessEffects, 664, 0x4000)
		ADD_BOOL(bForceCPUSkinning, 664, 0x2000)
		ADD_BOOL(bForceStaticTerrain, 664, 0x1000)
		ADD_BOOL(bShouldGenerateSimpleLightmaps, 664, 0x800)
		ADD_BOOL(HACK_EnableDMC, 664, 0x400)
		ADD_BOOL(HACK_UseTickFrequency, 664, 0x200)
		ADD_BOOL(bSmoothFrameRate, 664, 0x100)
		ADD_BOOL(bSubtitlesForcedOff, 664, 0x80)
		ADD_BOOL(bSubtitlesEnabled, 664, 0x40)
		ADD_BOOL(bUseBackgroundLevelStreaming, 664, 0x20)
		ADD_BOOL(bUseSound, 664, 0x10)
		ADD_BOOL(bRenderLightMapDensityGrayscale, 664, 0x8)
		ADD_BOOL(bCombineSimilarMappings, 664, 0x4)
		ADD_BOOL(ForcePowerOfTwoProcBuildingLODTextures, 664, 0x2)
		ADD_BOOL(UseProcBuildingLODTextureCropping, 664, 0x1)
		ADD_STRUCT(int, MaxProcBuildingLODLightingTextureSize, 660)
		ADD_STRUCT(int, MaxProcBuildingLODColorTextureSize, 656)
		ADD_STRUCT(float, ProcBuildingLODLightingTexelsPerWorldUnit, 652)
		ADD_STRUCT(float, ProcBuildingLODColorTexelsPerWorldUnit, 648)
		ADD_STRUCT(ScriptString*, BuildingQuadStaticMeshName, 636)
		ADD_OBJECT(StaticMesh, BuildingQuadStaticMesh, 632)
		ADD_STRUCT(ScriptString*, ProcBuildingSimpleMaterialName, 620)
		ADD_OBJECT(Material, ProcBuildingSimpleMaterial, 616)
		ADD_STRUCT(ScriptString*, TangentColorMaterialName, 604)
		ADD_OBJECT(Material, TangentColorMaterial, 600)
		ADD_STRUCT(ScriptString*, BoneWeightMaterialName, 588)
		ADD_OBJECT(Material, BoneWeightMaterial, 584)
		ADD_STRUCT(ScriptString*, HeatmapMaterialName, 572)
		ADD_OBJECT(Material, HeatmapMaterial, 568)
		ADD_STRUCT(ScriptString*, VertexColorViewModeMaterialName_BlueOnly, 556)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_BlueOnly, 552)
		ADD_STRUCT(ScriptString*, VertexColorViewModeMaterialName_GreenOnly, 540)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_GreenOnly, 536)
		ADD_STRUCT(ScriptString*, VertexColorViewModeMaterialName_RedOnly, 524)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_RedOnly, 520)
		ADD_STRUCT(ScriptString*, VertexColorViewModeMaterialName_AlphaAsColor, 508)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_AlphaAsColor, 504)
		ADD_STRUCT(ScriptString*, VertexColorViewModeMaterialName_ColorOnly, 492)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_ColorOnly, 488)
		ADD_STRUCT(ScriptString*, VertexColorMaterialName, 476)
		ADD_OBJECT(Material, VertexColorMaterial, 472)
		ADD_STRUCT(ScriptString*, RemoveSurfaceMaterialName, 460)
		ADD_OBJECT(Material, RemoveSurfaceMaterial, 456)
		ADD_STRUCT(ScriptString*, ShadedLevelColorationUnlitMaterialName, 444)
		ADD_OBJECT(Material, ShadedLevelColorationUnlitMaterial, 440)
		ADD_STRUCT(ScriptString*, ShadedLevelColorationLitMaterialName, 428)
		ADD_OBJECT(Material, ShadedLevelColorationLitMaterial, 424)
		ADD_STRUCT(ScriptString*, LightingTexelDensityName, 412)
		ADD_OBJECT(Material, LightingTexelDensityMaterial, 408)
		ADD_STRUCT(ScriptString*, LevelColorationUnlitMaterialName, 396)
		ADD_OBJECT(Material, LevelColorationUnlitMaterial, 392)
		ADD_STRUCT(ScriptString*, LevelColorationLitMaterialName, 380)
		ADD_OBJECT(Material, LevelColorationLitMaterial, 376)
		ADD_STRUCT(ScriptString*, CrossMaterialName, 364)
		ADD_OBJECT(Material, CrossMaterial, 360)
		ADD_STRUCT(ScriptString*, TickMaterialName, 348)
		ADD_OBJECT(Material, TickMaterial, 344)
		ADD_STRUCT(ScriptString*, DefaultFogVolumeMaterialName, 332)
		ADD_OBJECT(Material, DefaultFogVolumeMaterial, 328)
		ADD_STRUCT(ScriptString*, GeomMaterialName, 316)
		ADD_OBJECT(Material, GeomMaterial, 312)
		ADD_STRUCT(ScriptString*, EmissiveTexturedMaterialName, 300)
		ADD_OBJECT(Material, EmissiveTexturedMaterial, 296)
		ADD_STRUCT(ScriptString*, WireframeMaterialName, 284)
		ADD_OBJECT(Material, WireframeMaterial, 280)
		ADD_STRUCT(ScriptString*, DefaultTextureName, 268)
		ADD_OBJECT(Texture, DefaultTexture, 264)
		ADD_STRUCT(ScriptString*, DefaultDecalMaterialName, 252)
		ADD_OBJECT(Material, DefaultDecalMaterial, 248)
		ADD_STRUCT(ScriptString*, DefaultMaterialName, 236)
		ADD_OBJECT(Material, DefaultMaterial, 232)
		ADD_STRUCT(ScriptString*, LocalPlayerClassName, 220)
		ADD_OBJECT(ScriptClass, LocalPlayerClass, 216)
		ADD_STRUCT(ScriptString*, DataStoreClientClassName, 204)
		ADD_OBJECT(ScriptClass, DataStoreClientClass, 200)
		ADD_STRUCT(ScriptString*, GameViewportClientClassName, 188)
		ADD_OBJECT(ScriptClass, GameViewportClientClass, 184)
		ADD_STRUCT(ScriptString*, ConsoleClassName, 172)
		ADD_OBJECT(ScriptClass, ConsoleClass, 168)
		ADD_STRUCT(ScriptString*, SubtitleFontName, 132)
		ADD_OBJECT(Font, SubtitleFont, 128)
		ADD_STRUCT(ScriptString*, LargeFontName, 116)
		ADD_OBJECT(Font, LargeFont, 112)
		ADD_STRUCT(ScriptString*, MediumFontName, 100)
		ADD_OBJECT(Font, MediumFont, 96)
		ADD_STRUCT(ScriptString*, SmallFontName, 84)
		ADD_OBJECT(Font, SmallFont, 80)
		ADD_STRUCT(ScriptString*, TinyFontName, 68)
		ADD_OBJECT(Font, TinyFont, 64)
		bool IsGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7287);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsEditor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7300);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class Font* GetSmallFont()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9330);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)params;
		}
		class AudioDevice* GetAudioDevice()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9508);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AudioDevice**)params;
		}
		bool IsSplitScreen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12288);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class Font* GetTinyFont()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13765);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)params;
		}
		class Font* GetMediumFont()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13867);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)params;
		}
		class Font* GetLargeFont()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13869);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)params;
		}
		class WorldInfo* GetCurrentWorldInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15534);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class WorldInfo**)params;
		}
		ScriptString* GetBuildDate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15536);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		class Font* GetSubtitleFont()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15538);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)params;
		}
		class Font* GetAdditionalFont(int AdditionalFontIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15540);
			byte params[8] = { NULL };
			*(int*)params = AdditionalFontIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)&params[4];
		}
		ScriptString* GetLastMovieName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15543);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool PlayLoadMapMovie()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15545);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void StopMovie(bool bDelayStopUntilGameHasRendered)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15547);
			byte params[4] = { NULL };
			*(bool*)params = bDelayStopUntilGameHasRendered;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveAllOverlays()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15549);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddOverlay(class Font* Font, ScriptString* Text, float X, float Y, float ScaleX, float ScaleY, bool bIsCentered)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15550);
			byte params[36] = { NULL };
			*(class Font**)params = Font;
			*(ScriptString**)&params[4] = Text;
			*(float*)&params[16] = X;
			*(float*)&params[20] = Y;
			*(float*)&params[24] = ScaleX;
			*(float*)&params[28] = ScaleY;
			*(bool*)&params[32] = bIsCentered;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddOverlayWrapped(class Font* Font, ScriptString* Text, float X, float Y, float ScaleX, float ScaleY, float WrapWidth)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15558);
			byte params[36] = { NULL };
			*(class Font**)params = Font;
			*(ScriptString**)&params[4] = Text;
			*(float*)&params[16] = X;
			*(float*)&params[20] = Y;
			*(float*)&params[24] = ScaleX;
			*(float*)&params[28] = ScaleY;
			*(float*)&params[32] = WrapWidth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Engine* GetEngine()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15566);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Engine**)params;
		}
		class PostProcessChain* GetWorldPostProcessChain()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15568);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PostProcessChain**)params;
		}
		void AddTextureStreamingSlaveLoc(Vector InLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15570);
			byte params[12] = { NULL };
			*(Vector*)params = InLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BasicSaveObject(class Object* Obj, ScriptString* PathName, bool bIsSaveGame, int Version)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15572);
			byte params[28] = { NULL };
			*(class Object**)params = Obj;
			*(ScriptString**)&params[4] = PathName;
			*(bool*)&params[16] = bIsSaveGame;
			*(int*)&params[20] = Version;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool BasicLoadObject(class Object* Obj, ScriptString* PathName, bool bIsSaveGame, int Version)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15578);
			byte params[28] = { NULL };
			*(class Object**)params = Obj;
			*(ScriptString**)&params[4] = PathName;
			*(bool*)&params[16] = bIsSaveGame;
			*(int*)&params[20] = Version;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
