#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider_OnlinePlayerStorage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider_OnlinePlayerStorage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider_OnlinePlayerStorage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerStorage : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
			ADD_VAR( ::IntProperty, DeviceStorageSizeNeeded, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWasErrorLastRead, 0x1 )
			ADD_VAR( ::NameProperty, ProviderName, 0xFFFFFFFF )
			ADD_OBJECT( OnlinePlayerStorage, Profile )
			bool ReadData( byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.ReadData" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				*( int* )( params + 12 ) = DeviceID;
				*( class OnlinePlayerStorage** )( params + 16 ) = PlayerStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WriteData( byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.WriteData" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				*( int* )( params + 12 ) = DeviceID;
				*( class OnlinePlayerStorage** )( params + 16 ) = PlayerStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetData( byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.GetData" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				*( class OnlinePlayerStorage** )( params + 12 ) = PlayerStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.AddReadCompleteDelegate" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.ClearReadCompleteDelegate" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRegister( class LocalPlayer* InPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.OnRegister" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = InPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregister(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.OnUnregister" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadStorageComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.OnReadStorageComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshStorageData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.RefreshStorageData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDeviceSelectionComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.OnDeviceSelectionComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ArrayProviderPropertyChanged( class UIDataProvider* SourceProvider, ScriptName PropTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.ArrayProviderPropertyChanged" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UIDataProvider** )params = SourceProvider;
				*( ScriptName* )( params + 4 ) = PropTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSettingValueUpdated( ScriptName SettingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.OnSettingValueUpdated" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SettingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStorageDeviceChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlinePlayerStorage.OnStorageDeviceChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
