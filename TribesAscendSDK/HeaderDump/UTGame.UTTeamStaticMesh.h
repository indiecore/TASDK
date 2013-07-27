#pragma once
#include "Engine.StaticMeshActor.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Material.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamStaticMesh : public StaticMeshActor
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, TeamMaterials, 484)
		ADD_OBJECT(Material, NeutralMaterial, 496)
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49460);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeamNum(byte NewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49465);
			byte params[1] = { NULL };
			*params = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
