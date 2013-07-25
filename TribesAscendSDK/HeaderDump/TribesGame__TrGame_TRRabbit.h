#pragma once
#include "TribesGame__TrGame.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TRRabbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRRabbit." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRRabbit : public TrGame
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, m_HolderPRI)
		ADD_OBJECT(PlayerReplicationInfo, m_Leader)
		ADD_VAR(::FloatProperty, m_fScoreInterval, 0xFFFFFFFF)
		ADD_OBJECT(TrFlagRabbit, m_Flag)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
