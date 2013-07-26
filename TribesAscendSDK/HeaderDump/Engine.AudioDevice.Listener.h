#pragma once
#include "Engine.PortalVolume.h"
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AudioDevice.Listener." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AudioDevice.Listener." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Listener
	{
	public:
		ADD_STRUCT(::VectorProperty, Front, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Right, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Up, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		ADD_OBJECT(PortalVolume, PortalVolume)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
