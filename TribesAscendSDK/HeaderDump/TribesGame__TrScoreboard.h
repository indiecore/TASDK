#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrScoreboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrScoreboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrScoreboard." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrScoreboard : public Object
	{
	public:
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::BoolProperty, bIsActive, 0x8 )
			int CreditsSort( class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.CreditsSort" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerReplicationInfo** )params = A;
				*( class TrPlayerReplicationInfo** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int AssistsSort( class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.AssistsSort" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerReplicationInfo** )params = A;
				*( class TrPlayerReplicationInfo** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int KillsSort( class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.KillsSort" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerReplicationInfo** )params = A;
				*( class TrPlayerReplicationInfo** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_VAR( ::BoolProperty, bCheckPing, 0x10 )
			ADD_VAR( ::BoolProperty, bInitialized, 0x4 )
			ADD_VAR( ::BoolProperty, bUpdated, 0x2 )
			ADD_VAR( ::BoolProperty, bTeamGame, 0x1 )
			ADD_VAR( ::IntProperty, DSIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BEIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DSOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevActiveSlot, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevDSSLots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevBESlots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DSSlots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BESlots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAX_PLAYER_INDEX, 0xFFFFFFFF )
			void Initialize( class TrPlayerController* PC, class GfxTrHud* MP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.Initialize" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerController** )params = PC;
				*( class GfxTrHud** )( params + 4 ) = MP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Show( bool bIsTeamGame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.Show" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIsTeamGame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Hide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.Hide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConfigScoreboard(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.ConfigScoreboard" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePRILists( class TrGameReplicationInfo* TrGRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.UpdatePRILists" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = TrGRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetBestSortArray(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.GetBestSortArray" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			int GetRank(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.GetRank" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool ClearSlot( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.ClearSlot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UpdateSlot( int Index, class TrPlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.UpdateSlot" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Index;
				*( class TrPlayerReplicationInfo** )( params + 4 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > FormatTime( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.FormatTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void UpdateHeaders( class TrGameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.UpdateHeaders" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrGameReplicationInfo** )params = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsValidScoreboardPlayer( class TrPlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrScoreboard.IsValidScoreboardPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
