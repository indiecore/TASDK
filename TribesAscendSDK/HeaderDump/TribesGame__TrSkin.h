#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrSkin." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrSkin." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrSkin." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSkin : public Object
	{
	public:
			ADD_VAR( ::StrProperty, ItemName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, InfoPanelDescription, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TranslucencySortPriority, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ItemId, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, SkinMeleeDevice )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
