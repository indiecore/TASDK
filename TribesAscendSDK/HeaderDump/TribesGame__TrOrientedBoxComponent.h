#pragma once
#include "Engine__PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrOrientedBoxComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrOrientedBoxComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, BoxLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoxWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoxHeight, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
