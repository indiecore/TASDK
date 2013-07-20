#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKUIDataStore_MenuItems." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKUIDataStore_MenuItems." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKUIDataStore_MenuItems." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKUIDataStore_MenuItems : public UIDataStore_GameResource
	{
	public:
			ADD_VAR( ::IntProperty, GameModeFilter, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, MapInfoDataProviderClass )
			int GetProviderCount( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.GetProviderCount" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool IsProviderFiltered( ScriptName FieldName, int ProviderIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.IsProviderFiltered" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = FieldName;
				*( int* )( params + 8 ) = ProviderIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetAllResourceDataProviders( ScriptClass* ProviderClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.GetAllResourceDataProviders" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = ProviderClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindValueInProviderSet( ScriptName ProviderFieldName, ScriptName SearchTag, ScriptArray< wchar_t > SearchValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.FindValueInProviderSet" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )params = ProviderFieldName;
				*( ScriptName* )( params + 8 ) = SearchTag;
				*( ScriptArray< wchar_t >* )( params + 16 ) = SearchValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool GetValueFromProviderSet( ScriptName ProviderFieldName, ScriptName SearchTag, int ListIndex, ScriptArray< wchar_t > &OutValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.GetValueFromProviderSet" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )params = ProviderFieldName;
				*( ScriptName* )( params + 8 ) = SearchTag;
				*( int* )( params + 16 ) = ListIndex;
				*( ScriptArray< wchar_t >* )( params + 20 ) = OutValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutValue = *( ScriptArray< wchar_t >* )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProviderSet( ScriptName ProviderFieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.GetProviderSet" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ProviderFieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InitializeListElementProviders(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.InitializeListElementProviders" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveListElementProvidersKey( ScriptName KeyName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.RemoveListElementProvidersKey" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = KeyName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddListElementProvidersKey( ScriptName KeyName, class UDKUIResourceDataProvider* Provider )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_MenuItems.AddListElementProvidersKey" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = KeyName;
				*( class UDKUIResourceDataProvider** )( params + 8 ) = Provider;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
