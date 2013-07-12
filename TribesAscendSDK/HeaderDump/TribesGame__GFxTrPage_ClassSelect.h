#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage_ClassSelect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage_ClassSelect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage_ClassSelect." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_ClassSelect : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bClassDeniedPopup, 0x1 )
			ADD_VAR( ::IntProperty, XPAmount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GPAmount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PurchasingClass, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FocusedClass, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
