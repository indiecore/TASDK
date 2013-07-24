#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_RemoteArxBuster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_RemoteArxBuster : public TrProj_StickyGrenade
	{
	public:
		ADD_VAR(::BoolProperty, m_bIsDetonating, 0x1)
	};
}
#undef ADD_VAR
