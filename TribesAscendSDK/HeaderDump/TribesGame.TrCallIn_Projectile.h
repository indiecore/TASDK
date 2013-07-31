#pragma once
#include "TribesGame.TrCallIn.h"
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SoundCue.h"
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
	class TrCallIn_Projectile : public TrCallIn
	{
	public:
		ADD_STRUCT(Vector, m_SavedTargetNormal, 588)
		ADD_STRUCT(Vector, m_SavedTargetLocation, 576)
		ADD_STRUCT(int, m_FiredProjectiles, 572)
		ADD_OBJECT(ParticleSystem, TargetParticleSystem, 568)
		ADD_OBJECT(SoundCue, TargetParticleSound, 564)
		ADD_OBJECT(SoundCue, AreaWarningSound, 560)
		ADD_STRUCT(int, NumberOfProjectiles, 556)
		ADD_STRUCT(float, FireTimeLength, 552)
		ADD_STRUCT(float, CallRadius, 548)
		ADD_OBJECT(ScriptClass, ProjectileFireClass, 544)
		bool FireCompletedCallIn(int CallInOffs, Vector TargetLocation, Vector TargetNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74081);
			byte params[32] = { NULL };
			*(int*)params = CallInOffs;
			*(Vector*)&params[4] = TargetLocation;
			*(Vector*)&params[16] = TargetNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void FireProjectile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74089);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
