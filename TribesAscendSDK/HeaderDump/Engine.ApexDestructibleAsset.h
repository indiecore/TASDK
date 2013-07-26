#pragma once
#include "Engine.ApexAsset.h"
#include "Engine.ApexDestructibleAsset.NxDestructibleParameters.h"
#include "Core.Object.Pointer.h"
#include "Engine.PhysicalMaterial.h"
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
		ADD_STRUCT(::NonArithmeticProperty<NxDestructibleParameters>, DestructibleParameters, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DustEmitterName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CrumbleEmitterName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDynamic, 0x2)
		ADD_VAR(::BoolProperty, bHasUniqueAssetMaterialNames, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, MDestructibleThumbnailComponent, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysMaterial)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, MApexAsset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
