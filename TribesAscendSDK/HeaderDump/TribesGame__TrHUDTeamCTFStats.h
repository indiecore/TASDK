#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrHUDTeamCTFStats." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrHUDTeamCTFStats." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrHUDTeamCTFStats." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrHUDTeamCTFStats : public Object
	{
	public:
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::BoolProperty, bIsActive, 0x1 )
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_OBJECT( PlayerReplicationInfo, FlagHolderPRI )
			ADD_VAR( ::ByteProperty, bEmptyFlagStatus, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FlagState, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GeneratorDowntime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GeneratorPower, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TeamScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FlagReturnTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MyTeam, 0xFFFFFFFF )
			void Initialize( class TrPlayerController* PC, class GfxTrHud* MP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.Initialize" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerController** )params = PC;
				*( class GfxTrHud** )( params + 4 ) = MP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Show(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.Show" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Hide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.Hide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.Tick" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.UpdateTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetTeamIndex( int I )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.GetTeamIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = I;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void UpdateFlagStatus( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.UpdateFlagStatus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGeneratorStatus( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.UpdateGeneratorStatus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTeamScore( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.UpdateTeamScore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateTime( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.UpdateTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > FormatTime( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.FormatTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ForceUpdate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrHUDTeamCTFStats.ForceUpdate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
