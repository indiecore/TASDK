#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleBeamSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleBeamSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleBeamSource : public ParticleModuleBeamBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'SourceStrength'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'SourceTangent'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'Source'!
		ADD_VAR(::BoolProperty, bLockSourceStength, 0x8)
		ADD_VAR(::BoolProperty, bLockSourceTangent, 0x4)
		ADD_VAR(::BoolProperty, bLockSource, 0x2)
		ADD_VAR(::BoolProperty, bSourceAbsolute, 0x1)
		ADD_VAR(::NameProperty, SourceName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SourceTangentMethod, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SourceMethod, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
