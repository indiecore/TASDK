#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshObstacle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshObstacle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshObstacle : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bPreserveInternalGeo, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_NavMeshPathObstacle'!
		// Here lies the not-yet-implemented method 'GetObstacleBoudingShape'
		// Here lies the not-yet-implemented method 'RegisterObstacle'
		// Here lies the not-yet-implemented method 'UnRegisterObstacle'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'SetEnabled'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
