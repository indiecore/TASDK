#pragma once
#include "Engine__ActorFactoryVehicle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTActorFactoryVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTActorFactoryVehicle : public ActorFactoryVehicle
	{
	public:
		ADD_VAR(::ByteProperty, TeamNum, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bKeyVehicle, 0x2)
		ADD_VAR(::BoolProperty, bTeamLocked, 0x1)
		// Here lies the not-yet-implemented method 'PostCreateActor'
	};
}
#undef ADD_VAR
