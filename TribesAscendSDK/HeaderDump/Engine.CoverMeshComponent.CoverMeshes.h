#pragma once
#include "Engine.StaticMesh.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty CoverMeshComponent.CoverMeshes." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CoverMeshes
	{
	public:
		ADD_OBJECT(StaticMesh, PlayerOnly)
		ADD_OBJECT(StaticMesh, PopUp)
		ADD_OBJECT(StaticMesh, SwatRight)
		ADD_OBJECT(StaticMesh, SwatLeft)
		ADD_OBJECT(StaticMesh, SlipRight)
		ADD_OBJECT(StaticMesh, SlipLeft)
		ADD_OBJECT(StaticMesh, Mantle)
		ADD_OBJECT(StaticMesh, Climb)
		ADD_OBJECT(StaticMesh, LeanRight)
		ADD_OBJECT(StaticMesh, LeanLeft)
		ADD_OBJECT(StaticMesh, Base)
	};
}
#undef ADD_OBJECT
