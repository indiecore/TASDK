#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKUIDataStore_StringAliasBindingMap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKUIDataStore_StringAliasBindingMap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKUIDataStore_StringAliasBindingMap." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasBindingMap : public UIDataStore_StringAliasMap
	{
	public:
			ADD_VAR( ::IntProperty, FakePlatform, 0xFFFFFFFF )
			int GetStringWithFieldName( ScriptArray< wchar_t > FieldName, ScriptArray< wchar_t > &MappedString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetStringWithFieldName" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = MappedString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MappedString = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetBoundStringWithFieldName( ScriptArray< wchar_t > FieldName, ScriptArray< wchar_t > &MappedString, int &StartIndex, ScriptArray< wchar_t > &BindString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetBoundStringWithFieldName" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptArray< wchar_t >* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = MappedString;
				*( int* )( params + 24 ) = StartIndex;
				*( ScriptArray< wchar_t >* )( params + 28 ) = BindString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MappedString = *( ScriptArray< wchar_t >* )( params + 12 );
				StartIndex = *( int* )( params + 24 );
				BindString = *( ScriptArray< wchar_t >* )( params + 28 );
				return *( int* )( params + function->return_val_offset() );
			}

			bool FindMappingInBoundKeyCache( ScriptArray< wchar_t > Command, ScriptArray< wchar_t > &MappingStr, int &FieldIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringAliasBindingMap.FindMappingInBoundKeyCache" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				*( ScriptArray< wchar_t >* )( params + 12 ) = MappingStr;
				*( int* )( params + 24 ) = FieldIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MappingStr = *( ScriptArray< wchar_t >* )( params + 12 );
				FieldIndex = *( int* )( params + 24 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddMappingToBoundKeyCache( ScriptArray< wchar_t > Command, ScriptArray< wchar_t > MappingStr, int FieldIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringAliasBindingMap.AddMappingToBoundKeyCache" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				*( ScriptArray< wchar_t >* )( params + 12 ) = MappingStr;
				*( int* )( params + 24 ) = FieldIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearBoundKeyCache(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringAliasBindingMap.ClearBoundKeyCache" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
