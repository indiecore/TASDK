#pragma once
#include "Core.Object.Guid.h"
#include "Engine.NavigationPoint.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Actor.NavReference." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Actor.NavReference." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavReference
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Guid>, Guid, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, Nav)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
