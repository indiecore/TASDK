#pragma once
#include "Engine.MorphNodeWeight.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.FDamageMorphTargets." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKVehicle.FDamageMorphTargets." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FDamageMorphTargets
	{
	public:
		ADD_VAR(::IntProperty, Health, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InfluenceBone, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LinkedMorphNodeIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LinkedMorphNodeName, 0xFFFFFFFF)
		ADD_OBJECT(MorphNodeWeight, MorphNode)
		ADD_VAR(::NameProperty, MorphNodeName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
