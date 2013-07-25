#pragma once
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrDeployable.h"
#include "Engine__Actor.h"
#include "Engine__Weapon.h"
#include "Engine__Controller.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTurretPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTurretPawn : public TrPawn
	{
	public:
		ADD_OBJECT(TrDeployable, m_OwnerDeployable)
		// Here lies the not-yet-implemented method 'LeadingAimLocation'
		// Here lies the not-yet-implemented method 'GetValidAimTarget'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'WeaponFired'
		// Here lies the not-yet-implemented method 'GetAimVectorFor'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'GetWeaponStartTraceLocation'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'RefreshPlayer'
		// Here lies the not-yet-implemented method 'RefreshInventory'
		// Here lies the not-yet-implemented method 'SetCharacterClassFromInfo'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'IncrementFlashCount'
	};
}
#undef ADD_OBJECT
