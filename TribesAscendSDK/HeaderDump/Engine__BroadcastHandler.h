#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.BroadcastHandler." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BroadcastHandler : public Info
	{
	public:
		ADD_VAR(::BoolProperty, bMuteSpectators, 0x1)
		ADD_VAR(::IntProperty, SentText, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
