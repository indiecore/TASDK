#pragma once
#include "Engine__Emitter.h"
#include "UDKBase__UDKPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKEmitCameraEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKEmitCameraEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKEmitCameraEffect : public Emitter
	{
	public:
		ADD_OBJECT(UDKPlayerController, Cam)
		ADD_VAR(::FloatProperty, DistFromCamera, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'RegisterCamera'
		// Here lies the not-yet-implemented method 'Activate'
		// Here lies the not-yet-implemented method 'Deactivate'
		// Here lies the not-yet-implemented method 'UpdateLocation'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
