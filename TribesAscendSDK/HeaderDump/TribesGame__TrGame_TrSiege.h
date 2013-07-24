#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrSiege." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrSiege : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_CurrentPhase, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasCoreDestroyedInRoundOne, 0x1)
		ADD_VAR(::FloatProperty, m_bRoundOneTimeSecs, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
