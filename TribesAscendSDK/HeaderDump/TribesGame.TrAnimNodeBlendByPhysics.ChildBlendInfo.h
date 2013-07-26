#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrAnimNodeBlendByPhysics.ChildBlendInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ChildBlendInfo
	{
	public:
		ADD_VAR(::FloatProperty, m_fBlendTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_PhysicsState, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
