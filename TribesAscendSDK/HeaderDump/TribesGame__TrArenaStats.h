#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrArenaStats." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrArenaStats." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrArenaStats." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrArenaStats : public Object
	{
	public:
			ADD_VAR( ::IntProperty, MyTeam, 0xFFFFFFFF )
			void Initialize( class TrPlayerController* PC, class GfxTrHud* MP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.Initialize" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerController** )params = PC;
				*( class GfxTrHud** )( params + 4 ) = MP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			void Show(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.Show" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bIsActive, 0x1 )
			void Hide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.Hide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.Tick" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.UpdateTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTeamScore( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.UpdateTeamScore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, TeamScore, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForcingUpdate, 0x2 )
			void SetManGraphicState( bool bFriendly, int Index, byte NewState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.SetManGraphicState" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( bool* )params = bFriendly;
				*( int* )( params + 4 ) = Index;
				*( byte* )( params + 8 ) = NewState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, FriendlyManGraphics, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, EnemyManGraphics, 0xFFFFFFFF )
			void UpdateRound( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.UpdateRound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, RoundScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RoundNum, 0xFFFFFFFF )
			void UpdateTime( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.UpdateTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ScriptArray< wchar_t > FormatTime( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.FormatTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ForceUpdate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrArenaStats.ForceUpdate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
