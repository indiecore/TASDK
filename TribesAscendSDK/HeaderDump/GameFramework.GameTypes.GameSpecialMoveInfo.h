#pragma once
#include "GameFramework.GameSpecialMove.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameTypes.GameSpecialMoveInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameTypes.GameSpecialMoveInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameSpecialMoveInfo
	{
	public:
		ADD_VAR(::NameProperty, SpecialMoveName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SpecialMoveClass)
		ADD_OBJECT(GameSpecialMove, SpecialMoveInstance)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
