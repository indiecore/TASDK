#pragma once
#include "Engine__PlayerController.h"
#include "Engine__Player.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DebugCameraController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DebugCameraController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DebugCameraController : public PlayerController
	{
	public:
		ADD_OBJECT(Player, OryginalPlayer)
		ADD_OBJECT(PlayerController, OryginalControllerRef)
		ADD_OBJECT(Actor, SelectedActor)
		ADD_VAR(::BoolProperty, bIsFrozenRendering, 0x2)
		ADD_VAR(::BoolProperty, bShowSelectedInfo, 0x1)
		ADD_VAR(::NameProperty, UnselectKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SecondaryKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PrimaryKey, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PrimarySelect'
		// Here lies the not-yet-implemented method 'SecondarySelect'
		// Here lies the not-yet-implemented method 'Unselect'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'OnActivate'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'OnDeactivate'
		// Here lies the not-yet-implemented method 'DisableDebugCamera'
		// Here lies the not-yet-implemented method 'NativeInputKey'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
