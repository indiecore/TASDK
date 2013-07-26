#pragma once
#include "Engine.Actor.ActorReference.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.CoverReference." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CoverReference : public ActorReference
	{
	public:
		ADD_VAR(::IntProperty, SlotIdx, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
