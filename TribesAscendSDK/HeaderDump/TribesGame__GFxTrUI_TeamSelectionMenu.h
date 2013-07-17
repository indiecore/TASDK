#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrUI_TeamSelectionMenu." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrUI_TeamSelectionMenu." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrUI_TeamSelectionMenu." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrUI_TeamSelectionMenu : public GFxMoviePlayer
	{
	public:
			ADD_OBJECT( GFxObject, MovieClip )
			ADD_VAR( ::BoolProperty, bCompleted, 0x4 )
			ADD_OBJECT( GFxObject, DiamondSwordCountTF )
			ADD_OBJECT( GFxObject, BloodEagleCountTF )
			ADD_OBJECT( GFxObject, DiamondSwordButton )
			ADD_OBJECT( GFxObject, BloodEagleButton )
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_VAR( ::BoolProperty, JoinDiamondSwordAllowed, 0x10 )
			ADD_VAR( ::BoolProperty, JoinBloodEagleAllowed, 0x8 )
			ADD_VAR( ::BoolProperty, bJustJoined, 0x2 )
			ADD_VAR( ::BoolProperty, bInitialized, 0x1 )
			ADD_VAR( ::IntProperty, PrevDiamondSwordCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevBloodEagleCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AllowedTeamDiscrepancyOnTeam, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AllowedTeamDiscrepancyNoTeam, 0xFFFFFFFF )
			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Start( bool StartPaused )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.Start" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = StartPaused;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFontIndex( int FontIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.SetFontIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = FontIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Show(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.Show" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLabels( ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Spectate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.SetLabels" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Spectate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( class GameReplicationInfo* GRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameReplicationInfo** )( params + 0 ) = GRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableBloodEagle( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableBloodEagle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AsTeamChooseEnableButton( int TeamID, ScriptArray< wchar_t > bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.AsTeamChooseEnableButton" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = TeamID;
				*( ScriptArray< wchar_t >* )( params + 4 ) = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableDiamondSword( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableDiamondSword" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableSpectate( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.EnableSpectate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void choseTeamBE(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.choseTeamBE" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void choseTeamDS(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.choseTeamDS" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void choseTeamSpectate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.choseTeamSpectate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CompleteMovie( bool bHaveTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrUI_TeamSelectionMenu.CompleteMovie" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bHaveTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
