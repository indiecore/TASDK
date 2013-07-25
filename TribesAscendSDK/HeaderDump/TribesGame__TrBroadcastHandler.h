#pragma once
#include "Engine__BroadcastHandler.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrBroadcastHandler." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrBroadcastHandler : public BroadcastHandler
	{
	public:
		ADD_VAR(::FloatProperty, m_fSpottedActorsUpdateFrequency, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
