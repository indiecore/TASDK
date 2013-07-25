#pragma once
#include "Engine.Inventory.h"
#include "UTGame.UTGameReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTInventory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTInventory : public Inventory
	{
	public:
		ADD_VAR(::BoolProperty, bReceiveOwnerEvents, 0x1)
		void AddWeaponOverlay(class UTGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.AddWeaponOverlay");
			byte* params = (byte*)malloc(4);
			*(class UTGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.DropFrom");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartLocation;
			*(Vector*)(params + 12) = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OwnerEvent(ScriptName EventName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventory.OwnerEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = EventName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
