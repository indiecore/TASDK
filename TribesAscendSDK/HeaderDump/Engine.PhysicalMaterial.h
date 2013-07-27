#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.PhysicalMaterialPropertyBase.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
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
	class PhysicalMaterial : public Object
	{
	public:
		enum EPhysEffectType : byte
		{
			EPMET_Impact = 0,
			EPMET_Slide = 1,
			EPMET_MAX = 2,
		};
		ADD_STRUCT(int, MaterialIndex, 60)
		ADD_OBJECT(SoundCue, FractureSoundSingle, 148)
		ADD_OBJECT(SoundCue, FractureSoundExplosion, 144)
		ADD_OBJECT(PhysicalMaterial, Parent, 152)
		ADD_OBJECT(PhysicalMaterialPropertyBase, PhysicalMaterialProperty, 156)
		ADD_STRUCT(float, Friction, 64)
		ADD_STRUCT(float, Restitution, 68)
		ADD_BOOL(bForceConeFriction, 72, 0x1)
		ADD_BOOL(bEnableAnisotropicFriction, 72, 0x2)
		ADD_STRUCT(Vector, AnisoFrictionDir, 76)
		ADD_STRUCT(float, FrictionV, 88)
		ADD_STRUCT(float, Density, 92)
		ADD_STRUCT(float, AngularDamping, 96)
		ADD_STRUCT(float, LinearDamping, 100)
		ADD_STRUCT(float, MagneticResponse, 104)
		ADD_STRUCT(float, WindResponse, 108)
		ADD_STRUCT(float, ImpactThreshold, 112)
		ADD_STRUCT(float, ImpactReFireDelay, 116)
		ADD_OBJECT(ParticleSystem, ImpactEffect, 120)
		ADD_OBJECT(SoundCue, ImpactSound, 124)
		ADD_STRUCT(float, SlideThreshold, 128)
		ADD_STRUCT(float, SlideReFireDelay, 132)
		ADD_OBJECT(ParticleSystem, SlideEffect, 136)
		ADD_OBJECT(SoundCue, SlideSound, 140)
		Actor::PhysEffectInfo FindPhysEffectInfo(PhysicalMaterial::EPhysEffectType Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16492);
			byte params[17] = { NULL };
			*(PhysicalMaterial::EPhysEffectType*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::PhysEffectInfo*)&params[4];
		}
		void FindFractureSounds(class SoundCue*& OutSoundExplosion, class SoundCue*& OutSoundSingle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24299);
			byte params[8] = { NULL };
			*(class SoundCue**)params = OutSoundExplosion;
			*(class SoundCue**)&params[4] = OutSoundSingle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutSoundExplosion = *(class SoundCue**)params;
			OutSoundSingle = *(class SoundCue**)&params[4];
		}
		class PhysicalMaterialPropertyBase* GetPhysicalMaterialProperty(ScriptClass* DesiredClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24306);
			byte params[8] = { NULL };
			*(ScriptClass**)params = DesiredClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicalMaterialPropertyBase**)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
