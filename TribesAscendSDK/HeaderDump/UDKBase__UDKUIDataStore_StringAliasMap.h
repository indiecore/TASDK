#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKUIDataStore_StringAliasMap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKUIDataStore_StringAliasMap." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKUIDataStore_StringAliasMap." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasMap : public UIDataStore_StringAliasMap
	{
	public:
			ADD_VAR( ::IntProperty, FakePlatform, 0xFFFFFFFF )
			int GetStringWithFieldName( ScriptArray< wchar_t > FieldName, ScriptArray< wchar_t > &MappedString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringAliasMap.GetStringWithFieldName" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = MappedString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MappedString = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
