#pragma once
#include "UDKBase.UDKAnimBlendBase.h"
#include "UDKBase.UDKAnimNodeJumpLeanOffset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByFall." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimBlendByFall." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByFall : public UDKAnimBlendBase
	{
	public:
		ADD_OBJECT(UDKAnimNodeJumpLeanOffset, CachedLeanNode)
		ADD_VAR(::FloatProperty, LastFallingVelocity, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FallState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ToDblJumpUprightTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PreLandStartUprightTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PreLandTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDodgeFall, 0x4)
		ADD_VAR(::BoolProperty, bDidDoubleJump, 0x2)
		ADD_VAR(::BoolProperty, bIgnoreDoubleJumps, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
