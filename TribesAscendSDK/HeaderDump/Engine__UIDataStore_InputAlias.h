#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_InputAlias." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_InputAlias." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_InputAlias." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_InputAlias : public UIDataStore_StringBase
	{
	public:
			ScriptArray< wchar_t > GetAliasFontMarkup( ScriptName DesiredAlias, byte OverridePlatform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.GetAliasFontMarkup" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )params = DesiredAlias;
				*( byte* )( params + 8 ) = OverridePlatform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetAliasFontMarkupByIndex( int AliasIndex, byte OverridePlatform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.GetAliasFontMarkupByIndex" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( int* )params = AliasIndex;
				*( byte* )( params + 4 ) = OverridePlatform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptName GetAliasInputKeyName( ScriptName DesiredAlias, byte OverridePlatform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.GetAliasInputKeyName" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )params = DesiredAlias;
				*( byte* )( params + 8 ) = OverridePlatform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			ScriptName GetAliasInputKeyNameByIndex( int AliasIndex, byte OverridePlatform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.GetAliasInputKeyNameByIndex" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( int* )params = AliasIndex;
				*( byte* )( params + 4 ) = OverridePlatform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			bool GetAliasInputKeyData( void* &out_InputKeyData, ScriptName DesiredAlias, byte OverridePlatform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.GetAliasInputKeyData" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( void** )params = out_InputKeyData;
				*( ScriptName* )( params + 12 ) = DesiredAlias;
				*( byte* )( params + 20 ) = OverridePlatform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_InputKeyData = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetAliasInputKeyDataByIndex( void* &out_InputKeyData, int AliasIndex, byte OverridePlatform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.GetAliasInputKeyDataByIndex" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( void** )params = out_InputKeyData;
				*( int* )( params + 12 ) = AliasIndex;
				*( byte* )( params + 16 ) = OverridePlatform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_InputKeyData = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindInputAliasIndex( ScriptName DesiredAlias )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.FindInputAliasIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = DesiredAlias;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool HasAliasMappingForPlatform( ScriptName DesiredAlias, byte DesiredPlatform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_InputAlias.HasAliasMappingForPlatform" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )params = DesiredAlias;
				*( byte* )( params + 8 ) = DesiredPlatform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
