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
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ActorFactory.PostCreateActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
