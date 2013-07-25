#pragma once
#include "UDKBase.UDKPawn.h"
#include "UDKBase.UDKAnimBlendBase.h"
#include "Engine.AnimNodeAimOffset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByFlying." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimBlendByFlying." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByFlying : public UDKAnimBlendBase
	{
	public:
		ADD_VAR(::NameProperty, EndingAnimName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasEndingAnim, 0x2)
		ADD_VAR(::BoolProperty, bHasStartingAnim, 0x1)
		ADD_VAR(::NameProperty, StartingAnimName, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeAimOffset, FlyingDir)
		ADD_OBJECT(UDKAnimBlendBase, FlyingMode)
		ADD_OBJECT(UDKPawn, Pawn)
		ADD_VAR(::ByteProperty, FlyingState, 0xFFFFFFFF)
		void UpdateFlyingState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimBlendByFlying.UpdateFlyingState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
