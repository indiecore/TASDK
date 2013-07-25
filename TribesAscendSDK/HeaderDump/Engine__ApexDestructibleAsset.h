#pragma once
#include "Engine__ApexAsset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexDestructibleAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ApexDestructibleAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ApexDestructibleAsset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ApexDestructibleAsset : public ApexAsset
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.ApexDestructibleAsset.NxDestructibleParameters' for the property named 'DestructibleParameters'!
		ADD_VAR(::StrProperty, DustEmitterName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CrumbleEmitterName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDynamic, 0x2)
		ADD_VAR(::BoolProperty, bHasUniqueAssetMaterialNames, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'MDestructibleThumbnailComponent'!
		ADD_OBJECT(PhysicalMaterial, DefaultPhysMaterial)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'MApexAsset'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
