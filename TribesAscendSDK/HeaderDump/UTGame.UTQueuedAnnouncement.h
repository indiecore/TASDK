#pragma once
#include "Engine.Info.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTQueuedAnnouncement : public Info
	{
	public:
		ADD_OBJECT(UTQueuedAnnouncement, nextAnnouncement, 476)
		ADD_OBJECT(ScriptClass, AnnouncementClass, 480)
		ADD_STRUCT(int, MessageIndex, 484)
		ADD_OBJECT(PlayerReplicationInfo, PRI, 488)
		ADD_OBJECT(Object, OptionalObject, 492)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
