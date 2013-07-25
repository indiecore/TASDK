#pragma once
#include "Engine__SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_LevelVisibility." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_LevelVisibility." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_LevelVisibility : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bStatusIsOk, 0x1)
		ADD_VAR(::NameProperty, LevelName, 0xFFFFFFFF)
		ADD_OBJECT(LevelStreaming, Level)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
