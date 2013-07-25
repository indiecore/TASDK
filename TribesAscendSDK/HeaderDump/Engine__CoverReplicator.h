#pragma once
#include "Engine__ReplicationInfo.h"
#include "Engine__PlayerController.h"
#include "Engine__CoverLink.h"
namespace UnrealScript
{
	class CoverReplicator : public ReplicationInfo
	{
	public:
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
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSendInitialCoverReplicationInfo(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendInitialCoverReplicationInfo");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveInitialCoverReplicationInfo(int Index, class CoverLink* Link, bool bLinkDisabled, byte NumSlotsEnabled, byte SlotsEnabled, byte NumSlotsDisabled, byte SlotsDisabled, byte NumSlotsAdjusted, byte SlotsAdjusted, byte NumCoverTypesChanged, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverReplicator.ManualCoverTypeInfo'!
void* SlotsCoverTypeChanged, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveInitialCoverReplicationInfo");
			byte* params = (byte*)malloc(27);
			*(int*)params = Index;
			*(class CoverLink**)(params + 4) = Link;
			*(bool*)(params + 8) = bLinkDisabled;
			*(params + 12) = NumSlotsEnabled;
			*(params + 13) = SlotsEnabled;
			*(params + 21) = NumSlotsDisabled;
			*(params + 22) = SlotsDisabled;
			*(params + 30) = NumSlotsAdjusted;
			*(params + 31) = SlotsAdjusted;
			*(params + 39) = NumCoverTypesChanged;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverReplicator.ManualCoverTypeInfo'!
void**)(params + 40) = SlotsCoverTypeChanged;
			*(bool*)(params + 72) = bDone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyEnabledSlots(class CoverLink* Link, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& SlotIndices)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyEnabledSlots");
			byte* params = (byte*)malloc(16);
			*(class CoverLink**)params = Link;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = SlotIndices;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SlotIndices = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void ServerSendEnabledSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendEnabledSlots");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveEnabledSlots(int Index, class CoverLink* Link, byte NumSlotsEnabled, byte SlotsEnabled, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveEnabledSlots");
			byte* params = (byte*)malloc(14);
			*(int*)params = Index;
			*(class CoverLink**)(params + 4) = Link;
			*(params + 8) = NumSlotsEnabled;
			*(params + 9) = SlotsEnabled;
			*(bool*)(params + 20) = bDone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyDisabledSlots(class CoverLink* Link, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& SlotIndices)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyDisabledSlots");
			byte* params = (byte*)malloc(16);
			*(class CoverLink**)params = Link;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = SlotIndices;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SlotIndices = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void ServerSendDisabledSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendDisabledSlots");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveDisabledSlots(int Index, class CoverLink* Link, byte NumSlotsDisabled, byte SlotsDisabled, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveDisabledSlots");
			byte* params = (byte*)malloc(14);
			*(int*)params = Index;
			*(class CoverLink**)(params + 4) = Link;
			*(params + 8) = NumSlotsDisabled;
			*(params + 9) = SlotsDisabled;
			*(bool*)(params + 20) = bDone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyAutoAdjustSlots(class CoverLink* Link, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& SlotIndices)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyAutoAdjustSlots");
			byte* params = (byte*)malloc(16);
			*(class CoverLink**)params = Link;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = SlotIndices;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SlotIndices = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void ServerSendAdjustedSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendAdjustedSlots");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveAdjustedSlots(int Index, class CoverLink* Link, byte NumSlotsAdjusted, byte SlotsAdjusted, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveAdjustedSlots");
			byte* params = (byte*)malloc(14);
			*(int*)params = Index;
			*(class CoverLink**)(params + 4) = Link;
			*(params + 8) = NumSlotsAdjusted;
			*(params + 9) = SlotsAdjusted;
			*(bool*)(params + 20) = bDone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifySetManualCoverTypeForSlots(class CoverLink* Link, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& SlotIndices, byte NewCoverType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifySetManualCoverTypeForSlots");
			byte* params = (byte*)malloc(17);
			*(class CoverLink**)params = Link;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = SlotIndices;
			*(params + 16) = NewCoverType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SlotIndices = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void ServerSendManualCoverTypeSlots(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendManualCoverTypeSlots");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveManualCoverTypeSlots(int Index, class CoverLink* Link, byte NumCoverTypesChanged, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverReplicator.ManualCoverTypeInfo'!
void* SlotsCoverTypeChanged, bool bDone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveManualCoverTypeSlots");
			byte* params = (byte*)malloc(17);
			*(int*)params = Index;
			*(class CoverLink**)(params + 4) = Link;
			*(params + 8) = NumCoverTypesChanged;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CoverReplicator.ManualCoverTypeInfo'!
void**)(params + 12) = SlotsCoverTypeChanged;
			*(bool*)(params + 44) = bDone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyLinkDisabledStateChange(class CoverLink* Link)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.NotifyLinkDisabledStateChange");
			byte* params = (byte*)malloc(4);
			*(class CoverLink**)params = Link;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSendLinkDisabledState(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ServerSendLinkDisabledState");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveLinkDisabledState(int Index, class CoverLink* Link, bool bLinkDisabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CoverReplicator.ClientReceiveLinkDisabledState");
			byte* params = (byte*)malloc(12);
			*(int*)params = Index;
			*(class CoverLink**)(params + 4) = Link;
			*(bool*)(params + 8) = bLinkDisabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
