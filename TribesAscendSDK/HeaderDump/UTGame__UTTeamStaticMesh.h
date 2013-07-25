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
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamStaticMesh.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeamNum(byte NewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamStaticMesh.SetTeamNum");
			byte* params = (byte*)malloc(1);
			*params = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
