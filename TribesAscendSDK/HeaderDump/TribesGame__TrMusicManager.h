#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrMusicManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrMusicManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMusicManager : public Info
	{
	public:
		ADD_OBJECT(TrPlayerController, m_PlayerOwner)
		ADD_VAR(::FloatProperty, m_fMusicVolume, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CurrentState, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_PendingState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStingerVolumeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_CTFTeamScores, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
