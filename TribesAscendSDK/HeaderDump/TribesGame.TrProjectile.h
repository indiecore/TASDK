#pragma once
#include "UTGame.UTProjectile.h"
#include "TribesGame.TrObject.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "UDKBase.UDKPawn.h"
#include "TribesGame.TrDevice.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.SoundCue.h"
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
	class TrProjectile : public UTProjectile
	{
	public:
		ADD_BOOL(m_bTether, 684, 0x40)
		ADD_BOOL(m_bSimulateAutonomousProjectiles, 684, 0x80)
		ADD_STRUCT(TrObject::TR_EQUIP_POINT, m_SpawnedEquipPoint, 756)
		ADD_STRUCT(int, r_nTetherId, 736)
		ADD_BOOL(m_bIsBullet, 684, 0x100)
		ADD_STRUCT(Vector, r_vSpawnLocation, 776)
		ADD_STRUCT(float, m_fInstigatorExtraZMomentum, 732)
		ADD_STRUCT(ScriptArray<UDKPawn::MaterialImpactEffect>, ImpactEffects, 788)
		ADD_OBJECT(TrDevice, SpawnedFromDevice, 812)
		ADD_STRUCT(float, m_fAlwaysRelevantDistanceSquared, 808)
		ADD_STRUCT(float, m_fMinLifespan, 804)
		ADD_STRUCT(float, m_fMaxLifespan, 800)
		ADD_STRUCT(Vector, m_vAccelDirection, 764)
		ADD_STRUCT(float, m_fClientSimulatedSpeed, 760)
		ADD_STRUCT(float, m_fTweenSpeed, 752)
		ADD_STRUCT(float, m_fCurrentTetherTweenAmount, 748)
		ADD_OBJECT(TrProjectile, c_ChildTetheredProjectile, 744)
		ADD_OBJECT(TrProjectile, c_ParentTetheredProjectile, 740)
		ADD_STRUCT(float, m_fInstigatorMomentumTransferMultiplier, 728)
		ADD_STRUCT(float, m_fAmbientSoundFadeOut, 724)
		ADD_STRUCT(float, m_fAmbientSoundFadeIn, 720)
		ADD_STRUCT(float, m_fDirectHitMultiplier, 716)
		ADD_STRUCT(float, m_fBounceDampingPercent, 712)
		ADD_STRUCT(int, m_nPerPlayerMaxDeployed, 708)
		ADD_STRUCT(float, m_fMaxProjInheritPct, 700)
		ADD_STRUCT(float, m_fProjInheritVelocityPctZ, 696)
		ADD_STRUCT(float, m_fProjInheritVelocityPct, 692)
		ADD_STRUCT(float, m_fXYDamageRadius, 688)
		ADD_BOOL(m_bAuthoritativeExploding, 684, 0x20)
		ADD_BOOL(m_bOrientToWall, 684, 0x10)
		ADD_BOOL(m_bHasBounced, 684, 0x8)
		ADD_BOOL(m_bFastProjectile, 684, 0x4)
		ADD_BOOL(m_bDebugProjectileRadius, 684, 0x2)
		ADD_BOOL(m_bLimitXYDamageCheck, 684, 0x1)
		ADD_OBJECT(ScriptClass, m_SpawnedDeployableClass, 680)
		bool IsBlockedByBlocker(class Actor* DamageInstigator, class Actor* Target, class Actor* OriginActor, bool CheckWorldGeometry, Vector AltOriginLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71790);
			byte params[32] = { NULL };
			*(class Actor**)params = DamageInstigator;
			*(class Actor**)&params[4] = Target;
			*(class Actor**)&params[8] = OriginActor;
			*(bool*)&params[12] = CheckWorldGeometry;
			*(Vector*)&params[16] = AltOriginLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void OrientToSlope(Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107650);
			byte params[12] = { NULL };
			*(Vector*)params = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector CalculateHitLocation(class Actor* shooter, Vector ShotDirection, Vector ShotLocation, float ClampedMaxSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107652);
			byte params[44] = { NULL };
			*(class Actor**)params = shooter;
			*(Vector*)&params[4] = ShotDirection;
			*(Vector*)&params[16] = ShotLocation;
			*(float*)&params[28] = ClampedMaxSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[32];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107658);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107660);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExplodeFromTimeLimit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107662);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107663);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReceivedProjectileToTether()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107667);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateProjectileLight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107673);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetonateObsolete(bool bDetonateFromAOE)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107674);
			byte params[4] = { NULL };
			*(bool*)params = bDetonateFromAOE;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyOldestOverLimit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107676);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetMaxDeployedLimit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107683);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void Init(Vector Direction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107689);
			byte params[12] = { NULL };
			*(Vector*)params = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107691);
			byte params[16] = { NULL };
			*(Vector*)params = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyInheritance(Vector ProjectileDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107694);
			byte params[12] = { NULL };
			*(Vector*)params = ProjectileDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientCheckFastSpawnExplode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107698);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnExplosionEffects(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107702);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetExplosionSound(class PhysicalMaterial* HitMaterial, class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107716);
			byte params[12] = { NULL };
			*(class PhysicalMaterial**)params = HitMaterial;
			*(class Actor**)&params[4] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[8];
		}
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107724);
			byte params[24] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107727);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Bounce(class Actor* Other, Vector WallNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107729);
			byte params[16] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ProjectileHurtRadius(Vector HurtOrigin, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107732);
			byte params[28] = { NULL };
			*(Vector*)params = HurtOrigin;
			*(Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HurtRadius_Internal(float DamageAmount, float InDamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, Vector AltHurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107741);
			byte params[56] = { NULL };
			*(float*)params = DamageAmount;
			*(float*)&params[4] = InDamageRadius;
			*(ScriptClass**)&params[8] = DamageType;
			*(float*)&params[12] = Momentum;
			*(Vector*)&params[16] = HurtOrigin;
			*(Vector*)&params[28] = AltHurtOrigin;
			*(class Actor**)&params[40] = IgnoredActor;
			*(class Controller**)&params[44] = InstigatedByController;
			*(bool*)&params[48] = bDoFullDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[52];
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107763);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107773);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107778);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
