#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Settings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Settings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Settings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Settings : public Object
	{
	public:
			void UpdateFromURL( ScriptArray< wchar_t > &URL, class GameInfo* Game )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.UpdateFromURL" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				*( class GameInfo** )( params + 12 ) = Game;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )params;
			}

			void BuildURL( ScriptArray< wchar_t > &URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.BuildURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )params;
			}

			void AppendContextsToURL( ScriptArray< wchar_t > &URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.AppendContextsToURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )params;
			}

			void AppendPropertiesToURL( ScriptArray< wchar_t > &URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.AppendPropertiesToURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )params;
			}

			void AppendDataBindingsToURL( ScriptArray< wchar_t > &URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.AppendDataBindingsToURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )params;
			}

			void GetQoSAdvertisedStringSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetQoSAdvertisedStringSettings" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetQoSAdvertisedProperties(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetQoSAdvertisedProperties" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetRangedPropertyValue( int PropertyId, float &OutValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetRangedPropertyValue" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( float* )( params + 4 ) = OutValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutValue = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetRangedPropertyValue( int PropertyId, float NewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetRangedPropertyValue" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( float* )( params + 4 ) = NewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetPropertyRange( int PropertyId, float &OutMinValue, float &OutMaxValue, float &RangeIncrement, byte &bFormatAsInt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyRange" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( int* )params = PropertyId;
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

			bool GetPropertyMappingType( int PropertyId, byte &OutType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyMappingType" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( int* )params = PropertyId;
				*( byte* )( params + 4 ) = OutType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutType = *( byte* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasStringSetting( int SettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.HasStringSetting" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasProperty( int PropertyId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.HasProperty" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PropertyId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateProperties( bool bShouldAddIfMissing )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.UpdateProperties" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )( params + 12 ) = bShouldAddIfMissing;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateStringSettings( bool bShouldAddIfMissing )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.UpdateStringSettings" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )( params + 12 ) = bShouldAddIfMissing;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetPropertyType( int PropertyId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PropertyId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool GetPropertyValueId( int PropertyId, int &ValueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyValueId" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( int* )( params + 4 ) = ValueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueId = *( int* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetPropertyValueId( int PropertyId, int ValueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetPropertyValueId" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( int* )( params + 4 ) = ValueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetStringProperty( int PropertyId, ScriptArray< wchar_t > &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringProperty" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = PropertyId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetStringProperty( int PropertyId, ScriptArray< wchar_t > Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetStringProperty" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = PropertyId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetIntProperty( int PropertyId, int &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetIntProperty" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( int* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( int* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetIntProperty( int PropertyId, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetIntProperty" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( int* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetFloatProperty( int PropertyId, float &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetFloatProperty" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( float* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Value = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFloatProperty( int PropertyId, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetFloatProperty" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PropertyId;
				*( float* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetPropertyFromStringByName( ScriptName PropertyName, ScriptArray< wchar_t > &NewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetPropertyFromStringByName" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = PropertyName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = NewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewValue = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPropertyAsStringByName( ScriptName PropertyName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyAsStringByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = PropertyName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPropertyAsString( int PropertyId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyAsString" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PropertyId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPropertyColumnHeader( int PropertyId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyColumnHeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PropertyId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptName GetPropertyName( int PropertyId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PropertyId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool GetPropertyId( ScriptName PropertyName, int &PropertyId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetPropertyId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = PropertyName;
				*( int* )( params + 8 ) = PropertyId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PropertyId = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetStringSettingValueFromStringByName( ScriptName StringSettingName, ScriptArray< wchar_t > &NewValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetStringSettingValueFromStringByName" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = StringSettingName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = NewValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewValue = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetStringSettingValueNameByName( ScriptName StringSettingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingValueNameByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = StringSettingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			ScriptName GetStringSettingValueName( int StringSettingId, int ValueIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingValueName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StringSettingId;
				*( int* )( params + 4 ) = ValueIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool IsWildcardStringSetting( int StringSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.IsWildcardStringSetting" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = StringSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetStringSettingColumnHeader( int StringSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingColumnHeader" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = StringSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptName GetStringSettingName( int StringSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = StringSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool GetStringSettingId( ScriptName StringSettingName, int &StringSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = StringSettingName;
				*( int* )( params + 8 ) = StringSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				StringSettingId = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetStringSettingValueByName( ScriptName StringSettingName, int &ValueIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingValueByName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = StringSettingName;
				*( int* )( params + 8 ) = ValueIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueIndex = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetStringSettingValueByName( ScriptName StringSettingName, int ValueIndex, bool bShouldAutoAdd )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetStringSettingValueByName" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = StringSettingName;
				*( int* )( params + 8 ) = ValueIndex;
				*( bool* )( params + 12 ) = bShouldAutoAdd;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetStringSettingValueNames( int StringSettingId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingValueNames" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = StringSettingId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IncrementStringSettingValue( int StringSettingId, int Direction, bool bShouldWrap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.IncrementStringSettingValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = StringSettingId;
				*( int* )( params + 4 ) = Direction;
				*( bool* )( params + 8 ) = bShouldWrap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetStringSettingValue( int StringSettingId, int &ValueIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetStringSettingValue" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StringSettingId;
				*( int* )( params + 4 ) = ValueIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueIndex = *( int* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetStringSettingValue( int StringSettingId, int ValueIndex, bool bShouldAutoAdd )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetStringSettingValue" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = StringSettingId;
				*( int* )( params + 4 ) = ValueIndex;
				*( bool* )( params + 8 ) = bShouldAutoAdd;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetSettingsDataDateTime( void* &Data, int &OutInt1, int &OutInt2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetSettingsDataDateTime" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )params = Data;
				*( int* )( params + 12 ) = OutInt1;
				*( int* )( params + 16 ) = OutInt2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
				OutInt1 = *( int* )( params + 12 );
				OutInt2 = *( int* )( params + 16 );
			}

			void GetSettingsDataBlob( void* &Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetSettingsDataBlob" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( void** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
			}

			int GetSettingsDataInt( void* &Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetSettingsDataInt" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
				return *( int* )( params + function->return_val_offset() );
			}

			float GetSettingsDataFloat( void* &Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetSettingsDataFloat" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
				return *( float* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSettingsDataString( void* &Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.GetSettingsDataString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void EmptySettingsData( void* &Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.EmptySettingsData" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
			}

			void SetSettingsData( void* &Data, void* &Data2Copy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetSettingsData" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( void** )params = Data;
				*( void** )( params + 12 ) = Data2Copy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
				Data2Copy = *( void** )( params + 12 );
			}

			void SetSettingsDataBlob( void* &Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetSettingsDataBlob" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( void** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
			}

			void SetSettingsDataDateTime( void* &Data, int InInt1, int InInt2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetSettingsDataDateTime" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )params = Data;
				*( int* )( params + 12 ) = InInt1;
				*( int* )( params + 16 ) = InInt2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
			}

			void SetSettingsDataInt( void* &Data, int InInt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetSettingsDataInt" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )params = Data;
				*( int* )( params + 12 ) = InInt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
			}

			void SetSettingsDataFloat( void* &Data, float InFloat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetSettingsDataFloat" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )params = Data;
				*( float* )( params + 12 ) = InFloat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
			}

			void SetSettingsDataString( void* &Data, ScriptArray< wchar_t > InString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Settings.SetSettingsDataString" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( void** )params = Data;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Data = *( void** )params;
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
