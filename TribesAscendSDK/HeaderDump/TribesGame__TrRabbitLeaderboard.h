#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrRabbitLeaderboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrRabbitLeaderboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrRabbitLeaderboard." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrRabbitLeaderboard : public Object
	{
	public:
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::BoolProperty, bIsActive, 0x4 )
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_VAR( ::BoolProperty, bInitialized, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdated, 0x1 )
			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevSlots, 0xFFFFFFFF )
			void Initialize( class TrPlayerController* PC, class GfxTrHud* MP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.Initialize" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerController** )( params + 0 ) = PC;
				*( class GfxTrHud** )( params + 4 ) = MP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Show(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.Show" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Hide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.Hide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.Tick" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePlayers( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.UpdatePlayers" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )( params + 0 ) = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UpdateLeaderboard( int Index, ScriptName PRIName, ScriptArray< wchar_t > PlayerName, int Score )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.UpdateLeaderboard" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )( params + 0 ) = Index;
				*( ScriptName* )( params + 4 ) = PRIName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = PlayerName;
				*( int* )( params + 24 ) = Score;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateTime( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.UpdateTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )( params + 0 ) = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > FormatTime( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.FormatTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ForceUpdate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRabbitLeaderboard.ForceUpdate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
