#pragma once
#include "Engine.MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " StaticMeshActorBasedOnExtremeContent.SMMaterialSetterDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty StaticMeshActorBasedOnExtremeContent.SMMaterialSetterDatum." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SMMaterialSetterDatum
	{
	public:
		ADD_OBJECT(MaterialInterface, TheMaterial)
		ADD_VAR(::IntProperty, MaterialIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
