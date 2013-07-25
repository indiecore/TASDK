#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrQueueManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrQueueManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrQueueManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bQueued, 0x1)
		ADD_VAR(::BoolProperty, bJoiningCustom, 0x4)
		ADD_VAR(::StrProperty, QueueFriend, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFilterOwner, 0x8)
		ADD_VAR(::IntProperty, GameTypeId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ServerIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MapSlots, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeedPassword, 0x2)
		ADD_OBJECT(GFxTrMenuMoviePlayer, TrOuter)
		ADD_OBJECT(OnlineGameInterfaceMcts, OnlineGameMcts)
		ADD_VAR(::BoolProperty, bFavoriteSort, 0x1000)
		ADD_VAR(::BoolProperty, bPasswordSort, 0x800)
		ADD_VAR(::BoolProperty, bSlotsSort, 0x400)
		ADD_VAR(::BoolProperty, bRangeSort, 0x200)
		ADD_VAR(::BoolProperty, bRulesSort, 0x100)
		ADD_VAR(::BoolProperty, bTypeSort, 0x80)
		ADD_VAR(::BoolProperty, bPingSort, 0x40)
		ADD_VAR(::BoolProperty, bNameSort, 0x20)
		ADD_VAR(::BoolProperty, bMapSort, 0x10)
		ADD_VAR(::IntProperty, PasswordQueue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PasswordIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ProfileIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, queueId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
