#pragma once
#include "Engine__Scout.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKScout." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKScout." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKScout : public Scout
	{
	public:
		ADD_VAR(::NameProperty, SizePersonFindName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, PrototypePawnClass)
		ADD_VAR(::FloatProperty, MaxDoubleJumpHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRequiresDoubleJump, 0x1)
		// Here lies the not-yet-implemented method 'SuggestJumpVelocity'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
