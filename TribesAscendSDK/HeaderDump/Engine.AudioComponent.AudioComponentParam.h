#pragma once
#include "Engine.SoundNodeWave.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AudioComponent.AudioComponentParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AudioComponent.AudioComponentParam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AudioComponentParam
	{
	public:
		ADD_OBJECT(SoundNodeWave, WaveParam)
		ADD_VAR(::FloatProperty, FloatParam, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParamName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
