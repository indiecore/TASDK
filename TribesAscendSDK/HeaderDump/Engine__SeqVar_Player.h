#pragma once
#include "Engine__SeqVar_Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqVar_Player." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqVar_Player : public SeqVar_Object
	{
	public:
		ADD_VAR(::IntProperty, PlayerIdx, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllPlayers, 0x1)
	};
}
#undef ADD_VAR
