#pragma once
#include "TribesGame__TrProjectile.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrMineCollisionProxy.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "Engine__Texture2D.h"
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Mine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_Mine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_Mine : public TrProjectile
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, r_OwnerPRI)
		ADD_VAR(::IntProperty, m_nIconStackId, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_VAR(::IntProperty, m_nMarkerOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShowHeaderUntil, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sScreenName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumBouncesBeforeDetonateObsolete, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumBounces, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxFloorZ, 0xFFFFFFFF)
		ADD_OBJECT(TrMineCollisionProxy, m_CollisionProxy)
		ADD_VAR(::FloatProperty, m_fDetonationHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDetonationRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeploySeconds, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsPostRendered, 0x10)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x8)
		ADD_VAR(::BoolProperty, m_bDrawOwnerName, 0x4)
		ADD_VAR(::BoolProperty, m_bUsesDetonationProxy, 0x2)
		ADD_VAR(::BoolProperty, m_bArmed, 0x1)
		ADD_OBJECT(SoundCue, WallImpactSound)
		bool IsAliveAndWell()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.IsAliveAndWell");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPRIReplicated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.OnPRIReplicated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ArmedTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.ArmedTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.HitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeRadiusDamage(class Controller* EventInstigator, float BaseDamage, float InDamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.TakeRadiusDamage");
			byte* params = (byte*)malloc(44);
			*(class Controller**)params = EventInstigator;
			*(float*)(params + 4) = BaseDamage;
			*(float*)(params + 8) = InDamageRadius;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HurtOrigin;
			*(bool*)(params + 32) = bFullDamage;
			*(class Actor**)(params + 36) = DamageCauser;
			*(float*)(params + 40) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitProjectile(Vector Direction, ScriptClass* ClassToInherit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.InitProjectile");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Direction;
			*(ScriptClass**)(params + 12) = ClassToInherit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnEnteredDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.PawnEnteredDetonationArea");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool MeetsDetonationRequirements(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.MeetsDetonationRequirements");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PawnLeftDetonationArea(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.PawnLeftDetonationArea");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NativeExplode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.NativeExplode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.ProcessTouch");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitLocation;
			*(Vector*)(params + 16) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Bounce(class Actor* Other, Vector WallNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.Bounce");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Mine.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
