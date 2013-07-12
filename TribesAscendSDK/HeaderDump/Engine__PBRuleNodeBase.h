#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PBRuleNodeBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PBRuleNodeBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PBRuleNodeBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PBRuleNodeBase : public Object
	{
	public:
			ADD_VAR( ::IntProperty, DrawHeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DrawWidth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, InDrawY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RulePosY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RulePosX, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Comment, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
