#pragma once
#include "Engine__MaterialInstance.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialInstanceTimeVarying." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialInstanceTimeVarying : public MaterialInstance
	{
	public:
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoActivateAll, 0x1)
	};
}
#undef ADD_VAR
