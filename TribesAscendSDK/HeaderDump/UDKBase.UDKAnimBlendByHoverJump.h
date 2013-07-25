#pragma once
#include "Engine.Pawn.h"
#include "UDKBase.UDKAnimBlendByFall.h"
#include "UDKBase.UDKVehicle.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimBlendByHoverJump." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByHoverJump : public UDKAnimBlendByFall
	{
	public:
		ADD_OBJECT(UDKVehicle, OwnerHV)
		ADD_OBJECT(Pawn, OwnerP)
	};
}
#undef ADD_OBJECT
