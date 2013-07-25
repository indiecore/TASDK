#pragma once
#include "UTGame.UTLocalMessage.h"
#include "UTGame.UTGame.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTQueuedAnnouncement.h"
#include "Engine.SoundNodeWave.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
#include "UTGame.UTAnnouncer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVoice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVoice." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVoice : public UTLocalMessage
	{
	public:
		ADD_VAR(::IntProperty, LocationSpeechOffset, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, GotOurFlagSound)
		ADD_OBJECT(SoundNodeWave, MidfieldSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierLowSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierHighSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierHereSound)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierSound)
		ADD_OBJECT(SoundNodeWave, IncomingSound)
		int GetAckMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.GetAckMessageIndex");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		int GetFriendlyFireMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.GetFriendlyFireMessageIndex");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		int GetGotYourBackMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.GetGotYourBackMessageIndex");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		int GetNeedOurFlagMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.GetNeedOurFlagMessageIndex");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.ClientReceive");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.AnnouncementSound");
			byte* params = (byte*)malloc(16);
			*(int*)params = MessageIndex;
			*(class Object**)(params + 4) = OptionalObject;
			*(class PlayerController**)(params + 8) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 12);
			free(params);
			return returnVal;
		}
		class SoundNodeWave* EnemySound(class PlayerController* PC, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.EnemySound");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = PC;
			*(class Object**)(params + 4) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.GetString");
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
		bool AllowVoiceMessage(ScriptName MessageType, class UTPlayerController* PC, class PlayerController* Recipient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.AllowVoiceMessage");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = MessageType;
			*(class UTPlayerController**)(params + 8) = PC;
			*(class PlayerController**)(params + 12) = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SendVoiceMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SendVoiceMessage");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.GetMessageIndex");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 20);
			free(params);
			return returnVal;
		}
		void InitStatusUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.InitStatusUpdate");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitCombatUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.InitCombatUpdate");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHoldingFlagUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SetHoldingFlagUpdate");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendLocalizedMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, int MessageIndex, class Object* LocationObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SendLocalizedMessage");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			*(int*)(params + 16) = MessageIndex;
			*(class Object**)(params + 20) = LocationObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendEnemyFlagCarrierHereUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SendEnemyFlagCarrierHereUpdate");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitSniperUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.InitSniperUpdate");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendEnemyStatusUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SendEnemyStatusUpdate");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendKilledVehicleMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SendKilledVehicleMessage");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class SoundNodeWave* KilledVehicleSound(class PlayerController* PC, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.KilledVehicleSound");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = PC;
			*(class Object**)(params + 4) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundNodeWave**)(params + 8);
			free(params);
			return returnVal;
		}
		bool SendLocationUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, class UTGame* G, class Pawn* StatusPawn, bool bDontSendMidfield)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SendLocationUpdate");
			byte* params = (byte*)malloc(32);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			*(class UTGame**)(params + 16) = G;
			*(class Pawn**)(params + 20) = StatusPawn;
			*(bool*)(params + 24) = bDontSendMidfield;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void SendInPositionMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.SendInPositionMessage");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)(params + 4) = Recipient;
			*(ScriptName*)(params + 8) = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.ShouldBeRemoved");
			byte* params = (byte*)malloc(16);
			*(class UTQueuedAnnouncement**)params = MyAnnouncement;
			*(ScriptClass**)(params + 4) = NewAnnouncementClass;
			*(int*)(params + 8) = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AddAnnouncement(class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVoice.AddAnnouncement");
			byte* params = (byte*)malloc(20);
			*(class UTAnnouncer**)params = Announcer;
			*(int*)(params + 4) = MessageIndex;
			*(class PlayerReplicationInfo**)(params + 8) = PRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
