#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCollisionProxy_Flag." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCollisionProxy_Flag : public TrCollisionProxy
	{
	public:
		ADD_VAR(::IntProperty, m_nFlagReachLevel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
