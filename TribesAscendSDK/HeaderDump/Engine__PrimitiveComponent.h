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
		ADD_STRUCT(::VectorProperty, Translation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Scale3D, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoundsScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSubmitTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastRenderTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScriptRigidBodyCollisionThreshold, 0xFFFFFFFF)
		void SetBlockRigidBody(bool bNewBlockRigidBody)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetBlockRigidBody");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewBlockRigidBody;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRBLinearVelocity(Vector NewVel, bool bAddToCurrent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBLinearVelocity");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = NewVel;
			*(bool*)(params + 12) = bAddToCurrent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddImpulse(Vector Impulse, Vector Position, ScriptName BoneName, bool bVelChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddImpulse");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = Impulse;
			*(Vector*)(params + 12) = Position;
			*(ScriptName*)(params + 24) = BoneName;
			*(bool*)(params + 32) = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddRadialImpulse(Vector Origin, float Radius, float Strength, byte Falloff, bool bVelChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddRadialImpulse");
			byte* params = (byte*)malloc(25);
			*(Vector*)params = Origin;
			*(float*)(params + 12) = Radius;
			*(float*)(params + 16) = Strength;
			*(params + 20) = Falloff;
			*(bool*)(params + 24) = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddForce(Vector Force, Vector Position, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddForce");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = Force;
			*(Vector*)(params + 12) = Position;
			*(ScriptName*)(params + 24) = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddRadialForce(Vector Origin, float Radius, float Strength, byte Falloff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddRadialForce");
			byte* params = (byte*)malloc(21);
			*(Vector*)params = Origin;
			*(float*)(params + 12) = Radius;
			*(float*)(params + 16) = Strength;
			*(params + 20) = Falloff;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddTorque(Vector Torque, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddTorque");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = Torque;
			*(ScriptName*)(params + 12) = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRBAngularVelocity(Vector NewAngVel, bool bAddToCurrent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBAngularVelocity");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = NewAngVel;
			*(bool*)(params + 12) = bAddToCurrent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RetardRBLinearVelocity(Vector RetardDir, float VelScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.RetardRBLinearVelocity");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = RetardDir;
			*(float*)(params + 12) = VelScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRBPosition(Vector NewPos, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBPosition");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = NewPos;
			*(ScriptName*)(params + 12) = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRBRotation(Rotator NewRot, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBRotation");
			byte* params = (byte*)malloc(20);
			*(Rotator*)params = NewRot;
			*(ScriptName*)(params + 12) = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WakeRigidBody(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.WakeRigidBody");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PutRigidBodyToSleep(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.PutRigidBodyToSleep");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RigidBodyIsAwake(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.RigidBodyIsAwake");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetRBCollidesWithChannel(byte Channel, bool bNewCollides)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBCollidesWithChannel");
			byte* params = (byte*)malloc(5);
			*params = Channel;
			*(bool*)(params + 4) = bNewCollides;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRBCollisionChannels(
// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer'!
void* Channels)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBCollisionChannels");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer'!
void**)params = Channels;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRBChannel(byte Channel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBChannel");
			byte* params = (byte*)malloc(1);
			*params = Channel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetNotifyRigidBodyCollision(bool bNewNotifyRigidBodyCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetNotifyRigidBodyCollision");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewNotifyRigidBodyCollision;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.InitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhysMaterialOverride(class PhysicalMaterial* NewPhysMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetPhysMaterialOverride");
			byte* params = (byte*)malloc(4);
			*(class PhysicalMaterial**)params = NewPhysMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class RB_BodyInstance* GetRootBodyInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.GetRootBodyInstance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class RB_BodyInstance**)params;
			free(params);
			return returnVal;
		}
		void SetRBDominanceGroup(byte InDomGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBDominanceGroup");
			byte* params = (byte*)malloc(1);
			*params = InDomGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldComponentAddToScene()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.ShouldComponentAddToScene");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetHidden(bool NewHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetHidden");
			byte* params = (byte*)malloc(4);
			*(bool*)params = NewHidden;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOwnerNoSee(bool bNewOwnerNoSee)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetOwnerNoSee");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewOwnerNoSee;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOnlyOwnerSee(bool bNewOnlyOwnerSee)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetOnlyOwnerSee");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewOnlyOwnerSee;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetIgnoreOwnerHidden(bool bNewIgnoreOwnerHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetIgnoreOwnerHidden");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewIgnoreOwnerHidden;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetShadowParent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewShadowParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetShadowParent");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewShadowParent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLightEnvironment(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewLightEnvironment)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetLightEnvironment");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewLightEnvironment;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCullDistance(float NewCullDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetCullDistance");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewCullDistance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLightingChannels(
// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer'!
void* NewLightingChannels)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetLightingChannels");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer'!
void**)params = NewLightingChannels;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDepthPriorityGroup(byte NewDepthPriorityGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetDepthPriorityGroup");
			byte* params = (byte*)malloc(1);
			*params = NewDepthPriorityGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetViewOwnerDepthPriorityGroup(bool bNewUseViewOwnerDepthPriorityGroup, byte NewViewOwnerDepthPriorityGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetViewOwnerDepthPriorityGroup");
			byte* params = (byte*)malloc(5);
			*(bool*)params = bNewUseViewOwnerDepthPriorityGroup;
			*(params + 4) = NewViewOwnerDepthPriorityGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTraceBlocking(bool NewBlockZeroExtent, bool NewBlockNonZeroExtent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetTraceBlocking");
			byte* params = (byte*)malloc(8);
			*(bool*)params = NewBlockZeroExtent;
			*(bool*)(params + 4) = NewBlockNonZeroExtent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActorCollision(bool NewCollideActors, bool NewBlockActors, bool NewAlwaysCheckCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetActorCollision");
			byte* params = (byte*)malloc(12);
			*(bool*)params = NewCollideActors;
			*(bool*)(params + 4) = NewBlockActors;
			*(bool*)(params + 8) = NewAlwaysCheckCollision;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTranslation(Vector NewTranslation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetTranslation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewTranslation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRotation");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetScale(float NewScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetScale");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetScale3D(Vector NewScale3D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetScale3D");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewScale3D;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAbsolute(bool NewAbsoluteTranslation, bool NewAbsoluteRotation, bool NewAbsoluteScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetAbsolute");
			byte* params = (byte*)malloc(12);
			*(bool*)params = NewAbsoluteTranslation;
			*(bool*)(params + 4) = NewAbsoluteRotation;
			*(bool*)(params + 8) = NewAbsoluteScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.GetPosition");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Rotator GetRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.GetRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		byte ClosestPointOnComponentToPoint(Vector& POI, Vector& Extent, Vector& OutPointA, Vector& OutPointB)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.ClosestPointOnComponentToPoint");
			byte* params = (byte*)malloc(49);
			*(Vector*)params = POI;
			*(Vector*)(params + 12) = Extent;
			*(Vector*)(params + 24) = OutPointA;
			*(Vector*)(params + 36) = OutPointB;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			POI = *(Vector*)params;
			Extent = *(Vector*)(params + 12);
			OutPointA = *(Vector*)(params + 24);
			OutPointB = *(Vector*)(params + 36);
			auto returnVal = *(params + 48);
			free(params);
			return returnVal;
		}
		byte ClosestPointOnComponentToComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& OtherComponent, Vector& PointOnComponentA, Vector& PointOnComponentB)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.ClosestPointOnComponentToComponent");
			byte* params = (byte*)malloc(29);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = OtherComponent;
			*(Vector*)(params + 4) = PointOnComponentA;
			*(Vector*)(params + 16) = PointOnComponentB;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OtherComponent = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
			PointOnComponentA = *(Vector*)(params + 4);
			PointOnComponentB = *(Vector*)(params + 16);
			auto returnVal = *(params + 28);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
