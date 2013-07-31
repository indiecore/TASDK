#pragma once
#include "TribesGame.TrProj_Grenade.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_StickyGrenade : public TrProj_Grenade
	{
	public:
		ADD_OBJECT(Actor, m_OldBase, 888)
		ADD_BOOL(m_bHasStuckToTarget, 884, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108038);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108039);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTouch(class Actor* Other, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108043);
			byte params[28] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StickToTarget(class Actor* Target, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108047);
			byte params[32] = { NULL };
			*(class Actor**)params = Target;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void OnBaseChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108052);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
