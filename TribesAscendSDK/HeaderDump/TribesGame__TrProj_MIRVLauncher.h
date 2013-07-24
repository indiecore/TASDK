#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_MIRVLauncher." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_MIRVLauncher : public TrProj_Grenade
	{
	public:
		ADD_VAR(::IntProperty, m_nSecondaryExplosions, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
