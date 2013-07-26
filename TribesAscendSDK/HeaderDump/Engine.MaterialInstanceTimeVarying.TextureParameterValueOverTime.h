#pragma once
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#include "Engine.Texture.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty MaterialInstanceTimeVarying.TextureParameterValueOverTime." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TextureParameterValueOverTime : public ParameterValueOverTime
	{
	public:
		ADD_OBJECT(Texture, ParameterValue)
	};
}
#undef ADD_OBJECT
