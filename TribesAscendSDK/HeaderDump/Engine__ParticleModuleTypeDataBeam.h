#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleTypeDataBeam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleTypeDataBeam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTypeDataBeam : public ParticleModuleTypeDataBase
	{
	public:
		ADD_VAR(::BoolProperty, RenderTessellation, 0x8)
		ADD_VAR(::BoolProperty, RenderLines, 0x4)
		ADD_VAR(::BoolProperty, RenderDirectLine, 0x2)
		ADD_VAR(::BoolProperty, RenderGeometry, 0x1)
		ADD_VAR(::IntProperty, TextureTile, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'EndPointDirection'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'TargetStrength'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'EmitterStrength'!
		ADD_VAR(::IntProperty, TessellationFactor, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'EndPoint'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Distance'!
		ADD_VAR(::ByteProperty, EndPointMethod, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BeamMethod, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
