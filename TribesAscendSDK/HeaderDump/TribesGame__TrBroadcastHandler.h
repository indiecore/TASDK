#pragma once
#include "Engine__BroadcastHandler.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrBroadcastHandler." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrBroadcastHandler : public BroadcastHandler
	{
	public:
		ADD_VAR(::FloatProperty, m_fSpottedActorsUpdateFrequency, 0xFFFFFFFF)
		void TeamBroadcastVGSCommand(class PlayerReplicationInfo* SenderPRI, byte VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.TeamBroadcastVGSCommand");
			byte* params = (byte*)malloc(5);
			*(class PlayerReplicationInfo**)params = SenderPRI;
			*(params + 4) = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GlobalBroadcastVGSCommand(class PlayerReplicationInfo* SenderPRI, byte VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.GlobalBroadcastVGSCommand");
			byte* params = (byte*)malloc(5);
			*(class PlayerReplicationInfo**)params = SenderPRI;
			*(params + 4) = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamBroadcastVGSContextCommand(class PlayerReplicationInfo* SenderPRI, byte ContextActor, byte ContextLocation, bool bEnemyLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.TeamBroadcastVGSContextCommand");
			byte* params = (byte*)malloc(10);
			*(class PlayerReplicationInfo**)params = SenderPRI;
			*(params + 4) = ContextActor;
			*(params + 5) = ContextLocation;
			*(bool*)(params + 8) = bEnemyLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnActorSpotted(class Actor* SpottedActor, ScriptClass* SpottedTargetClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.OnActorSpotted");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = SpottedActor;
			*(ScriptClass**)(params + 4) = SpottedTargetClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSpottedActorsTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.UpdateSpottedActorsTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
