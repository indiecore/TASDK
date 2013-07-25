#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "Engine__StaticMesh.h"
#include "Engine__MaterialInstanceTimeVarying.h"
#include "Engine__HUD.h"
#include "Engine__MaterialInstance.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__SoundCue.h"
#include "Engine__PlayerController.h"
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
		ADD_STRUCT(::RotatorProperty, OldCamRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, OldCamLoc, 0xFFFFFFFF
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
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'SetTexturesToBeResident'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'SetGibStaticMesh'
		// Here lies the not-yet-implemented method 'ChooseGib'
		// Here lies the not-yet-implemented method 'DoCustomGibEffects'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'BecomeViewTarget'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'RigidBodyCollision'
		// Here lies the not-yet-implemented method 'LeaveADecal'
		// Here lies the not-yet-implemented method 'TurnOnCollision'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'HitWall'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
