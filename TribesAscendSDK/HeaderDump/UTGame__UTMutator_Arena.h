#pragma once
#include "UTGame__UTMutator.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMutator_Arena." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTMutator_Arena : public UTMutator
	{
	public:
		ADD_VAR(::StrProperty, ArenaWeaponClassPath, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'CheckReplacement'
		// Here lies the not-yet-implemented method 'ModifyPlayer'
	};
}
#undef ADD_VAR
