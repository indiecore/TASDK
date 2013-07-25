#pragma once
#include "Engine__SceneCapturePortalActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PortalTeleporter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PortalTeleporter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PortalTeleporter : public SceneCapturePortalActor
	{
	public:
		ADD_VAR(::BoolProperty, bCanTeleportVehicles, 0x4)
		ADD_VAR(::BoolProperty, bAlwaysTeleportNonPawns, 0x2)
		ADD_VAR(::BoolProperty, bMovablePortal, 0x1)
		ADD_OBJECT(PortalMarker, MyMarker)
		ADD_VAR(::IntProperty, TextureResolutionY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TextureResolutionX, 0xFFFFFFFF)
		ADD_OBJECT(PortalTeleporter, SisterPortal)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
