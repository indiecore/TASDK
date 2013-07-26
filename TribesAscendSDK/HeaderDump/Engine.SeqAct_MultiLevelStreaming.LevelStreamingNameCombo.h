#pragma once
#include "Engine.LevelStreaming.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SeqAct_MultiLevelStreaming.LevelStreamingNameCombo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SeqAct_MultiLevelStreaming.LevelStreamingNameCombo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LevelStreamingNameCombo
	{
	public:
		ADD_VAR(::NameProperty, LevelName, 0xFFFFFFFF)
		ADD_OBJECT(LevelStreaming, Level)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
