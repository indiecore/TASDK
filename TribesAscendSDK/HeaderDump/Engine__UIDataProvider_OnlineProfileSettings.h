#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider_OnlineProfileSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider_OnlineProfileSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider_OnlineProfileSettings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlineProfileSettings : public UIDataProvider_OnlinePlayerStorage
	{
	public:
			bool ReadData( byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineProfileSettings.ReadData" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineProfileSettings.WriteData" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineProfileSettings.GetData" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				*( class OnlinePlayerStorage** )( params + 12 ) = PlayerStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineProfileSettings.AddReadCompleteDelegate" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineProfileSettings.ClearReadCompleteDelegate" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 8 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshStorageData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineProfileSettings.RefreshStorageData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
