#pragma once
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.Rotator.h"
#include "Engine.HUD.h"
#include "Engine.MaterialInstance.h"
#include "Core.Object.Vector.h"
#include "Engine.SoundCue.h"
#include "Engine.MaterialInstanceTimeVarying.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.StaticMesh.h"
#include "Engine.PlayerController.h"
#include "Engine.Actor.CollisionImpactData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGib." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTGib." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGib." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGib : public Actor
	{
	public:
		ADD_VAR(::NameProperty, DecalDissolveParamName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalWaitTimeBeforeDissolve, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseUnrealPhysics, 0x1)
		ADD_STRUCT(::RotatorProperty, OldCamRot, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OldCamLoc, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStopMovingCamera, 0x2)
		ADD_OBJECT(ParticleSystem, PS_CustomEffect)
		ADD_VAR(::FloatProperty, GibMeshWaitTimeBeforeDissolve, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, GibMeshDissolveParamName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV_GibMeshTemplateSecondary)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV_GibMeshTemplate)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV_DecalTemplate)
		ADD_OBJECT(MaterialInstance, MI_Decal)
		ADD_OBJECT(MaterialInstanceConstant, MIC_Gib)
		ADD_OBJECT(SoundCue, HitSound)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTexturesToBeResident(float TimeToBeResident)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.SetTexturesToBeResident");
			byte* params = (byte*)malloc(4);
			*(float*)params = TimeToBeResident;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void SetGibStaticMesh(class StaticMesh* NewStaticMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.SetGibStaticMesh");
			byte* params = (byte*)malloc(4);
			*(class StaticMesh**)params = NewStaticMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.CalcCamera");
			byte* params = (byte*)malloc(36);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.RigidBodyCollision");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComponent;
			*(CollisionImpactData*)(params + 8) = RigidCollisionData;
			*(int*)(params + 44) = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			RigidCollisionData = *(CollisionImpactData*)(params + 8);
			free(params);
		}
		void LeaveADecal(Vector HitLoc, Vector HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.LeaveADecal");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLoc;
			*(Vector*)(params + 12) = HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TurnOnCollision()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.TurnOnCollision");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib.HitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
