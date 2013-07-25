#pragma once
#include "UTGame__UTPickupFactory.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTItemPickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTItemPickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTItemPickupFactory : public UTPickupFactory
	{
	public:
		ADD_VAR(::StrProperty, PickupMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UseHintMessage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PickupSound)
		void InitializePickup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTItemPickupFactory.InitializePickup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetLocalString(int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTItemPickupFactory.GetLocalString");
			byte* params = (byte*)malloc(24);
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void SpawnCopyFor(class Pawn* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTItemPickupFactory.SpawnCopyFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTItemPickupFactory.SetRespawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetRespawnTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTItemPickupFactory.GetRespawnTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float BotDesireability(class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTItemPickupFactory.BotDesireability");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
