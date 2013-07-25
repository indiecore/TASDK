#pragma once
#include "Core__Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GenericParamListStatEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GenericParamListStatEntry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GenericParamListStatEntry : public Object
	{
	public:
		ADD_OBJECT(GameplayEventsWriter, Writer)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'StatEvent'!
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
