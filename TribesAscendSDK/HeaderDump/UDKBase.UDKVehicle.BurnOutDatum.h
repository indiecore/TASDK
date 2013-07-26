#pragma once
#include "Engine.MaterialInstanceTimeVarying.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.BurnOutDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKVehicle.BurnOutDatum." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class BurnOutDatum
	{
	public:
		ADD_VAR(::FloatProperty, CurrValue, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceTimeVarying, MITV)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
