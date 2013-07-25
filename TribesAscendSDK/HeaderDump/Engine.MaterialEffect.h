#pragma once
#include "Engine.PostProcessEffect.h"
#include "Engine.MaterialInterface.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialEffect : public PostProcessEffect
	{
	public:
		ADD_OBJECT(MaterialInterface, Material)
	};
}
#undef ADD_OBJECT
