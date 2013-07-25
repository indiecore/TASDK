#pragma once
#include "Core__Object.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LightmappedSurfaceCollection." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LightmappedSurfaceCollection : public Object
	{
	public:
		ADD_OBJECT(Model, SourceModel)
	};
}
#undef ADD_OBJECT
