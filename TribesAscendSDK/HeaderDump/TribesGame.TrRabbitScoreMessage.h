#pragma once
#include "UTGame.UTLocalMessage.h"
#include "Engine.SoundCue.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRabbitScoreMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRabbitScoreMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRabbitScoreMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundCue, m_sFlagReturnedToStand)
		ADD_OBJECT(SoundCue, m_sYouPickedUpFlag)
		ADD_OBJECT(SoundCue, m_sOtherIsNewLeadeCue)
		ADD_OBJECT(SoundCue, m_sYouAreNewLeadeCue)
		ADD_VAR(::StrProperty, GetToTheFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KillTheRabbit, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherDroppedFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouDroppedFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherIsNewLeader, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreNewLeader, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherScoreFlagTouch, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouScoreFlagTouch, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitScoreMessage.GetString");
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
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitScoreMessage.ClientReceive");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte AnnouncementLevel(byte MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitScoreMessage.AnnouncementLevel");
			byte* params = (byte*)malloc(2);
			*params = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
