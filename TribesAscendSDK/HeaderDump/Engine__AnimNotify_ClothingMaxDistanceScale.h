#pragma once
#include "Engine__AnimNotify.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNotify_ClothingMaxDistanceScale." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNotify_ClothingMaxDistanceScale : public AnimNotify
	{
	public:
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ScaleMode, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
