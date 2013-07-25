#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__LensFlare.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LensFlareSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LensFlareSource : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bCurrentlyActive, 0x1)
		// Here lies the not-yet-implemented method 'SetTemplate'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'SetFloatParameter'
		// Here lies the not-yet-implemented method 'SetVectorParameter'
		// Here lies the not-yet-implemented method 'SetColorParameter'
		// Here lies the not-yet-implemented method 'SetExtColorParameter'
		// Here lies the not-yet-implemented method 'SetActorParameter'
	};
}
#undef ADD_VAR
