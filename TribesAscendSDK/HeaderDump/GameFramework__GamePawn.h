#pragma once
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GamePawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GamePawn : public Pawn
	{
	public:
		ADD_VAR(::BoolProperty, bRespondToExplosions, 0x2)
		ADD_VAR(::BoolProperty, bLastHitWasHeadShot, 0x1)
		// Here lies the not-yet-implemented method 'UpdateShadowSettings'
		// Here lies the not-yet-implemented method 'ReattachMesh'
		// Here lies the not-yet-implemented method 'ReattachMeshWithoutBeingSeen'
	};
}
#undef ADD_VAR
