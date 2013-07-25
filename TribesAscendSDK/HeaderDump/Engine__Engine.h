#pragma once
#include "Engine__PhysicalMaterial.h"
#include "Engine__Material.h"
#include "Engine__GameViewportClient.h"
#include "Core__Subsystem.h"
#include "Engine__TranslationContext.h"
#include "Engine__PostProcessChain.h"
#include "Engine__Client.h"
#include "Engine__SoundNodeWave.h"
#include "Engine__Texture.h"
#include "Engine__Texture2D.h"
#include "Engine__ApexDestructibleDamageParameters.h"
#include "Engine__StaticMesh.h"
#include "Engine__Font.h"
#include "Core__Object.h"
#include "Engine__AudioDevice.h"
#include "Engine__WorldInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Engine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Engine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Engine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Engine : public Subsystem
	{
	public:
		ADD_OBJECT(TranslationContext, GlobalTranslationContext)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ScreenSaverInhibitor'!
		ADD_VAR(::IntProperty, ScreenSaverInhibitorSemaphore, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'UnselectedMaterialColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'SelectedMaterialColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'DefaultHoveredMaterialColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'DefaultSelectedMaterialColor'!
		ADD_VAR(::FloatProperty, TrackedOcclusionStepSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTrackedOcclusionIncrement, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NetClientTicksPerSecond, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DynamicCoverMeshComponentName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BeginUPTryCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxParticleSubUVCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxParticleSpriteCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxParticleVertexMemory, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxParticleResizeWarn, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxParticleResize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidSimulationTimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxFluidNumVerts, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxOcclusionPixelsFraction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PercentUnoccludedRequeries, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PrimitiveProbablyVisibleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraTranslationThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraRotationThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MeshLODRange, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TransitionGameType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TransitionDescription, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TransitionType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScoutClassName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StreamingDistanceFactor, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_BrushShape'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_Volume'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_OrthoBackground'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_BSPCollision'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_VolumeCollision'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_ScaleBoxHi'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_WireBackground'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_NonSolidWire'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_SemiSolidWire'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_SubtractWire'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_AddWire'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_BrushWire'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'C_WorldBox'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'MobileMaterialEmulator'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RemoteControlExec'!
		ADD_VAR(::FloatProperty, MinSmoothedFrameRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSmoothedFrameRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClientCycles, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GameCycles, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TickCycles, 0xFFFFFFFF)
		ADD_OBJECT(GameViewportClient, GameViewport)
		ADD_OBJECT(Client, Client)
		ADD_VAR(::FloatProperty, TimeBetweenPurgingPendingKillObjects, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultSoundName, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, DefaultSound)
		ADD_VAR(::StrProperty, LightMapDensityNormalName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, LightMapDensityNormal)
		ADD_VAR(::StrProperty, LightMapDensityTextureName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, LightMapDensityTexture)
		ADD_VAR(::StrProperty, WeightMapPlaceholderTextureName, 0xFFFFFFFF)
		ADD_OBJECT(Texture, WeightMapPlaceholderTexture)
		ADD_VAR(::StrProperty, RandomMirrorDiscTextureName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, RandomMirrorDiscTexture)
		ADD_VAR(::StrProperty, RandomNormalTextureName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, RandomNormalTexture)
		ADD_VAR(::StrProperty, RandomAngleTextureName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, RandomAngleTexture)
		ADD_VAR(::StrProperty, ScreenDoorNoiseTextureName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, ScreenDoorNoiseTexture)
		ADD_VAR(::StrProperty, SceneCaptureCubeActorMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, SceneCaptureCubeActorMaterial)
		ADD_VAR(::StrProperty, SceneCaptureReflectActorMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, SceneCaptureReflectActorMaterial)
		ADD_VAR(::StrProperty, DefaultUICaretMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, DefaultUICaretMaterial)
		ADD_VAR(::StrProperty, DefaultUIScenePostProcessName, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, DefaultUIScenePostProcess)
		ADD_VAR(::StrProperty, ThumbnailMaterialPostProcessName, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, ThumbnailMaterialPostProcess)
		ADD_VAR(::StrProperty, ThumbnailParticleSystemPostProcessName, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, ThumbnailParticleSystemPostProcess)
		ADD_VAR(::StrProperty, ThumbnailSkeletalMeshPostProcessName, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, ThumbnailSkeletalMeshPostProcess)
		ADD_VAR(::StrProperty, DefaultPostProcessName, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, DefaultPostProcess)
		ADD_VAR(::StrProperty, DefaultOnlineSubsystemName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, OnlineSubsystemClass)
		ADD_VAR(::FloatProperty, TerrainTessellationCheckDistance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TerrainTessellationCheckCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TerrainMaterialMaxTextureCount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TerrainErrorMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, TerrainErrorMaterial)
		ADD_VAR(::StrProperty, ApexDamageParamsName, 0xFFFFFFFF)
		ADD_OBJECT(ApexDestructibleDamageParameters, ApexDamageParams)
		ADD_VAR(::StrProperty, DefaultPhysMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysMaterial)
		ADD_VAR(::StrProperty, EditorBrushMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, EditorBrushMaterial)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'LightMapDensitySelectedColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'LightMapDensityVertexMappedColor'!
		ADD_VAR(::FloatProperty, RenderLightMapDensityColorScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RenderLightMapDensityGrayscaleScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxLightMapDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IdealLightMapDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinLightMapDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTextureDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IdealTextureDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinTextureDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPixelShaderAdditiveComplexityCount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'LightingOnlyBrightness'!
		ADD_VAR(::IntProperty, ImageReflectionTextureSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxRMSDForCombiningMappings, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisableAILogging, 0x40000000)
		ADD_VAR(::BoolProperty, bCookSeparateSharedMPGameContent, 0x20000000)
		ADD_VAR(::BoolProperty, bSuppressMapWarnings, 0x10000000)
		ADD_VAR(::BoolProperty, bEnableOnScreenDebugMessagesDisplay, 0x8000000)
		ADD_VAR(::BoolProperty, bEnableOnScreenDebugMessages, 0x4000000)
		ADD_VAR(::BoolProperty, bEmulateMobileRendering, 0x2000000)
		ADD_VAR(::BoolProperty, bHasPendingGlobalReattach, 0x1000000)
		ADD_VAR(::BoolProperty, bAreConstraintsDirty, 0x800000)
		ADD_VAR(::BoolProperty, bEnableColorClear, 0x400000)
		ADD_VAR(::BoolProperty, bCheckParticleRenderSize, 0x200000)
		ADD_VAR(::BoolProperty, bPauseOnLossOfFocus, 0x100000)
		ADD_VAR(::BoolProperty, bDisablePhysXHardwareSupport, 0x80000)
		ADD_VAR(::BoolProperty, bRenderTerrainCollisionAsOverlay, 0x40000)
		ADD_VAR(::BoolProperty, bAllowMatureLanguage, 0x20000)
		ADD_VAR(::BoolProperty, bEnableKismetLogging, 0x10000)
		ADD_VAR(::BoolProperty, bOnScreenKismetWarnings, 0x8000)
		ADD_VAR(::BoolProperty, bUsePostProcessEffects, 0x4000)
		ADD_VAR(::BoolProperty, bForceCPUSkinning, 0x2000)
		ADD_VAR(::BoolProperty, bForceStaticTerrain, 0x1000)
		ADD_VAR(::BoolProperty, bShouldGenerateSimpleLightmaps, 0x800)
		ADD_VAR(::BoolProperty, HACK_EnableDMC, 0x400)
		ADD_VAR(::BoolProperty, HACK_UseTickFrequency, 0x200)
		ADD_VAR(::BoolProperty, bSmoothFrameRate, 0x100)
		ADD_VAR(::BoolProperty, bSubtitlesForcedOff, 0x80)
		ADD_VAR(::BoolProperty, bSubtitlesEnabled, 0x40)
		ADD_VAR(::BoolProperty, bUseBackgroundLevelStreaming, 0x20)
		ADD_VAR(::BoolProperty, bUseSound, 0x10)
		ADD_VAR(::BoolProperty, bRenderLightMapDensityGrayscale, 0x8)
		ADD_VAR(::BoolProperty, bCombineSimilarMappings, 0x4)
		ADD_VAR(::BoolProperty, ForcePowerOfTwoProcBuildingLODTextures, 0x2)
		ADD_VAR(::BoolProperty, UseProcBuildingLODTextureCropping, 0x1)
		ADD_VAR(::IntProperty, MaxProcBuildingLODLightingTextureSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxProcBuildingLODColorTextureSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProcBuildingLODLightingTexelsPerWorldUnit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProcBuildingLODColorTexelsPerWorldUnit, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BuildingQuadStaticMeshName, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, BuildingQuadStaticMesh)
		ADD_VAR(::StrProperty, ProcBuildingSimpleMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, ProcBuildingSimpleMaterial)
		ADD_VAR(::StrProperty, TangentColorMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, TangentColorMaterial)
		ADD_VAR(::StrProperty, BoneWeightMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, BoneWeightMaterial)
		ADD_VAR(::StrProperty, HeatmapMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, HeatmapMaterial)
		ADD_VAR(::StrProperty, VertexColorViewModeMaterialName_BlueOnly, 0xFFFFFFFF)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_BlueOnly)
		ADD_VAR(::StrProperty, VertexColorViewModeMaterialName_GreenOnly, 0xFFFFFFFF)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_GreenOnly)
		ADD_VAR(::StrProperty, VertexColorViewModeMaterialName_RedOnly, 0xFFFFFFFF)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_RedOnly)
		ADD_VAR(::StrProperty, VertexColorViewModeMaterialName_AlphaAsColor, 0xFFFFFFFF)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_AlphaAsColor)
		ADD_VAR(::StrProperty, VertexColorViewModeMaterialName_ColorOnly, 0xFFFFFFFF)
		ADD_OBJECT(Material, VertexColorViewModeMaterial_ColorOnly)
		ADD_VAR(::StrProperty, VertexColorMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, VertexColorMaterial)
		ADD_VAR(::StrProperty, RemoveSurfaceMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, RemoveSurfaceMaterial)
		ADD_VAR(::StrProperty, ShadedLevelColorationUnlitMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, ShadedLevelColorationUnlitMaterial)
		ADD_VAR(::StrProperty, ShadedLevelColorationLitMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, ShadedLevelColorationLitMaterial)
		ADD_VAR(::StrProperty, LightingTexelDensityName, 0xFFFFFFFF)
		ADD_OBJECT(Material, LightingTexelDensityMaterial)
		ADD_VAR(::StrProperty, LevelColorationUnlitMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, LevelColorationUnlitMaterial)
		ADD_VAR(::StrProperty, LevelColorationLitMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, LevelColorationLitMaterial)
		ADD_VAR(::StrProperty, CrossMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, CrossMaterial)
		ADD_VAR(::StrProperty, TickMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, TickMaterial)
		ADD_VAR(::StrProperty, DefaultFogVolumeMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, DefaultFogVolumeMaterial)
		ADD_VAR(::StrProperty, GeomMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, GeomMaterial)
		ADD_VAR(::StrProperty, EmissiveTexturedMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, EmissiveTexturedMaterial)
		ADD_VAR(::StrProperty, WireframeMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, WireframeMaterial)
		ADD_VAR(::StrProperty, DefaultTextureName, 0xFFFFFFFF)
		ADD_OBJECT(Texture, DefaultTexture)
		ADD_VAR(::StrProperty, DefaultDecalMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, DefaultDecalMaterial)
		ADD_VAR(::StrProperty, DefaultMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(Material, DefaultMaterial)
		ADD_VAR(::StrProperty, LocalPlayerClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, LocalPlayerClass)
		ADD_VAR(::StrProperty, DataStoreClientClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DataStoreClientClass)
		ADD_VAR(::StrProperty, GameViewportClientClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, GameViewportClientClass)
		ADD_VAR(::StrProperty, ConsoleClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ConsoleClass)
		ADD_VAR(::StrProperty, SubtitleFontName, 0xFFFFFFFF)
		ADD_OBJECT(Font, SubtitleFont)
		ADD_VAR(::StrProperty, LargeFontName, 0xFFFFFFFF)
		ADD_OBJECT(Font, LargeFont)
		ADD_VAR(::StrProperty, MediumFontName, 0xFFFFFFFF)
		ADD_OBJECT(Font, MediumFont)
		ADD_VAR(::StrProperty, SmallFontName, 0xFFFFFFFF)
		ADD_OBJECT(Font, SmallFont)
		ADD_VAR(::StrProperty, TinyFontName, 0xFFFFFFFF)
		ADD_OBJECT(Font, TinyFont)
		bool IsGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.IsGame");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsEditor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.IsEditor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class Font* GetSmallFont()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetSmallFont");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)params;
			free(params);
			return returnVal;
		}
		class AudioDevice* GetAudioDevice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetAudioDevice");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AudioDevice**)params;
			free(params);
			return returnVal;
		}
		bool IsSplitScreen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.IsSplitScreen");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class Font* GetTinyFont()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetTinyFont");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)params;
			free(params);
			return returnVal;
		}
		class Font* GetMediumFont()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetMediumFont");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)params;
			free(params);
			return returnVal;
		}
		class Font* GetLargeFont()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetLargeFont");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)params;
			free(params);
			return returnVal;
		}
		class WorldInfo* GetCurrentWorldInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetCurrentWorldInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class WorldInfo**)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetBuildDate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetBuildDate");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		class Font* GetSubtitleFont()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetSubtitleFont");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)params;
			free(params);
			return returnVal;
		}
		class Font* GetAdditionalFont(int AdditionalFontIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetAdditionalFont");
			byte* params = (byte*)malloc(8);
			*(int*)params = AdditionalFontIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetLastMovieName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetLastMovieName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool PlayLoadMapMovie()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.PlayLoadMapMovie");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void StopMovie(bool bDelayStopUntilGameHasRendered)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.StopMovie");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDelayStopUntilGameHasRendered;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveAllOverlays()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.RemoveAllOverlays");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddOverlay(class Font* Font, ScriptArray<wchar_t> Text, float X, float Y, float ScaleX, float ScaleY, bool bIsCentered)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.AddOverlay");
			byte* params = (byte*)malloc(36);
			*(class Font**)params = Font;
			*(ScriptArray<wchar_t>*)(params + 4) = Text;
			*(float*)(params + 16) = X;
			*(float*)(params + 20) = Y;
			*(float*)(params + 24) = ScaleX;
			*(float*)(params + 28) = ScaleY;
			*(bool*)(params + 32) = bIsCentered;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddOverlayWrapped(class Font* Font, ScriptArray<wchar_t> Text, float X, float Y, float ScaleX, float ScaleY, float WrapWidth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.AddOverlayWrapped");
			byte* params = (byte*)malloc(36);
			*(class Font**)params = Font;
			*(ScriptArray<wchar_t>*)(params + 4) = Text;
			*(float*)(params + 16) = X;
			*(float*)(params + 20) = Y;
			*(float*)(params + 24) = ScaleX;
			*(float*)(params + 28) = ScaleY;
			*(float*)(params + 32) = WrapWidth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Engine* GetEngine()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetEngine");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Engine**)params;
			free(params);
			return returnVal;
		}
		class PostProcessChain* GetWorldPostProcessChain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.GetWorldPostProcessChain");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PostProcessChain**)params;
			free(params);
			return returnVal;
		}
		void AddTextureStreamingSlaveLoc(Vector InLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.AddTextureStreamingSlaveLoc");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = InLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool BasicSaveObject(class Object* Obj, ScriptArray<wchar_t> PathName, bool bIsSaveGame, int Version)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.BasicSaveObject");
			byte* params = (byte*)malloc(28);
			*(class Object**)params = Obj;
			*(ScriptArray<wchar_t>*)(params + 4) = PathName;
			*(bool*)(params + 16) = bIsSaveGame;
			*(int*)(params + 20) = Version;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool BasicLoadObject(class Object* Obj, ScriptArray<wchar_t> PathName, bool bIsSaveGame, int Version)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Engine.BasicLoadObject");
			byte* params = (byte*)malloc(28);
			*(class Object**)params = Obj;
			*(ScriptArray<wchar_t>*)(params + 4) = PathName;
			*(bool*)(params + 16) = bIsSaveGame;
			*(int*)(params + 20) = Version;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
