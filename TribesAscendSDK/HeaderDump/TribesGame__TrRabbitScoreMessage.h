#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrRabbitScoreMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrRabbitScoreMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrRabbitScoreMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrRabbitScoreMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundCue, m_sFlagReturnedToStand )
			ADD_OBJECT( SoundCue, m_sYouPickedUpFlag )
			ADD_OBJECT( SoundCue, m_sOtherIsNewLeadeCue )
			ADD_OBJECT( SoundCue, m_sYouAreNewLeadeCue )
			ADD_VAR( ::StrProperty, GetToTheFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KillTheRabbit, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherDroppedFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouDroppedFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherIsNewLeader, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouAreNewLeader, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherScoreFlagTouch, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouScoreFlagTouch, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetString( int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitScoreMessage.GetString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = Switch;
				*( bool* )( params + 4 ) = bPRI1HUD;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ClientReceive( class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitScoreMessage.ClientReceive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte AnnouncementLevel( byte MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitScoreMessage.AnnouncementLevel" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
