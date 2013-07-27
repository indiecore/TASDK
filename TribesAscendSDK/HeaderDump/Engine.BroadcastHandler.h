#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Info.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.PlayerReplicationInfo.h"
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
	class BroadcastHandler : public Info
	{
	public:
		ADD_BOOL(bMuteSpectators, 480, 0x1)
		ADD_STRUCT(int, SentText, 476)
		void UpdateSentText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.UpdateSentText");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AllowsBroadcast(class Actor* broadcaster, int InLen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.AllowsBroadcast");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = broadcaster;
			*(int*)&params[4] = InLen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void BroadcastText(class PlayerReplicationInfo* SenderPRI, class PlayerController* Receiver, ScriptString* msg, ScriptName Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.BroadcastText");
			byte params[28] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = SenderPRI;
			*(class PlayerController**)&params[4] = Receiver;
			*(ScriptString**)&params[8] = msg;
			*(ScriptName*)&params[20] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastLocalized(class Actor* Sender, class PlayerController* Receiver, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.BroadcastLocalized");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = Sender;
			*(class PlayerController**)&params[4] = Receiver;
			*(ScriptClass**)&params[8] = Message;
			*(int*)&params[12] = Switch;
			*(class PlayerReplicationInfo**)&params[16] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[20] = RelatedPRI_2;
			*(class Object**)&params[24] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Broadcast(class Actor* Sender, ScriptString* msg, ScriptName Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.Broadcast");
			byte params[24] = { NULL };
			*(class Actor**)&params[0] = Sender;
			*(ScriptString**)&params[4] = msg;
			*(ScriptName*)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastTeam(class Controller* Sender, ScriptString* msg, ScriptName Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.BroadcastTeam");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Sender;
			*(ScriptString**)&params[4] = msg;
			*(ScriptName*)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AllowBroadcastLocalized(class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.AllowBroadcastLocalized");
			byte params[24] = { NULL };
			*(class Actor**)&params[0] = Sender;
			*(ScriptClass**)&params[4] = Message;
			*(int*)&params[8] = Switch;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[16] = RelatedPRI_2;
			*(class Object**)&params[20] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AllowBroadcastLocalizedTeam(int TeamIndex, class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.BroadcastHandler.AllowBroadcastLocalizedTeam");
			byte params[28] = { NULL };
			*(int*)&params[0] = TeamIndex;
			*(class Actor**)&params[4] = Sender;
			*(ScriptClass**)&params[8] = Message;
			*(int*)&params[12] = Switch;
			*(class PlayerReplicationInfo**)&params[16] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[20] = RelatedPRI_2;
			*(class Object**)&params[24] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
