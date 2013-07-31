#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrCollisionProxy_Flag : public TrCollisionProxy
	{
	public:
		ADD_STRUCT(int, m_nFlagReachLevel, 492)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74542);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
