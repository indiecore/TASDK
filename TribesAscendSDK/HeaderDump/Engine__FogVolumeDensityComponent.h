#pragma once
#include "Engine__MaterialInterface.h"
#include "Engine__ActorComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FogVolumeDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FogVolumeDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FogVolumeDensityComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FogVolumeDensityComponent : public ActorComponent
	{
	public:
		ADD_VAR(::FloatProperty, StartDistance, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'ApproxFogLightColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'SimpleLightColor'!
		ADD_VAR(::BoolProperty, bOnlyAffectsTranslucency, 0x4)
		ADD_VAR(::BoolProperty, bAffectsTranslucency, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_OBJECT(MaterialInterface, DefaultFogVolumeMaterial)
		ADD_OBJECT(MaterialInterface, FogMaterial)
		// Here lies the not-yet-implemented method 'SetEnabled'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
