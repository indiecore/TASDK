#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SpeedTree." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SpeedTree." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SpeedTree." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SpeedTree : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'LightingGuid'!
		ADD_STRUCT(::VectorProperty, WindDirection, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WindStrength, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, BillboardMaterial)
		ADD_OBJECT(MaterialInterface, LeafMeshMaterial)
		ADD_OBJECT(MaterialInterface, LeafCardMaterial)
		ADD_OBJECT(MaterialInterface, FrondMaterial)
		ADD_OBJECT(MaterialInterface, Branch2Material)
		ADD_OBJECT(MaterialInterface, Branch1Material)
		ADD_VAR(::FloatProperty, LeafStaticShadowOpacity, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SRH'!
		ADD_VAR(::BoolProperty, bLegacySpeedTree, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
