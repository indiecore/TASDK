#pragma once
#include "GameFramework__GamePawn.h"
#include "Core__Object.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameSpecialMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameSpecialMove." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameSpecialMove." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameSpecialMove : public Object
	{
	public:
		ADD_STRUCT(::RotatorProperty, PreciseRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, PreciseRotationInterpolationTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PreciseDestRelOffset, 0xFFFFFFFF
		ADD_OBJECT(Actor, PreciseDestBase)
		ADD_STRUCT(::VectorProperty, PreciseDestination, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bForcePrecisePosition, 0x20)
		ADD_VAR(::BoolProperty, bReachedPreciseRotation, 0x10)
		ADD_VAR(::BoolProperty, bReachPreciseRotation, 0x8)
		ADD_VAR(::BoolProperty, bReachedPreciseDestination, 0x4)
		ADD_VAR(::BoolProperty, bReachPreciseDestination, 0x2)
		ADD_VAR(::BoolProperty, bLastCanDoSpecialMove, 0x1)
		ADD_VAR(::FloatProperty, LastCanDoSpecialMoveTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Handle, 0xFFFFFFFF)
		ADD_OBJECT(GamePawn, PawnOwner)
		// Here lies the not-yet-implemented method 'InitSpecialMove'
		// Here lies the not-yet-implemented method 'InitSpecialMoveFlags'
		// Here lies the not-yet-implemented method 'ExtractSpecialMoveFlags'
		// Here lies the not-yet-implemented method 'CanChainMove'
		// Here lies the not-yet-implemented method 'CanOverrideMoveWith'
		// Here lies the not-yet-implemented method 'CanOverrideSpecialMove'
		// Here lies the not-yet-implemented method 'CanDoSpecialMove'
		// Here lies the not-yet-implemented method 'InternalCanDoSpecialMove'
		// Here lies the not-yet-implemented method 'SpecialMoveStarted'
		// Here lies the not-yet-implemented method 'SpecialMoveEnded'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'SpecialMoveFlagsUpdated'
		// Here lies the not-yet-implemented method 'ShouldReplicate'
		// Here lies the not-yet-implemented method 'SetReachPreciseDestination'
		// Here lies the not-yet-implemented method 'SetFacePreciseRotation'
		// Here lies the not-yet-implemented method 'ReachedPrecisePosition'
		// Here lies the not-yet-implemented method 'ResetFacePreciseRotation'
		// Here lies the not-yet-implemented method 'MessageEvent'
		// Here lies the not-yet-implemented method 'ForcePawnRotation'
		// Here lies the not-yet-implemented method 'WorldToRelativeOffset'
		// Here lies the not-yet-implemented method 'RelativeToWorldOffset'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
