#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Core.Factory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Core.Factory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Core.Factory." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Factory : public Object
	{
	public:
			ADD_VAR( ::IntProperty, AutoPriority, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bText, 0x8 )
			ADD_VAR( ::BoolProperty, bEditorImport, 0x4 )
			ADD_VAR( ::BoolProperty, bEditAfterNew, 0x2 )
			ADD_VAR( ::BoolProperty, bCreateNew, 0x1 )
			ADD_VAR( ::StrProperty, Description, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
