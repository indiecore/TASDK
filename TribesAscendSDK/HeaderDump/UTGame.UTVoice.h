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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTVoice : public UTLocalMessage
	{
	public:
		static const auto ACKINDEXSTART = 600;
		static const auto FRIENDLYFIREINDEXSTART = 700;
		static const auto GOTYOURBACKINDEXSTART = 800;
		static const auto NEEDOURFLAGINDEXSTART = 900;
		static const auto SNIPERINDEXINDEXSTART = 1000;
		static const auto LOCATIONUPDATEINDEXSTART = 1100;
		static const auto INPOSITIONINDEXSTART = 1200;
		static const auto ENEMYSTATUSINDEXSTART = 1300;
		static const auto KILLEDVEHICLEINDEXSTART = 1400;
		static const auto ENEMYFLAGCARRIERINDEXSTART = 1500;
		static const auto HOLDINGFLAGINDEXSTART = 1600;
		static const auto AREASECUREINDEXSTART = 1700;
		static const auto GOTOURFLAGINDEXSTART = 1900;
		static const auto NODECONSTRUCTEDINDEXSTART = 2000;
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, AckSounds, 100)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, FriendlyFireSounds, 112)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, GotYourBackSounds, 124)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, NeedOurFlagSounds, 136)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, SniperSounds, 148)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, InPositionSounds, 160)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, HaveFlagSounds, 172)
		ADD_STRUCT(ScriptArray<class SoundNodeWave*>, AreaSecureSounds, 184)
		ADD_STRUCT(int, LocationSpeechOffset, 224)
		ADD_OBJECT(SoundNodeWave, GotOurFlagSound, 220)
		ADD_OBJECT(SoundNodeWave, MidfieldSound, 216)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierLowSound, 212)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierHighSound, 208)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierHereSound, 204)
		ADD_OBJECT(SoundNodeWave, EnemyFlagCarrierSound, 200)
		ADD_OBJECT(SoundNodeWave, IncomingSound, 196)
		int GetAckMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50021);
			byte params[20] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		int GetFriendlyFireMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50026);
			byte params[20] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		int GetGotYourBackMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50031);
			byte params[20] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		int GetNeedOurFlagMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50036);
			byte params[20] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50041);
			byte params[20] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundNodeWave* AnnouncementSound(int MessageIndex, class Object* OptionalObject, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50047);
			byte params[16] = { NULL };
			*(int*)params = MessageIndex;
			*(class Object**)&params[4] = OptionalObject;
			*(class PlayerController**)&params[8] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[12];
		}
		class SoundNodeWave* EnemySound(class PlayerController* PC, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50055);
			byte params[12] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Object**)&params[4] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[8];
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50063);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		bool AllowVoiceMessage(ScriptName MessageType, class UTPlayerController* PC, class PlayerController* Recipient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50070);
			byte params[20] = { NULL };
			*(ScriptName*)params = MessageType;
			*(class UTPlayerController**)&params[8] = PC;
			*(class PlayerController**)&params[12] = Recipient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SendVoiceMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50076);
			byte params[20] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetMessageIndex(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50087);
			byte params[24] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		void InitStatusUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50093);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitCombatUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50099);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHoldingFlagUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50104);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendLocalizedMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, int MessageIndex, class Object* LocationObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50109);
			byte params[24] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			*(int*)&params[16] = MessageIndex;
			*(class Object**)&params[20] = LocationObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendEnemyFlagCarrierHereUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50117);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitSniperUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50126);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendEnemyStatusUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50132);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendKilledVehicleMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50140);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SoundNodeWave* KilledVehicleSound(class PlayerController* PC, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50145);
			byte params[12] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Object**)&params[4] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundNodeWave**)&params[8];
		}
		bool SendLocationUpdate(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType, class UTGame* G, class Pawn* StatusPawn, bool bDontSendMidfield)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50150);
			byte params[32] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			*(class UTGame**)&params[16] = G;
			*(class Pawn**)&params[20] = StatusPawn;
			*(bool*)&params[24] = bDontSendMidfield;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void SendInPositionMessage(class Controller* Sender, class PlayerReplicationInfo* Recipient, ScriptName MessageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50160);
			byte params[16] = { NULL };
			*(class Controller**)params = Sender;
			*(class PlayerReplicationInfo**)&params[4] = Recipient;
			*(ScriptName*)&params[8] = MessageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldBeRemoved(class UTQueuedAnnouncement* MyAnnouncement, ScriptClass* NewAnnouncementClass, int NewMessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50164);
			byte params[16] = { NULL };
			*(class UTQueuedAnnouncement**)params = MyAnnouncement;
			*(ScriptClass**)&params[4] = NewAnnouncementClass;
			*(int*)&params[8] = NewMessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AddAnnouncement(class UTAnnouncer* Announcer, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50172);
			byte params[20] = { NULL };
			*(class UTAnnouncer**)params = Announcer;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
