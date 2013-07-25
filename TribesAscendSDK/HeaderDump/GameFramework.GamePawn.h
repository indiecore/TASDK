#pragma once
#include "Engine.Pawn.h"
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
		void UpdateShadowSettings(bool bInWantShadow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePawn.UpdateShadowSettings");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReattachMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePawn.ReattachMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReattachMeshWithoutBeingSeen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePawn.ReattachMeshWithoutBeingSeen");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
