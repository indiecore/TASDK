#pragma once
#include "Engine__StaticMeshActor.h"
#include "Engine__Material.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamStaticMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamStaticMesh : public StaticMeshActor
	{
	public:
		ADD_OBJECT(Material, NeutralMaterial)
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'SetTeamNum'
	};
}
#undef ADD_OBJECT
