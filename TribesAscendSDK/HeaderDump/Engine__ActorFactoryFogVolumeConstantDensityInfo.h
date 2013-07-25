#pragma once
#include "Engine__ActorFactory.h"
#include "Engine__MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorFactoryFogVolumeConstantDensityInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryFogVolumeConstantDensityInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryFogVolumeConstantDensityInfo : public ActorFactory
	{
	public:
		ADD_VAR(::BoolProperty, bNothingSelected, 0x1)
		ADD_OBJECT(MaterialInterface, SelectedMaterial)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
