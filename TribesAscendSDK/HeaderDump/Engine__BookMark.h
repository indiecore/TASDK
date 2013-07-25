#pragma once
#include "Core__Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.BookMark." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BookMark : public Object
	{
	public:
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF
	};
}
#undef ADD_STRUCT
