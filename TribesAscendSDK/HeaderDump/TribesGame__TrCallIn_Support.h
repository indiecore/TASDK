#pragma once
#include "TribesGame__TrCallIn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_Support." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_Support." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_Support : public TrCallIn
	{
	public:
		ADD_VAR(::IntProperty, MaxDeployedLimit, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ItemInDeliveryPod)
		// Here lies the not-yet-implemented method 'FireCompletedCallIn'
		// Here lies the not-yet-implemented method 'DestroyOverLimit'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
