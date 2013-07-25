#pragma once
#include "UDKBase.UDKPawn.h"
#include "UDKBase.UDKAnimBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByTurnInPlace." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimBlendByTurnInPlace." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByTurnInPlace : public UDKAnimBlendBase
	{
	public:
		ADD_OBJECT(UDKPawn, OwnerUTP)
		ADD_VAR(::FloatProperty, TurnInPlaceBlendSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RootYawSpeedThresh, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
