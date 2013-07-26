#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Actor.h"
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty WorldInfo.NetViewer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty WorldInfo.NetViewer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NetViewer
	{
	public:
		ADD_OBJECT(PlayerController, InViewer)
		ADD_OBJECT(Actor, Viewer)
		ADD_STRUCT(::VectorProperty, ViewLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ViewDir, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
