#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVictoryMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVictoryMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVictoryMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVictoryMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, TrainingComplete, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DrawGame, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PlayerWonRound, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DiamondSwordVictory, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BloodEagleVictory, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NormalDefeat, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NormalVictory, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DominantDefeat, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DominantVictory, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, BloodEagleSounds )
			ADD_OBJECT( SoundCue, DiamondSwordSounds )
			ScriptArray< wchar_t > GetString( int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVictoryMessage.GetString" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVictoryMessage.ClientReceive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
