#pragma once
#include "TribesGame.TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrGame_TRRabbit.ScoreStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrGame_TRRabbit.ScoreStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ScoreStruct
	{
	public:
		ADD_VAR(::FloatProperty, Score, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, C)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
