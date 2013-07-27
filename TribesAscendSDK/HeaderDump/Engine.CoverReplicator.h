#pragma once
#include "Engine.ReplicationInfo.h"
#include "Engine.PlayerController.h"
#include "Engine.CoverLink.h"
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
	class CoverReplicator : public ReplicationInfo
	{
	public:
		class ManualCoverTypeInfo
		{
		public:
			ADD_STRUCT(CoverLink::ECoverType, ManualCoverType, 1)
			ADD_STRUCT(byte, SlotIndex, 0)
		};
		class CoverReplicationInfo
		{
		public:
			ADD_STRUCT(ScriptArray<byte>, SlotsEnabled, 4)
			ADD_STRUCT(ScriptArray<byte>, SlotsDisabled, 16)
			ADD_STRUCT(ScriptArray<byte>, SlotsAdjusted, 28)
			ADD_STRUCT(ScriptArray<CoverReplicator::ManualCoverTypeInfo>, SlotsCoverTypeChanged, 40)
			ADD_OBJECT(CoverLink, Link, 0)
		};
		ADD_STRUCT(ScriptArray<CoverReplicator::CoverReplicationInfo>, CoverReplicationData, 476)
		void PurgeOldEntries()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.PurgeOldEntries");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicateInitialCoverInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ReplicateInitialCoverInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetOwner(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientSetOwner");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSendInitialCoverReplicationInfo(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendInitialCoverReplicationInfo");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveInitialCoverReplicationInfo(int Index, class CoverLink* Link, bool bLinkDisabled, byte NumSlotsEnabled, byte SlotsEnabled, byte NumSlotsDisabled, byte SlotsDisabled, byte NumSlotsAdjusted, byte SlotsAdjusted, byte NumCoverTypesChanged, CoverReplicator::ManualCoverTypeInfo SlotsCoverTypeChanged, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveInitialCoverReplicationInfo");
			byte params[27] = { NULL };
			*(int*)&params[0] = Index;
			*(class CoverLink**)&params[4] = Link;
			*(bool*)&params[8] = bLinkDisabled;
			params[12] = NumSlotsEnabled;
			params[13] = SlotsEnabled;
			params[21] = NumSlotsDisabled;
			params[22] = SlotsDisabled;
			params[30] = NumSlotsAdjusted;
			params[31] = SlotsAdjusted;
			params[39] = NumCoverTypesChanged;
			*(CoverReplicator::ManualCoverTypeInfo*)&params[40] = SlotsCoverTypeChanged;
			*(bool*)&params[72] = bDone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyEnabledSlots(class CoverLink* Link, ScriptArray<int>& SlotIndices)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyEnabledSlots");
			byte params[16] = { NULL };
			*(class CoverLink**)&params[0] = Link;
			*(ScriptArray<int>*)&params[4] = SlotIndices;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SlotIndices = *(ScriptArray<int>*)&params[4];
		}
		void ServerSendEnabledSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendEnabledSlots");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveEnabledSlots(int Index, class CoverLink* Link, byte NumSlotsEnabled, byte SlotsEnabled, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveEnabledSlots");
			byte params[14] = { NULL };
			*(int*)&params[0] = Index;
			*(class CoverLink**)&params[4] = Link;
			params[8] = NumSlotsEnabled;
			params[9] = SlotsEnabled;
			*(bool*)&params[20] = bDone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyDisabledSlots(class CoverLink* Link, ScriptArray<int>& SlotIndices)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyDisabledSlots");
			byte params[16] = { NULL };
			*(class CoverLink**)&params[0] = Link;
			*(ScriptArray<int>*)&params[4] = SlotIndices;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SlotIndices = *(ScriptArray<int>*)&params[4];
		}
		void ServerSendDisabledSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendDisabledSlots");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveDisabledSlots(int Index, class CoverLink* Link, byte NumSlotsDisabled, byte SlotsDisabled, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveDisabledSlots");
			byte params[14] = { NULL };
			*(int*)&params[0] = Index;
			*(class CoverLink**)&params[4] = Link;
			params[8] = NumSlotsDisabled;
			params[9] = SlotsDisabled;
			*(bool*)&params[20] = bDone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyAutoAdjustSlots(class CoverLink* Link, ScriptArray<int>& SlotIndices)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyAutoAdjustSlots");
			byte params[16] = { NULL };
			*(class CoverLink**)&params[0] = Link;
			*(ScriptArray<int>*)&params[4] = SlotIndices;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SlotIndices = *(ScriptArray<int>*)&params[4];
		}
		void ServerSendAdjustedSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendAdjustedSlots");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveAdjustedSlots(int Index, class CoverLink* Link, byte NumSlotsAdjusted, byte SlotsAdjusted, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveAdjustedSlots");
			byte params[14] = { NULL };
			*(int*)&params[0] = Index;
			*(class CoverLink**)&params[4] = Link;
			params[8] = NumSlotsAdjusted;
			params[9] = SlotsAdjusted;
			*(bool*)&params[20] = bDone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifySetManualCoverTypeForSlots(class CoverLink* Link, ScriptArray<int>& SlotIndices, CoverLink::ECoverType NewCoverType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifySetManualCoverTypeForSlots");
			byte params[17] = { NULL };
			*(class CoverLink**)&params[0] = Link;
			*(ScriptArray<int>*)&params[4] = SlotIndices;
			*(CoverLink::ECoverType*)&params[16] = NewCoverType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SlotIndices = *(ScriptArray<int>*)&params[4];
		}
		void ServerSendManualCoverTypeSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendManualCoverTypeSlots");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveManualCoverTypeSlots(int Index, class CoverLink* Link, byte NumCoverTypesChanged, CoverReplicator::ManualCoverTypeInfo SlotsCoverTypeChanged, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveManualCoverTypeSlots");
			byte params[17] = { NULL };
			*(int*)&params[0] = Index;
			*(class CoverLink**)&params[4] = Link;
			params[8] = NumCoverTypesChanged;
			*(CoverReplicator::ManualCoverTypeInfo*)&params[12] = SlotsCoverTypeChanged;
			*(bool*)&params[44] = bDone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyLinkDisabledStateChange(class CoverLink* Link)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyLinkDisabledStateChange");
			byte params[4] = { NULL };
			*(class CoverLink**)&params[0] = Link;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSendLinkDisabledState(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendLinkDisabledState");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveLinkDisabledState(int Index, class CoverLink* Link, bool bLinkDisabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveLinkDisabledState");
			byte params[12] = { NULL };
			*(int*)&params[0] = Index;
			*(class CoverLink**)&params[4] = Link;
			*(bool*)&params[8] = bLinkDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
