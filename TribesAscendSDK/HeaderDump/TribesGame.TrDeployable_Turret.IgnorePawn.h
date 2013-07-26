#pragma once
#include "TribesGame.TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDeployable_Turret.IgnorePawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrDeployable_Turret.IgnorePawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class IgnorePawn
	{
	public:
		ADD_VAR(::FloatProperty, UnignoreTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, PawnToIgnore)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
