#pragma once
#include "Engine.Pawn.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
namespace UnrealScript
{
	class GamePawn : public Pawn
	{
	public:
		ADD_BOOL(bRespondToExplosions, 1144, 0x2)
		ADD_BOOL(bLastHitWasHeadShot, 1144, 0x1)
		void UpdateShadowSettings(bool bInWantShadow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31725);
			byte params[4] = { NULL };
			*(bool*)params = bInWantShadow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReattachMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31729);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReattachMeshWithoutBeingSeen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31730);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
