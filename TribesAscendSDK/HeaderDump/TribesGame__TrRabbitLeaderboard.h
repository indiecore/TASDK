#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRabbitLeaderboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrRabbitLeaderboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRabbitLeaderboard." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRabbitLeaderboard : public Object
	{
	public:
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::BoolProperty, bIsActive, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrRabbitLeaderboard.LeaderboardSlot' for the property named 'LeaderboardSlots'!
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_VAR(::BoolProperty, bInitialized, 0x2)
		ADD_VAR(::BoolProperty, bUpdated, 0x1)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevSlots, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
