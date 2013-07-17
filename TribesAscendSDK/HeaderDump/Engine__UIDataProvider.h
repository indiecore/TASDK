#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider : public UIRoot
	{
	public:
			void OnDataProviderPropertyChange( class UIDataProvider* SourceProvider, ScriptName PropTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.OnDataProviderPropertyChange" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UIDataProvider** )( params + 0 ) = SourceProvider;
				*( ScriptName* )( params + 4 ) = PropTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, WriteAccessType, 0xFFFFFFFF )
			bool GetProviderFieldType( ScriptArray< wchar_t > DataTag, byte &out_ProviderFieldType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.GetProviderFieldType" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = DataTag;
				*( byte* )( params + 12 ) = out_ProviderFieldType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ProviderFieldType = *( byte* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			int ParseArrayDelimiter( ScriptArray< wchar_t > &DataTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.ParseArrayDelimiter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = DataTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DataTag = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			void GetSupportedScriptFields(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.GetSupportedScriptFields" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowPublishingToField( ScriptArray< wchar_t > FieldName, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.AllowPublishingToField" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = FieldName;
				*( int* )( params + 12 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetFieldValue( ScriptArray< wchar_t > FieldName, void* &FieldValue, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.GetFieldValue" );
				byte *params = ( byte* )( malloc( 100 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = FieldName;
				*( void** )( params + 12 ) = FieldValue;
				*( int* )( params + 96 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FieldValue = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetFieldValue( ScriptArray< wchar_t > FieldName, void* &FieldValue, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.SetFieldValue" );
				byte *params = ( byte* )( malloc( 100 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = FieldName;
				*( void** )( params + 12 ) = FieldValue;
				*( int* )( params + 96 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FieldValue = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GenerateScriptMarkupString( ScriptName DataTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.GenerateScriptMarkupString" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = DataTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GenerateFillerData( ScriptArray< wchar_t > DataTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.GenerateFillerData" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = DataTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool IsProviderDisabled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.IsProviderDisabled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsCollectionDataType( byte FieldType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.IsCollectionDataType" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FieldType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyPropertyChanged( ScriptName PropTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.NotifyPropertyChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = PropTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AddPropertyNotificationChangeRequest( bool bAllowDuplicates )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.AddPropertyNotificationChangeRequest" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )( params + 12 ) = bAllowDuplicates;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemovePropertyNotificationChangeRequest(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.RemovePropertyNotificationChangeRequest" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int ParseTagArrayDelimiter( ScriptName &FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider.ParseTagArrayDelimiter" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FieldName = *( ScriptName* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
