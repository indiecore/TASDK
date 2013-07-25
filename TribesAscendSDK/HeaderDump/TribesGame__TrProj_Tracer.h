#pragma once
#include "TribesGame__TrProjectile.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Tracer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_Tracer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_Tracer : public TrProjectile
	{
	public:
		ADD_STRUCT(::VectorProperty, m_vTracerDrawScale3D, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vInitialFrameOfRefVelocity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vDestinationLoc, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fMeshScaleDownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bScalingDown, 0x2)
		ADD_VAR(::BoolProperty, m_bScaledUp, 0x1)
		ADD_VAR(::FloatProperty, m_fMeshScaleUpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccelRate, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'CalcTracerAccel'
		// Here lies the not-yet-implemented method 'InitTracer'
		// Here lies the not-yet-implemented method 'KillProjectile'
		// Here lies the not-yet-implemented method 'ScaleDownFinishedNotify'
		// Here lies the not-yet-implemented method 'ScaleUpFinishedNotify'
		// Here lies the not-yet-implemented method 'OutsideWorldBounds'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'Recycle'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'WakeProjectile'
		// Here lies the not-yet-implemented method 'ProcessTouch'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
