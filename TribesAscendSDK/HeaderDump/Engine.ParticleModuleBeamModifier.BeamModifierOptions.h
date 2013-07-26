#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModuleBeamModifier.BeamModifierOptions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BeamModifierOptions
	{
	public:
		ADD_VAR(::BoolProperty, Block, 0x4)
		ADD_VAR(::BoolProperty, bScale, 0x2)
		ADD_VAR(::BoolProperty, bModify, 0x1)
	};
}
#undef ADD_VAR
