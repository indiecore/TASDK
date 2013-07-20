#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGameReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGameReplicationInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGameReplicationInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGameReplicationInfo : public GameReplicationInfo
	{
	public:
			ADD_VAR( ::BoolProperty, bStoryMode, 0x4 )
			ADD_VAR( ::BoolProperty, bAnnouncementsDisabled, 0x20 )
			ADD_VAR( ::StrProperty, MessageOfTheDay, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bConsoleServer, 0x8 )
			ADD_VAR( ::BoolProperty, bAllowKeyboardAndMouse, 0x10 )
			ADD_VAR( ::IntProperty, BotDifficulty, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinNetPlayers, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRequireReady, 0x40 )
			ADD_VAR( ::StrProperty, MutatorList, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesString, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWarmupRound, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool InOrder( class PlayerReplicationInfo* P1, class PlayerReplicationInfo* P2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.InOrder" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )params = P1;
				*( class PlayerReplicationInfo** )( params + 4 ) = P2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SortPRIArray(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.SortPRIArray" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CharacterProcessingComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.CharacterProcessingComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlagHome( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.SetFlagHome" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, FlagState, 0xFFFFFFFF )
			bool FlagIsHome( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.FlagIsHome" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FlagsAreHome(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.FlagsAreHome" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFlagHeldFriendly( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.SetFlagHeldFriendly" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FlagIsHeldFriendly( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.FlagIsHeldFriendly" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFlagHeldEnemy( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.SetFlagHeldEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FlagIsHeldEnemy( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.FlagIsHeldEnemy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFlagDown( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.SetFlagDown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FlagIsDown( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.FlagIsDown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMidGameMenu( class UTPlayerController* InstigatorPC, ScriptName TabTag, bool bEnableInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.ShowMidGameMenu" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTPlayerController** )params = InstigatorPC;
				*( ScriptName* )( params + 4 ) = TabTag;
				*( bool* )( params + 12 ) = bEnableInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHudShowScores( bool bShow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.SetHudShowScores" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bShow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddGameRule( ScriptArray< wchar_t > Rule )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameReplicationInfo.AddGameRule" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Rule;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, WeaponBerserk, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceDefaultCharacter, 0x2 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
