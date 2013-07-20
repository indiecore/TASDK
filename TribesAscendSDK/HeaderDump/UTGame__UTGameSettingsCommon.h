#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGameSettingsCommon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGameSettingsCommon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGameSettingsCommon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGameSettingsCommon : public UDKGameSettingsCommon
	{
	public:
			ADD_VAR( ::IntProperty, MaxPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinNetPlayers, 0xFFFFFFFF )
			void SetCustomMapName( ScriptArray< wchar_t > MapName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameSettingsCommon.SetCustomMapName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = MapName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOfficialMutatorBitmask( int MutatorBitmask )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameSettingsCommon.SetOfficialMutatorBitmask" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = MutatorBitmask;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BuildURL( ScriptArray< wchar_t > &OutURL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameSettingsCommon.BuildURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = OutURL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutURL = *( ScriptArray< wchar_t >* )params;
			}

			void UpdateFromURL( ScriptArray< wchar_t > &URL, class GameInfo* Game )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameSettingsCommon.UpdateFromURL" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				*( class GameInfo** )( params + 12 ) = Game;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )params;
			}

			void SetMutators( ScriptArray< wchar_t > &URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameSettingsCommon.SetMutators" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )params;
			}

			int GenerateMutatorBitmaskFromURL( class UTUIDataStore_MenuItems* MenuDataStore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameSettingsCommon.GenerateMutatorBitmaskFromURL" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTUIDataStore_MenuItems** )params = MenuDataStore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetCustomMutators( class UTUIDataStore_MenuItems* MenuDataStore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGameSettingsCommon.SetCustomMutators" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTUIDataStore_MenuItems** )params = MenuDataStore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
