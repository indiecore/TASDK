#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlinePlayerStorage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlinePlayerStorage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlinePlayerStorage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlayerStorage : public Object
	{
	public:
			ADD_VAR( ::IntProperty, DeviceID, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AsyncState, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VersionNumber, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VersionSettingsId, 0xFFFFFFFF )
			bool GetProfileSettingId( ScriptName ProfileSettingName, int &ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = ProfileSettingName;
				*( int* )( params + 8 ) = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ProfileSettingId = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetProfileSettingName( int ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetProfileSettingColumnHeader( int ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingColumnHeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int FindProfileSettingIndex( int ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.FindProfileSettingIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int FindProfileMappingIndex( int ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.FindProfileMappingIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int FindProfileMappingIndexByName( ScriptName ProfileSettingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.FindProfileMappingIndexByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = ProfileSettingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int FindDefaultProfileMappingIndexByName( ScriptName ProfileSettingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.FindDefaultProfileMappingIndexByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = ProfileSettingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool IsProfileSettingIdMapped( int ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.IsProfileSettingIdMapped" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingValue( int ProfileSettingId, ScriptArray< wchar_t > &Value, int ValueMapID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValue" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = ProfileSettingId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Value;
				*( int* )( params + 16 ) = ValueMapID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetProfileSettingValueName( int ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValueName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingValues( int ProfileSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValues" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = ProfileSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingValueByName( ScriptName ProfileSettingName, ScriptArray< wchar_t > &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValueByName" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ProfileSettingName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetProfileSettingValueByName( ScriptName ProfileSettingName, ScriptArray< wchar_t > &NewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetProfileSettingValueByName" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ProfileSettingName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = NewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewValue = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetProfileSettingValue( int ProfileSettingId, ScriptArray< wchar_t > &NewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetProfileSettingValue" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = ProfileSettingId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = NewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewValue = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingValueId( int ProfileSettingId, int &ValueId, int &ListIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValueId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ProfileSettingId;
				*( int* )( params + 4 ) = ValueId;
				*( int* )( params + 8 ) = ListIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueId = *( int* )( params + 4 );
				ListIndex = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingValueFromListIndex( int ProfileSettingId, int ListIndex, int &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValueFromListIndex" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ProfileSettingId;
				*( int* )( params + 4 ) = ListIndex;
				*( int* )( params + 8 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingValueInt( int ProfileSettingId, int &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValueInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileSettingId;
				*( int* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( int* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingValueFloat( int ProfileSettingId, float &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingValueFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileSettingId;
				*( float* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetProfileSettingValueId( int ProfileSettingId, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetProfileSettingValueId" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileSettingId;
				*( int* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetProfileSettingValueInt( int ProfileSettingId, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetProfileSettingValueInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileSettingId;
				*( int* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetProfileSettingValueFloat( int ProfileSettingId, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetProfileSettingValueFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileSettingId;
				*( float* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingMappingType( int ProfileId, byte &OutType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingMappingType" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( int* )params = ProfileId;
				*( byte* )( params + 4 ) = OutType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutType = *( byte* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingMappingIds( int ProfileId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingMappingIds" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = ProfileId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingRange( int ProfileId, float &OutMinValue, float &OutMaxValue, float &RangeIncrement, byte &bFormatAsInt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetProfileSettingRange" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( int* )params = ProfileId;
				*( float* )( params + 4 ) = OutMinValue;
				*( float* )( params + 8 ) = OutMaxValue;
				*( float* )( params + 12 ) = RangeIncrement;
				*( byte* )( params + 16 ) = bFormatAsInt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutMinValue = *( float* )( params + 4 );
				OutMaxValue = *( float* )( params + 8 );
				RangeIncrement = *( float* )( params + 12 );
				bFormatAsInt = *( byte* )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetRangedProfileSettingValue( int ProfileId, float NewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetRangedProfileSettingValue" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileId;
				*( float* )( params + 4 ) = NewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetRangedProfileSettingValue( int ProfileId, float &OutValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetRangedProfileSettingValue" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileId;
				*( float* )( params + 4 ) = OutValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutValue = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddSettingInt( int SettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.AddSettingInt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddSettingFloat( int SettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.AddSettingFloat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetToDefaults(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetToDefaults" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AppendVersionToSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.AppendVersionToSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetVersionNumber(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.GetVersionNumber" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetDefaultVersionNumber(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerStorage.SetDefaultVersionNumber" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
