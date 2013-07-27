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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.AddWeaponOverlay");
			byte params[4] = { NULL };
			*(class UTGameReplicationInfo**)&params[0] = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientLostItem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.ClientLostItem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DropFrom(Object::Vector StartLocation, Object::Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.DropFrom");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartLocation;
			*(Object::Vector*)&params[12] = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OwnerEvent(ScriptName EventName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.OwnerEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = EventName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
