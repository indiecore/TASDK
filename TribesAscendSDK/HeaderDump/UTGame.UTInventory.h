#pragma once
#include "Engine.Inventory.h"
#include "Core.Object.h"
#include "UTGame.UTGameReplicationInfo.h"
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
	class UTInventory : public Inventory
	{
	public:
		ADD_BOOL(bReceiveOwnerEvents, 552, 0x1)
		void AddWeaponOverlay(class UTGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48017);
			byte params[4] = { NULL };
			*(class UTGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientLostItem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48019);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48020);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48022);
			byte params[24] = { NULL };
			*(Vector*)params = StartLocation;
			*(Vector*)&params[12] = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OwnerEvent(ScriptName EventName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48025);
			byte params[8] = { NULL };
			*(ScriptName*)params = EventName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
