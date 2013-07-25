#pragma once
#include "Engine__Actor.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn : public Actor
	{
	public:
		ADD_OBJECT(TrPlayerController, OwningController)
		ADD_OBJECT(ScriptClass, ExtentTemplateClass)
		ADD_VAR(::BoolProperty, IsInProgress, 0x4)
		ADD_VAR(::BoolProperty, PendingDelete, 0x2)
		ADD_VAR(::BoolProperty, CheckExtentsOnSpawn, 0x1)
		ADD_VAR(::FloatProperty, VehicleDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GameObjectiveDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlagStationDist, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DisplayName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, MICDisplay)
		ADD_VAR(::IntProperty, CreditCost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DegreeOfMovement, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CooldownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CallTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BuildupTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DatabaseId, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CallInId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'GetCreditCost'
		// Here lies the not-yet-implemented method 'VerifyCredits'
		// Here lies the not-yet-implemented method 'VerifyPower'
		// Here lies the not-yet-implemented method 'FireCompletedCallIn'
		// Here lies the not-yet-implemented method 'Tick'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
