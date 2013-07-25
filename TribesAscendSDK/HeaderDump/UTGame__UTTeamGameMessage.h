#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Engine__SoundNodeWave.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamGameMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTeamGameMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamGameMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamGameMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, AnnouncerSounds)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BlueDrawColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RedDrawColor'!
		ADD_VAR(::StrProperty, YouAreOnBlueMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreOnRedMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RequestTeamSwapPostfix, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RequestTeamSwapPrefix, 0xFFFFFFFF)
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGameMessage.ClientReceive");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGameMessage.GetString");
			byte* params = (byte*)malloc(32);
			*(int*)params = Switch;
			*(bool*)(params + 4) = bPRI1HUD;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 20);
			free(params);
			return returnVal;
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGameMessage.AnnouncementSound");
			byte* params = (byte*)malloc(16);
			*(int*)params = MessageIndex;
			*(class Object**)(params + 4) = OptionalObject;
			*(class PlayerController**)(params + 8) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 12);
			free(params);
			return returnVal;
		}
		int GetFontSize(int Switch, class PlayerReplicationInfo* RelatedPRI1, class PlayerReplicationInfo* RelatedPRI2, class PlayerReplicationInfo* LocalPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGameMessage.GetFontSize");
			byte* params = (byte*)malloc(20);
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI1;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI2;
			*(class PlayerReplicationInfo**)(params + 12) = LocalPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		float GetPos(int Switch, class HUD* myHUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGameMessage.GetPos");
			byte* params = (byte*)malloc(12);
			*(int*)params = Switch;
			*(class HUD**)(params + 4) = myHUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* GetColor(int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGameMessage.GetColor");
			byte* params = (byte*)malloc(20);
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
