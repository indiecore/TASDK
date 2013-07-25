#pragma once
#include "Core__Object.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactory : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bShowInEditorQuickMenu, 0x2)
		ADD_VAR(::BoolProperty, bPlaceable, 0x1)
		ADD_OBJECT(ScriptClass, NewActorClass)
		ADD_VAR(::IntProperty, AlternateMenuPriority, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MenuPriority, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MenuName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, GameplayActorClass)
		// Here lies the not-yet-implemented method 'PostCreateActor'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
