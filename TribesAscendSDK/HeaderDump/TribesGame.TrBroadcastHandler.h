#pragma once
#include "Engine.BroadcastHandler.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrSpottedTarget.h"
#include "TribesGame.TrVGSCommandList.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrBroadcastHandler : public BroadcastHandler
	{
	public:
		ADD_STRUCT(ScriptArray<class TrSpottedTarget*>, m_SpottedTargets, 484)
		ADD_STRUCT(float, m_fSpottedActorsUpdateFrequency, 496)
		void TeamBroadcastVGSCommand(class PlayerReplicationInfo* SenderPRI, TrVGSCommandList::VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.TeamBroadcastVGSCommand");
			byte params[5] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = SenderPRI;
			*(TrVGSCommandList::VGSCommandType*)&params[4] = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GlobalBroadcastVGSCommand(class PlayerReplicationInfo* SenderPRI, TrVGSCommandList::VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.GlobalBroadcastVGSCommand");
			byte params[5] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = SenderPRI;
			*(TrVGSCommandList::VGSCommandType*)&params[4] = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamBroadcastVGSContextCommand(class PlayerReplicationInfo* SenderPRI, TrVGSCommandList::EVGSContextActor ContextActor, TrVGSCommandList::EVGSContextLocation ContextLocation, bool bEnemyLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.TeamBroadcastVGSContextCommand");
			byte params[10] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = SenderPRI;
			*(TrVGSCommandList::EVGSContextActor*)&params[4] = ContextActor;
			*(TrVGSCommandList::EVGSContextLocation*)&params[5] = ContextLocation;
			*(bool*)&params[8] = bEnemyLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnActorSpotted(class Actor* SpottedActor, ScriptClass* SpottedTargetClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.OnActorSpotted");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = SpottedActor;
			*(ScriptClass**)&params[4] = SpottedTargetClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSpottedActorsTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBroadcastHandler.UpdateSpottedActorsTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
