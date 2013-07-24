#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleTrailSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleTrailSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTrailSource : public ParticleModuleTrailBase
	{
	public:
		ADD_VAR(::IntProperty, SourceOffsetCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInheritRotation, 0x2)
		ADD_VAR(::BoolProperty, bLockSourceStength, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'SourceStrength'!
		ADD_VAR(::NameProperty, SourceName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SelectionMethod, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SourceMethod, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
