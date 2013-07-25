#pragma once
#include "Engine__SoundCue.h"
#include "Core__Object.h"
#include "Engine__ParticleSystem.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FractureMaterial." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FractureMaterial : public Object
	{
	public:
		ADD_OBJECT(SoundCue, FractureSound)
		ADD_OBJECT(ParticleSystem, FractureEffect)
	};
}
#undef ADD_OBJECT
