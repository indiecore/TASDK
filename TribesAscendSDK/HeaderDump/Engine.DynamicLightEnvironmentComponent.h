#pragma once
#include "Engine.LightEnvironmentComponent.h"
#include "Engine.LightComponent.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class DynamicLightEnvironmentComponent : public LightEnvironmentComponent
	{
	public:
		enum EDynamicLightEnvironmentBoundsMethod : byte
		{
			DLEB_OwnerComponents = 0,
			DLEB_ManualOverride = 1,
			DLEB_ActiveComponents = 2,
			DLEB_MAX = 3,
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, OverriddenLightComponents, 284)
		ADD_STRUCT(LightComponent::LightingChannelContainer, OverriddenLightingChannels, 280)
		ADD_STRUCT(Object::BoxSphereBounds, OverriddenBounds, 252)
		ADD_STRUCT(float, MinShadowAngle, 248)
		ADD_STRUCT(float, BouncedLightingFactor, 244)
		ADD_STRUCT(DynamicLightEnvironmentComponent::EDynamicLightEnvironmentBoundsMethod, BoundsMethod, 242)
		ADD_STRUCT(Object::Pointer, State, 112)
		ADD_STRUCT(LightComponent::ELightShadowMode, LightShadowMode, 241)
		ADD_STRUCT(LightComponent::EShadowFilterQuality, ShadowFilterQuality, 240)
		ADD_STRUCT(int, ShadowFadeResolution, 236)
		ADD_STRUCT(int, MaxShadowResolution, 232)
		ADD_STRUCT(int, MinShadowResolution, 228)
		ADD_STRUCT(float, DominantShadowTransitionEndDistance, 224)
		ADD_STRUCT(float, DominantShadowTransitionStartDistance, 220)
		ADD_STRUCT(Object::LinearColor, MaxModulatedShadowColor, 204)
		ADD_STRUCT(float, ModShadowFadeoutExponent, 200)
		ADD_STRUCT(float, ModShadowFadeoutTime, 196)
		ADD_BOOL(bOverrideOwnerLightingChannels, 192, 0x2000)
		ADD_BOOL(bIsCharacterLightEnvironment, 192, 0x1000)
		ADD_BOOL(bTraceFromClosestBoundsPoint, 192, 0x800)
		ADD_BOOL(bRequiresNonLatentUpdates, 192, 0x400)
		ADD_BOOL(bForceAllowLightEnvSphericalHarmonicLights, 192, 0x200)
		ADD_BOOL(bSynthesizeSHLight, 192, 0x100)
		ADD_BOOL(bSynthesizeDirectionalLight, 192, 0x80)
		ADD_BOOL(bDynamic, 192, 0x40)
		ADD_BOOL(bShadowFromEnvironment, 192, 0x20)
		ADD_BOOL(bUseBooleanEnvironmentShadowing, 192, 0x10)
		ADD_BOOL(bAffectedBySmallDynamicLights, 192, 0x8)
		ADD_BOOL(bForceCompositeAllLights, 192, 0x4)
		ADD_BOOL(bCompositeShadowsFromDynamicLights, 192, 0x2)
		ADD_BOOL(bCastShadows, 192, 0x1)
		ADD_STRUCT(float, ShadowDistance, 188)
		ADD_STRUCT(float, LightDistance, 184)
		ADD_STRUCT(float, LightDesaturation, 180)
		ADD_STRUCT(Object::LinearColor, AmbientGlow, 164)
		ADD_STRUCT(Object::Vector, AmbientShadowSourceDirection, 152)
		ADD_STRUCT(Object::LinearColor, AmbientShadowColor, 136)
		ADD_STRUCT(float, LightingBoundsScale, 132)
		ADD_STRUCT(int, NumVolumeVisibilitySamples, 128)
		ADD_STRUCT(float, ShadowInterpolationSpeed, 124)
		ADD_STRUCT(float, MinTimeBetweenFullUpdates, 120)
		ADD_STRUCT(float, InvisibleUpdateTime, 116)
		void ResetEnvironment()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DynamicLightEnvironmentComponent.ResetEnvironment");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
