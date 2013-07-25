#pragma once
#include "Engine__Teleporter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKTeleporterBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKTeleporterBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKTeleporterBase : public Teleporter
	{
	public:
		ADD_OBJECT(SoundCue, TeleportingSound)
		ADD_VAR(::NameProperty, PortalTextureParameter, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, PortalMaterialInstance)
		ADD_OBJECT(MaterialInterface, PortalMaterial)
		ADD_OBJECT(Actor, PortalViewTarget)
		ADD_VAR(::IntProperty, TextureResolutionY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TextureResolutionX, 0xFFFFFFFF)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
