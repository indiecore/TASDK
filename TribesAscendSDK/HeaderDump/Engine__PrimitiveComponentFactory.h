#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PrimitiveComponentFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PrimitiveComponentFactory : public Object
	{
	public:
		ADD_VAR(::BoolProperty, CastShadow, 0x80)
		ADD_VAR(::BoolProperty, HiddenEditor, 0x40)
		ADD_VAR(::BoolProperty, HiddenGame, 0x20)
		ADD_VAR(::BoolProperty, BlockRigidBody, 0x10)
		ADD_VAR(::BoolProperty, BlockNonZeroExtent, 0x8)
		ADD_VAR(::BoolProperty, BlockZeroExtent, 0x4)
		ADD_VAR(::BoolProperty, BlockActors, 0x2)
		ADD_VAR(::BoolProperty, CollideActors, 0x1)
	};
}
#undef ADD_VAR
