#pragma once
#include "Engine__Brush.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Volume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Volume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Volume : public Brush
	{
	public:
		ADD_VAR(::BoolProperty, bProcessAllActors, 0x2)
		ADD_VAR(::BoolProperty, bForcePawnWalk, 0x1)
		ADD_OBJECT(Actor, AssociatedActor)
		// Here lies the not-yet-implemented method 'Encompasses'
		// Here lies the not-yet-implemented method 'EncompassesPoint'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'CollisionChanged'
		// Here lies the not-yet-implemented method 'ProcessActorSetVolume'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
