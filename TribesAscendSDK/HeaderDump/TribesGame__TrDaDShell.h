#pragma once
#include "Engine__InterpActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDaDShell." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDaDShell : public InterpActor
	{
	public:
		ADD_VAR(::BoolProperty, r_bShield0Up, 0x1)
		ADD_VAR(::BoolProperty, r_bShield1Up, 0x2)
		ADD_VAR(::BoolProperty, r_bShield2Up, 0x4)
		ADD_VAR(::BoolProperty, r_bIsRotating, 0x8)
	};
}
#undef ADD_VAR
