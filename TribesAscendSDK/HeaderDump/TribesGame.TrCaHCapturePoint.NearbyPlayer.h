#pragma once
#include "TribesGame.TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrCaHCapturePoint.NearbyPlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrCaHCapturePoint.NearbyPlayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NearbyPlayer
	{
	public:
		ADD_VAR(::FloatProperty, LastCheckedTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, NearbyPC)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
