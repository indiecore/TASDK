#pragma once
#include "Engine__PhysicalMaterialPropertyBase.h"
#include "Engine__SoundCue.h"
#include "Core__Object.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PhysicalMaterial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PhysicalMaterial." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PhysicalMaterial." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PhysicalMaterial : public Object
	{
	public:
		ADD_VAR(::IntProperty, MaterialIndex, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, FractureSoundSingle)
		ADD_OBJECT(SoundCue, FractureSoundExplosion)
		ADD_OBJECT(PhysicalMaterial, Parent)
		ADD_OBJECT(PhysicalMaterialPropertyBase, PhysicalMaterialProperty)
		ADD_VAR(::FloatProperty, Friction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Restitution, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceConeFriction, 0x1)
		ADD_VAR(::BoolProperty, bEnableAnisotropicFriction, 0x2)
		ADD_STRUCT(::VectorProperty, AnisoFrictionDir, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, FrictionV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Density, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngularDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MagneticResponse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WindResponse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpactThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpactReFireDelay, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, ImpactEffect)
		ADD_OBJECT(SoundCue, ImpactSound)
		ADD_VAR(::FloatProperty, SlideThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlideReFireDelay, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, SlideEffect)
		ADD_OBJECT(SoundCue, SlideSound)
		
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.PhysEffectInfo'!
void* FindPhysEffectInfo(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicalMaterial.FindPhysEffectInfo");
			byte* params = (byte*)malloc(17);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.PhysEffectInfo'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void FindFractureSounds(class SoundCue*& OutSoundExplosion, class SoundCue*& OutSoundSingle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicalMaterial.FindFractureSounds");
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = OutSoundExplosion;
			*(class SoundCue**)(params + 4) = OutSoundSingle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutSoundExplosion = *(class SoundCue**)params;
			OutSoundSingle = *(class SoundCue**)(params + 4);
			free(params);
		}
		class PhysicalMaterialPropertyBase* GetPhysicalMaterialProperty(ScriptClass* DesiredClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicalMaterial.GetPhysicalMaterialProperty");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = DesiredClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PhysicalMaterialPropertyBase**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
