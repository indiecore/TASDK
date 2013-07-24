#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ChangeCollision." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ChangeCollision : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bCollideActors, 0x1)
		ADD_VAR(::BoolProperty, bBlockActors, 0x2)
		ADD_VAR(::BoolProperty, bIgnoreEncroachers, 0x4)
		ADD_VAR(::ByteProperty, CollisionType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
