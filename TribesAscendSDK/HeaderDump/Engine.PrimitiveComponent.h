#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.h"
#include "Engine.Scene.h"
#include "Engine.RB_BodyInstance.h"
#include "Engine.LightComponent.h"
#include "Engine.PhysicalMaterial.h"
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
	class PrimitiveComponent : public ActorComponent
	{
	public:
		enum GJKResult : byte
		{
			GJK_Intersect = 0,
			GJK_NoIntersection = 1,
			GJK_Fail = 2,
			GJK_MAX = 3,
		};
		enum ERBCollisionChannel : byte
		{
			RBCC_Default = 0,
			RBCC_Nothing = 1,
			RBCC_Pawn = 2,
			RBCC_Vehicle = 3,
			RBCC_Water = 4,
			RBCC_GameplayPhysics = 5,
			RBCC_EffectPhysics = 6,
			RBCC_Untitled1 = 7,
			RBCC_Untitled2 = 8,
			RBCC_Untitled3 = 9,
			RBCC_Untitled4 = 10,
			RBCC_Cloth = 11,
			RBCC_FluidDrain = 12,
			RBCC_SoftBody = 13,
			RBCC_FracturedMeshPart = 14,
			RBCC_BlockingVolume = 15,
			RBCC_DeadPawn = 16,
			RBCC_Clothing = 17,
			RBCC_ClothingCollision = 18,
			RBCC_MAX = 19,
		};
		enum ERadialImpulseFalloff : byte
		{
			RIF_Constant = 0,
			RIF_Linear = 1,
			RIF_MAX = 2,
		};
		class RBCollisionChannelContainer
		{
		public:
			ADD_BOOL(Default, 0, 0x1)
			ADD_BOOL(Nothing, 0, 0x2)
			ADD_BOOL(Pawn, 0, 0x4)
			ADD_BOOL(Vehicle, 0, 0x8)
			ADD_BOOL(Water, 0, 0x10)
			ADD_BOOL(GameplayPhysics, 0, 0x20)
			ADD_BOOL(EffectPhysics, 0, 0x40)
			ADD_BOOL(Untitled1, 0, 0x80)
			ADD_BOOL(Untitled2, 0, 0x100)
			ADD_BOOL(Untitled3, 0, 0x200)
			ADD_BOOL(Untitled4, 0, 0x400)
			ADD_BOOL(Cloth, 0, 0x800)
			ADD_BOOL(FluidDrain, 0, 0x1000)
			ADD_BOOL(SoftBody, 0, 0x2000)
			ADD_BOOL(FracturedMeshPart, 0, 0x4000)
			ADD_BOOL(BlockingVolume, 0, 0x8000)
			ADD_BOOL(DeadPawn, 0, 0x10000)
			ADD_BOOL(Clothing, 0, 0x20000)
			ADD_BOOL(ClothingCollision, 0, 0x40000)
		};
		class MaterialViewRelevance
		{
		public:
			ADD_BOOL(bOpaque, 0, 0x1)
			ADD_BOOL(bTranslucent, 0, 0x2)
			ADD_BOOL(bDistortion, 0, 0x4)
			ADD_BOOL(bOneLayerDistortionRelevance, 0, 0x8)
			ADD_BOOL(bLit, 0, 0x10)
			ADD_BOOL(bUsesSceneColor, 0, 0x20)
		};
		ADD_STRUCT(int, Tag, 88)
		ADD_STRUCT(Object::Matrix, LocalToWorld, 160)
		ADD_STRUCT(int, ThreadTag, 92)
		ADD_STRUCT(Object::BoxSphereBounds, Bounds, 120)
		ADD_STRUCT(Object::Pointer, SceneInfo, 148)
		ADD_STRUCT(int, DetachFence, 152)
		ADD_STRUCT(float, LocalToWorldDeterminant, 156)
		ADD_STRUCT(int, MotionBlurInfoIndex, 224)
		ADD_STRUCT(ScriptArray<Object::Pointer>, DecalList, 228)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, DecalsToReattach, 240)
		ADD_STRUCT(float, MinDrawDistance, 276)
		ADD_STRUCT(float, MassiveLODDistance, 280)
		ADD_STRUCT(float, MaxDrawDistance, 284)
		ADD_STRUCT(float, CachedMaxDrawDistance, 288)
		ADD_STRUCT(float, CullDistance, 292)
		ADD_STRUCT(float, CachedCullDistance, 296)
		ADD_STRUCT(Scene::ESceneDepthPriorityGroup, DepthPriorityGroup, 300)
		ADD_STRUCT(Scene::ESceneDepthPriorityGroup, ViewOwnerDepthPriorityGroup, 301)
		ADD_STRUCT(Scene::EDetailMode, DetailMode, 302)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, RBChannel, 303)
		ADD_STRUCT(byte, RBDominanceGroup, 304)
		ADD_STRUCT(byte, PreviewEnvironmentShadowing, 305)
		ADD_STRUCT(float, MotionBlurScale, 308)
		ADD_BOOL(bUseViewOwnerDepthPriorityGroup, 312, 0x1)
		ADD_BOOL(bAllowCullDistanceVolume, 312, 0x2)
		ADD_BOOL(HiddenGame, 312, 0x4)
		ADD_BOOL(HiddenEditor, 312, 0x8)
		ADD_BOOL(bOwnerNoSee, 312, 0x10)
		ADD_BOOL(bOnlyOwnerSee, 312, 0x20)
		ADD_BOOL(bIgnoreOwnerHidden, 312, 0x40)
		ADD_BOOL(bUseAsOccluder, 312, 0x80)
		ADD_BOOL(bAllowApproximateOcclusion, 312, 0x100)
		ADD_BOOL(bFirstFrameOcclusion, 312, 0x200)
		ADD_BOOL(bIgnoreNearPlaneIntersection, 312, 0x400)
		ADD_BOOL(bSelectable, 312, 0x800)
		ADD_BOOL(bForceMipStreaming, 312, 0x1000)
		ADD_BOOL(bAcceptsDecals, 312, 0x2000)
		ADD_BOOL(bAcceptsDecalsDuringGameplay, 312, 0x4000)
		ADD_BOOL(bAcceptsStaticDecals, 312, 0x8000)
		ADD_BOOL(bAcceptsDynamicDecals, 312, 0x10000)
		ADD_BOOL(bIsRefreshingDecals, 312, 0x20000)
		ADD_BOOL(bAllowDecalAutomaticReAttach, 312, 0x40000)
		ADD_BOOL(CastShadow, 312, 0x80000)
		ADD_BOOL(bForceDirectLightMap, 312, 0x100000)
		ADD_BOOL(bCastDynamicShadow, 312, 0x200000)
		ADD_BOOL(bUsesPlayerShadowFadeResolution, 312, 0x400000)
		ADD_BOOL(bSelfShadowOnly, 312, 0x800000)
		ADD_BOOL(bAcceptsDynamicDominantLightShadows, 312, 0x1000000)
		ADD_BOOL(bCastHiddenShadow, 312, 0x2000000)
		ADD_BOOL(bCastShadowAsTwoSided, 312, 0x4000000)
		ADD_BOOL(bAcceptsLights, 312, 0x8000000)
		ADD_BOOL(bAcceptsDynamicLights, 312, 0x10000000)
		ADD_BOOL(bUseOnePassLightingOnTranslucency, 312, 0x20000000)
		ADD_BOOL(bUsePrecomputedShadows, 312, 0x40000000)
		ADD_BOOL(bHasExplicitShadowParent, 312, 0x80000000)
		ADD_BOOL(bCullModulatedShadowOnBackfaces, 316, 0x1)
		ADD_BOOL(bCullModulatedShadowOnEmissive, 316, 0x2)
		ADD_BOOL(bAllowAmbientOcclusion, 316, 0x4)
		ADD_BOOL(CollideActors, 316, 0x8)
		ADD_BOOL(AlwaysCheckCollision, 316, 0x10)
		ADD_BOOL(BlockActors, 316, 0x20)
		ADD_BOOL(BlockZeroExtent, 316, 0x40)
		ADD_BOOL(BlockNonZeroExtent, 316, 0x80)
		ADD_BOOL(CanBlockCamera, 316, 0x100)
		ADD_BOOL(BlockRigidBody, 316, 0x200)
		ADD_BOOL(bDisableAllRigidBody, 316, 0x400)
		ADD_BOOL(bSkipRBGeomCreation, 316, 0x800)
		ADD_BOOL(bNotifyRigidBodyCollision, 316, 0x1000)
		ADD_BOOL(bFluidDrain, 316, 0x2000)
		ADD_BOOL(bFluidTwoWay, 316, 0x4000)
		ADD_BOOL(bIgnoreRadialImpulse, 316, 0x8000)
		ADD_BOOL(bIgnoreRadialForce, 316, 0x10000)
		ADD_BOOL(bIgnoreForceField, 316, 0x20000)
		ADD_BOOL(bUseCompartment, 316, 0x40000)
		ADD_BOOL(AlwaysLoadOnClient, 316, 0x80000)
		ADD_BOOL(AlwaysLoadOnServer, 316, 0x100000)
		ADD_BOOL(bIgnoreHiddenActorsMembership, 316, 0x200000)
		ADD_BOOL(AbsoluteTranslation, 316, 0x400000)
		ADD_BOOL(AbsoluteRotation, 316, 0x800000)
		ADD_BOOL(AbsoluteScale, 316, 0x1000000)
		ADD_BOOL(bAllowShadowFade, 316, 0x2000000)
		ADD_BOOL(bWasSNFiltered, 316, 0x4000000)
		ADD_STRUCT(ScriptArray<int>, OctreeNodes, 320)
		ADD_STRUCT(int, TranslucencySortPriority, 332)
		ADD_STRUCT(int, VisibilityId, 336)
		ADD_STRUCT(LightComponent::LightingChannelContainer, LightingChannels, 340)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, RBCollideWithChannels, 344)
		ADD_OBJECT(PhysicalMaterial, PhysMaterialOverride, 348)
		ADD_OBJECT(RB_BodyInstance, BodyInstance, 352)
		ADD_STRUCT(Object::Matrix, CachedParentToWorld, 368)
		ADD_STRUCT(Object::Vector, Translation, 432)
		ADD_STRUCT(Object::Rotator, Rotation, 444)
		ADD_STRUCT(float, Scale, 456)
		ADD_STRUCT(Object::Vector, Scale3D, 460)
		ADD_STRUCT(float, BoundsScale, 472)
		ADD_STRUCT(float, LastSubmitTime, 476)
		ADD_STRUCT(float, LastRenderTime, 480)
		ADD_STRUCT(float, ScriptRigidBodyCollisionThreshold, 484)
		void SetBlockRigidBody(bool bNewBlockRigidBody)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetBlockRigidBody");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewBlockRigidBody;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBLinearVelocity(Object::Vector NewVel, bool bAddToCurrent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBLinearVelocity");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = NewVel;
			*(bool*)&params[12] = bAddToCurrent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddImpulse(Object::Vector Impulse, Object::Vector Position, ScriptName BoneName, bool bVelChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddImpulse");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = Impulse;
			*(Object::Vector*)&params[12] = Position;
			*(ScriptName*)&params[24] = BoneName;
			*(bool*)&params[32] = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRadialImpulse(Object::Vector Origin, float Radius, float Strength, PrimitiveComponent::ERadialImpulseFalloff Falloff, bool bVelChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddRadialImpulse");
			byte params[25] = { NULL };
			*(Object::Vector*)&params[0] = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = Strength;
			*(PrimitiveComponent::ERadialImpulseFalloff*)&params[20] = Falloff;
			*(bool*)&params[24] = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddForce(Object::Vector Force, Object::Vector Position, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddForce");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = Force;
			*(Object::Vector*)&params[12] = Position;
			*(ScriptName*)&params[24] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRadialForce(Object::Vector Origin, float Radius, float Strength, PrimitiveComponent::ERadialImpulseFalloff Falloff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddRadialForce");
			byte params[21] = { NULL };
			*(Object::Vector*)&params[0] = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = Strength;
			*(PrimitiveComponent::ERadialImpulseFalloff*)&params[20] = Falloff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddTorque(Object::Vector Torque, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.AddTorque");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = Torque;
			*(ScriptName*)&params[12] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBAngularVelocity(Object::Vector NewAngVel, bool bAddToCurrent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBAngularVelocity");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = NewAngVel;
			*(bool*)&params[12] = bAddToCurrent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RetardRBLinearVelocity(Object::Vector RetardDir, float VelScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.RetardRBLinearVelocity");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = RetardDir;
			*(float*)&params[12] = VelScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBPosition(Object::Vector NewPos, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBPosition");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = NewPos;
			*(ScriptName*)&params[12] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBRotation(Object::Rotator NewRot, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBRotation");
			byte params[20] = { NULL };
			*(Object::Rotator*)&params[0] = NewRot;
			*(ScriptName*)&params[12] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WakeRigidBody(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.WakeRigidBody");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PutRigidBodyToSleep(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.PutRigidBodyToSleep");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RigidBodyIsAwake(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.RigidBodyIsAwake");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetRBCollidesWithChannel(PrimitiveComponent::ERBCollisionChannel Channel, bool bNewCollides)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBCollidesWithChannel");
			byte params[5] = { NULL };
			*(PrimitiveComponent::ERBCollisionChannel*)&params[0] = Channel;
			*(bool*)&params[4] = bNewCollides;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBCollisionChannels(PrimitiveComponent::RBCollisionChannelContainer Channels)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBCollisionChannels");
			byte params[4] = { NULL };
			*(PrimitiveComponent::RBCollisionChannelContainer*)&params[0] = Channels;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRBChannel(PrimitiveComponent::ERBCollisionChannel Channel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBChannel");
			byte params[1] = { NULL };
			*(PrimitiveComponent::ERBCollisionChannel*)&params[0] = Channel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNotifyRigidBodyCollision(bool bNewNotifyRigidBodyCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetNotifyRigidBodyCollision");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewNotifyRigidBodyCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.InitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPhysMaterialOverride(class PhysicalMaterial* NewPhysMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetPhysMaterialOverride");
			byte params[4] = { NULL };
			*(class PhysicalMaterial**)&params[0] = NewPhysMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class RB_BodyInstance* GetRootBodyInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.GetRootBodyInstance");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class RB_BodyInstance**)&params[0];
		}
		void SetRBDominanceGroup(byte InDomGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRBDominanceGroup");
			byte params[1] = { NULL };
			params[0] = InDomGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldComponentAddToScene()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.ShouldComponentAddToScene");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetHidden(bool NewHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetHidden");
			byte params[4] = { NULL };
			*(bool*)&params[0] = NewHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOwnerNoSee(bool bNewOwnerNoSee)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetOwnerNoSee");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewOwnerNoSee;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyOwnerSee(bool bNewOnlyOwnerSee)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetOnlyOwnerSee");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewOnlyOwnerSee;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetIgnoreOwnerHidden(bool bNewIgnoreOwnerHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetIgnoreOwnerHidden");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewIgnoreOwnerHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShadowParent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewShadowParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetShadowParent");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = NewShadowParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightEnvironment(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewLightEnvironment)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetLightEnvironment");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = NewLightEnvironment;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCullDistance(float NewCullDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetCullDistance");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewCullDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightingChannels(LightComponent::LightingChannelContainer NewLightingChannels)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetLightingChannels");
			byte params[4] = { NULL };
			*(LightComponent::LightingChannelContainer*)&params[0] = NewLightingChannels;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDepthPriorityGroup(Scene::ESceneDepthPriorityGroup NewDepthPriorityGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetDepthPriorityGroup");
			byte params[1] = { NULL };
			*(Scene::ESceneDepthPriorityGroup*)&params[0] = NewDepthPriorityGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewOwnerDepthPriorityGroup(bool bNewUseViewOwnerDepthPriorityGroup, Scene::ESceneDepthPriorityGroup NewViewOwnerDepthPriorityGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetViewOwnerDepthPriorityGroup");
			byte params[5] = { NULL };
			*(bool*)&params[0] = bNewUseViewOwnerDepthPriorityGroup;
			*(Scene::ESceneDepthPriorityGroup*)&params[4] = NewViewOwnerDepthPriorityGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTraceBlocking(bool NewBlockZeroExtent, bool NewBlockNonZeroExtent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetTraceBlocking");
			byte params[8] = { NULL };
			*(bool*)&params[0] = NewBlockZeroExtent;
			*(bool*)&params[4] = NewBlockNonZeroExtent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActorCollision(bool NewCollideActors, bool NewBlockActors, bool NewAlwaysCheckCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetActorCollision");
			byte params[12] = { NULL };
			*(bool*)&params[0] = NewCollideActors;
			*(bool*)&params[4] = NewBlockActors;
			*(bool*)&params[8] = NewAlwaysCheckCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTranslation(Object::Vector NewTranslation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetTranslation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewTranslation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRotation(Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetRotation");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScale(float NewScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetScale");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScale3D(Object::Vector NewScale3D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetScale3D");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewScale3D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAbsolute(bool NewAbsoluteTranslation, bool NewAbsoluteRotation, bool NewAbsoluteScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.SetAbsolute");
			byte params[12] = { NULL };
			*(bool*)&params[0] = NewAbsoluteTranslation;
			*(bool*)&params[4] = NewAbsoluteRotation;
			*(bool*)&params[8] = NewAbsoluteScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.GetPosition");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		Object::Rotator GetRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.GetRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		PrimitiveComponent::GJKResult ClosestPointOnComponentToPoint(Object::Vector& POI, Object::Vector& Extent, Object::Vector& OutPointA, Object::Vector& OutPointB)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.ClosestPointOnComponentToPoint");
			byte params[49] = { NULL };
			*(Object::Vector*)&params[0] = POI;
			*(Object::Vector*)&params[12] = Extent;
			*(Object::Vector*)&params[24] = OutPointA;
			*(Object::Vector*)&params[36] = OutPointB;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POI = *(Object::Vector*)&params[0];
			Extent = *(Object::Vector*)&params[12];
			OutPointA = *(Object::Vector*)&params[24];
			OutPointB = *(Object::Vector*)&params[36];
			return *(PrimitiveComponent::GJKResult*)&params[48];
		}
		PrimitiveComponent::GJKResult ClosestPointOnComponentToComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& OtherComponent, Object::Vector& PointOnComponentA, Object::Vector& PointOnComponentB)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PrimitiveComponent.ClosestPointOnComponentToComponent");
			byte params[29] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = OtherComponent;
			*(Object::Vector*)&params[4] = PointOnComponentA;
			*(Object::Vector*)&params[16] = PointOnComponentB;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OtherComponent = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0];
			PointOnComponentA = *(Object::Vector*)&params[4];
			PointOnComponentB = *(Object::Vector*)&params[16];
			return *(PrimitiveComponent::GJKResult*)&params[28];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
