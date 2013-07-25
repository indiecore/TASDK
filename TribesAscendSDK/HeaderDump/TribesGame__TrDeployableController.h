#pragma once
#include "Engine__AIController.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Weapon.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployableController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployableController : public AIController
	{
	public:
		ADD_OBJECT(TrPlayerController, m_SpawnedFromController)
		// Here lies the not-yet-implemented method 'CanFireWeapon'
		// Here lies the not-yet-implemented method 'ScriptGetTeamNum'
	};
}
#undef ADD_OBJECT
