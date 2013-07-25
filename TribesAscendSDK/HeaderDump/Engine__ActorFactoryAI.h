#pragma once
#include "Engine__ActorFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorFactoryAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ActorFactoryAI : public ActorFactory
	{
	public:
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGiveDefaultInventory, 0x1)
		ADD_VAR(::StrProperty, PawnName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
