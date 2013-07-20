#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CoverReplicator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CoverReplicator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CoverReplicator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CoverReplicator : public ReplicationInfo
	{
	public:
			void PurgeOldEntries(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.PurgeOldEntries" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicateInitialCoverInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ReplicateInitialCoverInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetOwner( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ClientSetOwner" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSendInitialCoverReplicationInfo( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ServerSendInitialCoverReplicationInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveInitialCoverReplicationInfo( int Index, class CoverLink* Link, bool bLinkDisabled, byte NumSlotsEnabled, byte SlotsEnabled, byte NumSlotsDisabled, byte SlotsDisabled, byte NumSlotsAdjusted, byte SlotsAdjusted, byte NumCoverTypesChanged, void* SlotsCoverTypeChanged, bool bDone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ClientReceiveInitialCoverReplicationInfo" );
				byte *params = ( byte* )( malloc( 27 ) );
				*( int* )params = Index;
				*( class CoverLink** )( params + 4 ) = Link;
				*( bool* )( params + 8 ) = bLinkDisabled;
				*( byte* )( params + 12 ) = NumSlotsEnabled;
				*( byte* )( params + 13 ) = SlotsEnabled;
				*( byte* )( params + 21 ) = NumSlotsDisabled;
				*( byte* )( params + 22 ) = SlotsDisabled;
				*( byte* )( params + 30 ) = NumSlotsAdjusted;
				*( byte* )( params + 31 ) = SlotsAdjusted;
				*( byte* )( params + 39 ) = NumCoverTypesChanged;
				*( void** )( params + 40 ) = SlotsCoverTypeChanged;
				*( bool* )( params + 72 ) = bDone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyEnabledSlots( class CoverLink* Link )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.NotifyEnabledSlots" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class CoverLink** )params = Link;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSendEnabledSlots( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ServerSendEnabledSlots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveEnabledSlots( int Index, class CoverLink* Link, byte NumSlotsEnabled, byte SlotsEnabled, bool bDone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ClientReceiveEnabledSlots" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( int* )params = Index;
				*( class CoverLink** )( params + 4 ) = Link;
				*( byte* )( params + 8 ) = NumSlotsEnabled;
				*( byte* )( params + 9 ) = SlotsEnabled;
				*( bool* )( params + 20 ) = bDone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyDisabledSlots( class CoverLink* Link )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.NotifyDisabledSlots" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class CoverLink** )params = Link;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSendDisabledSlots( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ServerSendDisabledSlots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveDisabledSlots( int Index, class CoverLink* Link, byte NumSlotsDisabled, byte SlotsDisabled, bool bDone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ClientReceiveDisabledSlots" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( int* )params = Index;
				*( class CoverLink** )( params + 4 ) = Link;
				*( byte* )( params + 8 ) = NumSlotsDisabled;
				*( byte* )( params + 9 ) = SlotsDisabled;
				*( bool* )( params + 20 ) = bDone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyAutoAdjustSlots( class CoverLink* Link )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.NotifyAutoAdjustSlots" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class CoverLink** )params = Link;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSendAdjustedSlots( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ServerSendAdjustedSlots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveAdjustedSlots( int Index, class CoverLink* Link, byte NumSlotsAdjusted, byte SlotsAdjusted, bool bDone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ClientReceiveAdjustedSlots" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( int* )params = Index;
				*( class CoverLink** )( params + 4 ) = Link;
				*( byte* )( params + 8 ) = NumSlotsAdjusted;
				*( byte* )( params + 9 ) = SlotsAdjusted;
				*( bool* )( params + 20 ) = bDone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifySetManualCoverTypeForSlots( class CoverLink* Link, byte NewCoverType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.NotifySetManualCoverTypeForSlots" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class CoverLink** )params = Link;
				*( byte* )( params + 16 ) = NewCoverType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSendManualCoverTypeSlots( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ServerSendManualCoverTypeSlots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveManualCoverTypeSlots( int Index, class CoverLink* Link, byte NumCoverTypesChanged, void* SlotsCoverTypeChanged, bool bDone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ClientReceiveManualCoverTypeSlots" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( int* )params = Index;
				*( class CoverLink** )( params + 4 ) = Link;
				*( byte* )( params + 8 ) = NumCoverTypesChanged;
				*( void** )( params + 12 ) = SlotsCoverTypeChanged;
				*( bool* )( params + 44 ) = bDone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyLinkDisabledStateChange( class CoverLink* Link )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.NotifyLinkDisabledStateChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class CoverLink** )params = Link;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSendLinkDisabledState( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ServerSendLinkDisabledState" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceiveLinkDisabledState( int Index, class CoverLink* Link, bool bLinkDisabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.CoverReplicator.ClientReceiveLinkDisabledState" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = Index;
				*( class CoverLink** )( params + 4 ) = Link;
				*( bool* )( params + 8 ) = bLinkDisabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
