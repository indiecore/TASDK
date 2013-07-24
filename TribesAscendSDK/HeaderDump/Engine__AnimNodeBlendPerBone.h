#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeBlendPerBone." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendPerBone : public AnimNodeBlend
	{
	public:
		ADD_VAR(::BoolProperty, bForceLocalSpaceBlend, 0x1)
	};
}
#undef ADD_VAR
