#pragma once
#include "Engine__ActorComponent.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__RB_BodyInstance.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PrimitiveComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PrimitiveComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PrimitiveComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PrimitiveComponent : public ActorComponent
	{
	public:
		ADD_VAR(::IntProperty, Tag, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'LocalToWorld'!
		ADD_VAR(::IntProperty, ThreadTag, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.BoxSphereBounds' for the property named 'Bounds'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SceneInfo'!
		ADD_VAR(::IntProperty, DetachFence, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LocalToWorldDeterminant, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MotionBlurInfoIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinDrawDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MassiveLODDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDrawDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CachedMaxDrawDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CullDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CachedCullDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DepthPriorityGroup, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ViewOwnerDepthPriorityGroup, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DetailMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RBChannel, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RBDominanceGroup, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PreviewEnvironmentShadowing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MotionBlurScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseViewOwnerDepthPriorityGroup, 0x1)
		ADD_VAR(::BoolProperty, bAllowCullDistanceVolume, 0x2)
		ADD_VAR(::BoolProperty, HiddenGame, 0x4)
		ADD_VAR(::BoolProperty, HiddenEditor, 0x8)
		ADD_VAR(::BoolProperty, bOwnerNoSee, 0x10)
		ADD_VAR(::BoolProperty, bOnlyOwnerSee, 0x20)
		ADD_VAR(::BoolProperty, bIgnoreOwnerHidden, 0x40)
		ADD_VAR(::BoolProperty, bUseAsOccluder, 0x80)
		ADD_VAR(::BoolProperty, bAllowApproximateOcclusion, 0x100)
		ADD_VAR(::BoolProperty, bFirstFrameOcclusion, 0x200)
		ADD_VAR(::BoolProperty, bIgnoreNearPlaneIntersection, 0x400)
		ADD_VAR(::BoolProperty, bSelectable, 0x800)
		ADD_VAR(::BoolProperty, bForceMipStreaming, 0x1000)
		ADD_VAR(::BoolProperty, bAcceptsDecals, 0x2000)
		ADD_VAR(::BoolProperty, bAcceptsDecalsDuringGameplay, 0x4000)
		ADD_VAR(::BoolProperty, bAcceptsStaticDecals, 0x8000)
		ADD_VAR(::BoolProperty, bAcceptsDynamicDecals, 0x10000)
		ADD_VAR(::BoolProperty, bIsRefreshingDecals, 0x20000)
		ADD_VAR(::BoolProperty, bAllowDecalAutomaticReAttach, 0x40000)
		ADD_VAR(::BoolProperty, CastShadow, 0x80000)
		ADD_VAR(::BoolProperty, bForceDirectLightMap, 0x100000)
		ADD_VAR(::BoolProperty, bCastDynamicShadow, 0x200000)
		ADD_VAR(::BoolProperty, bUsesPlayerShadowFadeResolution, 0x400000)
		ADD_VAR(::BoolProperty, bSelfShadowOnly, 0x800000)
		ADD_VAR(::BoolProperty, bAcceptsDynamicDominantLightShadows, 0x1000000)
		ADD_VAR(::BoolProperty, bCastHiddenShadow, 0x2000000)
		ADD_VAR(::BoolProperty, bCastShadowAsTwoSided, 0x4000000)
		ADD_VAR(::BoolProperty, bAcceptsLights, 0x8000000)
		ADD_VAR(::BoolProperty, bAcceptsDynamicLights, 0x10000000)
		ADD_VAR(::BoolProperty, bUseOnePassLightingOnTranslucency, 0x20000000)
		ADD_VAR(::BoolProperty, bUsePrecomputedShadows, 0x40000000)
		ADD_VAR(::BoolProperty, bHasExplicitShadowParent, 0x80000000)
		ADD_VAR(::BoolProperty, bCullModulatedShadowOnBackfaces, 0x1)
		ADD_VAR(::BoolProperty, bCullModulatedShadowOnEmissive, 0x2)
		ADD_VAR(::BoolProperty, bAllowAmbientOcclusion, 0x4)
		ADD_VAR(::BoolProperty, CollideActors, 0x8)
		ADD_VAR(::BoolProperty, AlwaysCheckCollision, 0x10)
		ADD_VAR(::BoolProperty, BlockActors, 0x20)
		ADD_VAR(::BoolProperty, BlockZeroExtent, 0x40)
		ADD_VAR(::BoolProperty, BlockNonZeroExtent, 0x80)
		ADD_VAR(::BoolProperty, CanBlockCamera, 0x100)
		ADD_VAR(::BoolProperty, BlockRigidBody, 0x200)
		ADD_VAR(::BoolProperty, bDisableAllRigidBody, 0x400)
		ADD_VAR(::BoolProperty, bSkipRBGeomCreation, 0x800)
		ADD_VAR(::BoolProperty, bNotifyRigidBodyCollision, 0x1000)
		ADD_VAR(::BoolProperty, bFluidDrain, 0x2000)
		ADD_VAR(::BoolProperty, bFluidTwoWay, 0x4000)
		ADD_VAR(::BoolProperty, bIgnoreRadialImpulse, 0x8000)
		ADD_VAR(::BoolProperty, bIgnoreRadialForce, 0x10000)
		ADD_VAR(::BoolProperty, bIgnoreForceField, 0x20000)
		ADD_VAR(::BoolProperty, bUseCompartment, 0x40000)
		ADD_VAR(::BoolProperty, AlwaysLoadOnClient, 0x80000)
		ADD_VAR(::BoolProperty, AlwaysLoadOnServer, 0x100000)
		ADD_VAR(::BoolProperty, bIgnoreHiddenActorsMembership, 0x200000)
		ADD_VAR(::BoolProperty, AbsoluteTranslation, 0x400000)
		ADD_VAR(::BoolProperty, AbsoluteRotation, 0x800000)
		ADD_VAR(::BoolProperty, AbsoluteScale, 0x1000000)
		ADD_VAR(::BoolProperty, bAllowShadowFade, 0x2000000)
		ADD_VAR(::BoolProperty, bWasSNFiltered, 0x4000000)
		ADD_VAR(::IntProperty, TranslucencySortPriority, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VisibilityId, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer' for the property named 'LightingChannels'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer' for the property named 'RBCollideWithChannels'!
		ADD_OBJECT(PhysicalMaterial, PhysMaterialOverride)
		ADD_OBJECT(RB_BodyInstance, BodyInstance)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'CachedParentToWorld'!
		ADD_STRUCT(::VectorProperty, Translation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Scale3D, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, BoundsScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSubmitTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastRenderTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScriptRigidBodyCollisionThreshold, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetBlockRigidBody'
		// Here lies the not-yet-implemented method 'SetRBLinearVelocity'
		// Here lies the not-yet-implemented method 'AddImpulse'
		// Here lies the not-yet-implemented method 'AddRadialImpulse'
		// Here lies the not-yet-implemented method 'AddForce'
		// Here lies the not-yet-implemented method 'AddRadialForce'
		// Here lies the not-yet-implemented method 'AddTorque'
		// Here lies the not-yet-implemented method 'SetRBAngularVelocity'
		// Here lies the not-yet-implemented method 'RetardRBLinearVelocity'
		// Here lies the not-yet-implemented method 'SetRBPosition'
		// Here lies the not-yet-implemented method 'SetRBRotation'
		// Here lies the not-yet-implemented method 'WakeRigidBody'
		// Here lies the not-yet-implemented method 'PutRigidBodyToSleep'
		// Here lies the not-yet-implemented method 'RigidBodyIsAwake'
		// Here lies the not-yet-implemented method 'SetRBCollidesWithChannel'
		// Here lies the not-yet-implemented method 'SetRBCollisionChannels'
		// Here lies the not-yet-implemented method 'SetRBChannel'
		// Here lies the not-yet-implemented method 'SetNotifyRigidBodyCollision'
		// Here lies the not-yet-implemented method 'InitRBPhys'
		// Here lies the not-yet-implemented method 'SetPhysMaterialOverride'
		// Here lies the not-yet-implemented method 'GetRootBodyInstance'
		// Here lies the not-yet-implemented method 'SetRBDominanceGroup'
		// Here lies the not-yet-implemented method 'ShouldComponentAddToScene'
		// Here lies the not-yet-implemented method 'SetHidden'
		// Here lies the not-yet-implemented method 'SetOwnerNoSee'
		// Here lies the not-yet-implemented method 'SetOnlyOwnerSee'
		// Here lies the not-yet-implemented method 'SetIgnoreOwnerHidden'
		// Here lies the not-yet-implemented method 'SetShadowParent'
		// Here lies the not-yet-implemented method 'SetLightEnvironment'
		// Here lies the not-yet-implemented method 'SetCullDistance'
		// Here lies the not-yet-implemented method 'SetLightingChannels'
		// Here lies the not-yet-implemented method 'SetDepthPriorityGroup'
		// Here lies the not-yet-implemented method 'SetViewOwnerDepthPriorityGroup'
		// Here lies the not-yet-implemented method 'SetTraceBlocking'
		// Here lies the not-yet-implemented method 'SetActorCollision'
		// Here lies the not-yet-implemented method 'SetTranslation'
		// Here lies the not-yet-implemented method 'SetRotation'
		// Here lies the not-yet-implemented method 'SetScale'
		// Here lies the not-yet-implemented method 'SetScale3D'
		// Here lies the not-yet-implemented method 'SetAbsolute'
		// Here lies the not-yet-implemented method 'GetPosition'
		// Here lies the not-yet-implemented method 'GetRotation'
		// Here lies the not-yet-implemented method 'ClosestPointOnComponentToPoint'
		// Here lies the not-yet-implemented method 'ClosestPointOnComponentToComponent'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
