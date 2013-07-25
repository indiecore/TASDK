#pragma once
#include "Engine__CameraAnim.h"
#include "TribesGame__TrProjectile.h"
#include "Engine__SoundCue.h"
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Lacerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_Lacerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_Lacerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_Lacerator : public TrProjectile
	{
	public:
		ADD_OBJECT(CameraAnim, ShortRangeKillAnim)
		ADD_VAR(::BoolProperty, bShrinking, 0x2)
		ADD_VAR(::BoolProperty, bCheckShortRangeKill, 0x1)
		ADD_OBJECT(SoundCue, HitPawnSound)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialSoundEffect' for the property named 'DefaultHitSound'!
		ADD_OBJECT(ParticleSystem, RockSmokeTemplate)
		ADD_OBJECT(ParticleSystem, BounceTemplate)
		ADD_VAR(::FloatProperty, ShrinkTimer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageAttenuation, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Bounces, 0xFFFFFFFF)
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.InitProjectile");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(ScriptClass**)(params + 12) = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InternalSpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.InternalSpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDamage(class Actor* Other, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.GetDamage");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		float GetMomentumTransfer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.GetMomentumTransfer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SpawnImpactEffect(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.SpawnImpactEffect");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.HitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartToShrink()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.StartToShrink");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MyOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Lacerator.MyOnParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
