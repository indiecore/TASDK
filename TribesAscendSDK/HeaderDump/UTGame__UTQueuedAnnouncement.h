#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTQueuedAnnouncement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTQueuedAnnouncement." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTQueuedAnnouncement : public Info
	{
	public:
		ADD_OBJECT(UTQueuedAnnouncement, nextAnnouncement)
		ADD_VAR(::IntProperty, MessageIndex, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, PRI)
		ADD_OBJECT(Object, OptionalObject)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
