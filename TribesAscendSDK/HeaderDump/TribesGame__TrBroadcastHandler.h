#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrBroadcastHandler." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrBroadcastHandler." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrBroadcastHandler." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrBroadcastHandler : public BroadcastHandler
	{
	public:
			ADD_VAR( ::FloatProperty, m_fSpottedActorsUpdateFrequency, 0xFFFFFFFF )
			void TeamBroadcastVGSCommand( class PlayerReplicationInfo* SenderPRI, byte VGSCommandIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrBroadcastHandler.TeamBroadcastVGSCommand" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class PlayerReplicationInfo** )params = SenderPRI;
				*( byte* )( params + 4 ) = VGSCommandIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GlobalBroadcastVGSCommand( class PlayerReplicationInfo* SenderPRI, byte VGSCommandIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrBroadcastHandler.GlobalBroadcastVGSCommand" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class PlayerReplicationInfo** )params = SenderPRI;
				*( byte* )( params + 4 ) = VGSCommandIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamBroadcastVGSContextCommand( class PlayerReplicationInfo* SenderPRI, byte ContextActor, byte ContextLocation, bool bEnemyLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrBroadcastHandler.TeamBroadcastVGSContextCommand" );
				byte *params = ( byte* )( malloc( 10 ) );
				*( class PlayerReplicationInfo** )params = SenderPRI;
				*( byte* )( params + 4 ) = ContextActor;
				*( byte* )( params + 5 ) = ContextLocation;
				*( bool* )( params + 8 ) = bEnemyLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnActorSpotted( class Actor* SpottedActor, ScriptClass* SpottedTargetClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrBroadcastHandler.OnActorSpotted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = SpottedActor;
				*( ScriptClass** )( params + 4 ) = SpottedTargetClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSpottedActorsTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrBroadcastHandler.UpdateSpottedActorsTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
