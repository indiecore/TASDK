#pragma once
#include "TribesGame.TrPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrPlayerController.PendingSkin." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrPlayerController.PendingSkin." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PendingSkin
	{
	public:
		ADD_VAR(::IntProperty, skinId, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerReplicationInfo, TrPRI)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
