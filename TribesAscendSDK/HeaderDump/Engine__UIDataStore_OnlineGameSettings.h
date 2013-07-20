#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_OnlineGameSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_OnlineGameSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_OnlineGameSettings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_OnlineGameSettings : public UIDataStore_Settings
	{
	public:
			ADD_VAR( ::IntProperty, SelectedIndex, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, SettingsProviderClass )
			void OnSettingProviderChanged( class UIDataProvider* SourceProvider, ScriptName SettingsName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.OnSettingProviderChanged" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UIDataProvider** )params = SourceProvider;
				*( ScriptName* )( params + 4 ) = SettingsName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CreateGame( byte ControllerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.CreateGame" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = ControllerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class OnlineGameSettings* GetCurrentGameSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.GetCurrentGameSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSettings** )( params + function->return_val_offset() );
			}

			class UIDataProvider_Settings* GetCurrentProvider(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.GetCurrentProvider" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UIDataProvider_Settings** )( params + function->return_val_offset() );
			}

			void SetCurrentByIndex( int NewIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.SetCurrentByIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NewIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCurrentByName( ScriptName SettingsName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.SetCurrentByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SettingsName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveToNext(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.MoveToNext" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveToPrevious(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.MoveToPrevious" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Registered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.Registered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Unregistered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSettings.Unregistered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
