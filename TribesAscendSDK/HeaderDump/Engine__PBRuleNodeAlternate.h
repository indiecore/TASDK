#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PBRuleNodeAlternate." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PBRuleNodeAlternate." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PBRuleNodeAlternate." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PBRuleNodeAlternate : public PBRuleNodeBase
	{
	public:
			ADD_VAR( ::BoolProperty, bEqualSizeAB, 0x2 )
			ADD_VAR( ::BoolProperty, bInvertPatternOrder, 0x1 )
			ADD_VAR( ::FloatProperty, BMaxSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ASize, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RepeatAxis, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
