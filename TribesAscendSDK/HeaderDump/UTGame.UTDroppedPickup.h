#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.DroppedPickup.h"
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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTDroppedPickup : public DroppedPickup
	{
	public:
		ADD_BOOL(bPickupable, 504, 0x1)
		ADD_STRUCT(float, StartScale, 500)
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47247);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupMesh(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewPickupMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47248);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewPickupMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPickupParticles(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewPickupParticles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47250);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewPickupParticles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47252);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
