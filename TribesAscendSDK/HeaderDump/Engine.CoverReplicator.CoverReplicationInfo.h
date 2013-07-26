#pragma once
#include "Engine.CoverLink.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty CoverReplicator.CoverReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CoverReplicationInfo
	{
	public:
		ADD_OBJECT(CoverLink, Link)
	};
}
#undef ADD_OBJECT
