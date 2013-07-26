#pragma once
#include "Core.Object.h"
#include "Core.Object.IntPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.BookMark2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.BookMark2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BookMark2D : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<IntPoint>, Location, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Zoom2D, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
