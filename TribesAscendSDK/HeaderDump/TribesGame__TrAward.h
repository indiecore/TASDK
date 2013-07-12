#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAward." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAward." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAward." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAward : public Object
	{
	public:
			ADD_VAR( ::StrProperty, Units, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TitleTier3, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TitleTier2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TitleTier1, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Weight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TierLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DatabaseId, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
