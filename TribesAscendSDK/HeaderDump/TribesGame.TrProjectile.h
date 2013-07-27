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
		ADD_STRUCT(Object::Vector, r_vSpawnLocation, 776)
		ADD_STRUCT(float, m_fInstigatorExtraZMomentum, 732)
		ADD_STRUCT(ScriptArray<UDKPawn::MaterialImpactEffect>, ImpactEffects, 788)
		ADD_OBJECT(TrDevice, SpawnedFromDevice, 812)
		ADD_STRUCT(float, m_fAlwaysRelevantDistanceSquared, 808)
		ADD_STRUCT(float, m_fMinLifespan, 804)
		ADD_STRUCT(float, m_fMaxLifespan, 800)
		ADD_STRUCT(Object::Vector, m_vAccelDirection, 764)
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
		bool IsBlockedByBlocker(class Actor* DamageInstigator, class Actor* Target, class Actor* OriginActor, bool CheckWorldGeometry, Object::Vector AltOriginLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.IsBlockedByBlocker");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = DamageInstigator;
			*(class Actor**)&params[4] = Target;
			*(class Actor**)&params[8] = OriginActor;
			*(bool*)&params[12] = CheckWorldGeometry;
			*(Object::Vector*)&params[16] = AltOriginLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void OrientToSlope(Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.OrientToSlope");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector CalculateHitLocation(class Actor* shooter, Object::Vector ShotDirection, Object::Vector ShotLocation, float ClampedMaxSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.CalculateHitLocation");
			byte params[44] = { NULL };
			*(class Actor**)&params[0] = shooter;
			*(Object::Vector*)&params[4] = ShotDirection;
			*(Object::Vector*)&params[16] = ShotLocation;
			*(float*)&params[28] = ClampedMaxSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[32];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExplodeFromTimeLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ExplodeFromTimeLimit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReceivedProjectileToTether()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ClientReceivedProjectileToTether");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateProjectileLight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.CreateProjectileLight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetonateObsolete(bool bDetonateFromAOE)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.DetonateObsolete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDetonateFromAOE;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyOldestOverLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.DestroyOldestOverLimit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetMaxDeployedLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.GetMaxDeployedLimit");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void Init(Object::Vector Direction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.Init");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitProjectile(Object::Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.InitProjectile");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Direction;
			*(ScriptClass**)&params[12] = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyInheritance(Object::Vector ProjectileDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ApplyInheritance");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = ProjectileDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientCheckFastSpawnExplode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ClientCheckFastSpawnExplode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnExplosionEffects(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.SpawnExplosionEffects");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundCue* GetExplosionSound(class PhysicalMaterial* HitMaterial, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.GetExplosionSound");
			byte params[12] = { NULL };
			*(class PhysicalMaterial**)&params[0] = HitMaterial;
			*(class Actor**)&params[4] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[8];
		}
		void Explode(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.Explode");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Bounce(class Actor* Other, Object::Vector WallNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.Bounce");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ProjectileHurtRadius(Object::Vector HurtOrigin, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ProjectileHurtRadius");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = HurtOrigin;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool HurtRadius_Internal(float DamageAmount, float InDamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, Object::Vector AltHurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.HurtRadius_Internal");
			byte params[56] = { NULL };
			*(float*)&params[0] = DamageAmount;
			*(float*)&params[4] = InDamageRadius;
			*(ScriptClass**)&params[8] = DamageType;
			*(float*)&params[12] = Momentum;
			*(Object::Vector*)&params[16] = HurtOrigin;
			*(Object::Vector*)&params[28] = AltHurtOrigin;
			*(class Actor**)&params[40] = IgnoredActor;
			*(class Controller**)&params[44] = InstigatedByController;
			*(bool*)&params[48] = bDoFullDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[52];
		}
		void HitWall(Object::Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.HitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProjectile.ProcessTouch");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
