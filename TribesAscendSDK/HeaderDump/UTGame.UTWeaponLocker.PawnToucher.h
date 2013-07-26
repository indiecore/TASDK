#pragma once
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTWeaponLocker.PawnToucher." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTWeaponLocker.PawnToucher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PawnToucher
	{
	public:
		ADD_VAR(::FloatProperty, NextTouchTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, P)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
