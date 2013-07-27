#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SoundCue.h"
#include "Engine.MaterialInstanceTimeVarying.h"
#include "Engine.HUD.h"
#include "Engine.MaterialInstance.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.StaticMesh.h"
#include "Engine.PlayerController.h"
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
	class UTGib : public Actor
	{
	public:
		class StaticMeshDatum
		{
		public:
			ADD_BOOL(bUseSecondaryGibMeshMITV, 16, 0x1)
			ADD_STRUCT(float, DrawScale, 12)
			ADD_OBJECT(PhysicsAsset, ThePhysAsset, 8)
			ADD_OBJECT(SkeletalMesh, TheSkelMesh, 4)
			ADD_OBJECT(StaticMesh, TheStaticMesh, 0)
		};
		ADD_STRUCT(ScriptName, DecalDissolveParamName, 500)
		ADD_STRUCT(float, DecalWaitTimeBeforeDissolve, 508)
		ADD_BOOL(bUseUnrealPhysics, 540, 0x1)
		ADD_STRUCT(ScriptArray<UTGib::StaticMeshDatum>, GibMeshesData, 544)
		ADD_STRUCT(Object::Rotator, OldCamRot, 568)
		ADD_STRUCT(Object::Vector, OldCamLoc, 556)
		ADD_BOOL(bStopMovingCamera, 540, 0x2)
		ADD_OBJECT(ParticleSystem, PS_CustomEffect, 536)
		ADD_STRUCT(float, GibMeshWaitTimeBeforeDissolve, 528)
		ADD_STRUCT(ScriptName, GibMeshDissolveParamName, 520)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV_GibMeshTemplateSecondary, 516)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV_GibMeshTemplate, 512)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV_DecalTemplate, 496)
		ADD_OBJECT(MaterialInstance, MI_Decal, 492)
		ADD_OBJECT(MaterialInstanceConstant, MIC_Gib, 488)
		ADD_OBJECT(SoundCue, HitSound, 480)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTexturesToBeResident(float TimeToBeResident)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.SetTexturesToBeResident");
			byte params[4] = { NULL };
			*(float*)&params[0] = TimeToBeResident;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void SetGibStaticMesh(class StaticMesh* NewStaticMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.SetGibStaticMesh");
			byte params[4] = { NULL };
			*(class StaticMesh**)&params[0] = NewStaticMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChooseGib()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.ChooseGib");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoCustomGibEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.DoCustomGibEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.BecomeViewTarget");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcCamera(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.CalcCamera");
			byte params[36] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.RigidBodyCollision");
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComponent;
			*(Actor::CollisionImpactData*)&params[8] = RigidCollisionData;
			*(int*)&params[44] = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RigidCollisionData = *(Actor::CollisionImpactData*)&params[8];
		}
		void LeaveADecal(Object::Vector HitLoc, Object::Vector HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.LeaveADecal");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLoc;
			*(Object::Vector*)&params[12] = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TurnOnCollision()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.TurnOnCollision");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HitWall(Object::Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.HitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
