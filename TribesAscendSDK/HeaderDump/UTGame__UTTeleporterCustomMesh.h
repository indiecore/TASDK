#pragma once
#include "Engine__Teleporter.h"
#include "Engine__SoundCue.h"
#include "UTGame__UTPawn.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeleporterCustomMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeleporterCustomMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeleporterCustomMesh : public Teleporter
	{
	public:
		ADD_VAR(::FloatProperty, LastTime, 0xFFFFFFFF)
		ADD_OBJECT(UTPawn, LastPawn)
		ADD_OBJECT(SoundCue, TeleportingSound)
		// Here lies the not-yet-implemented method 'Accept'
		// Here lies the not-yet-implemented method 'Touch'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
