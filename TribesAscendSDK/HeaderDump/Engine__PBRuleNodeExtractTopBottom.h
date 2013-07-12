#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PBRuleNodeExtractTopBottom." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PBRuleNodeExtractTopBottom." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PBRuleNodeExtractTopBottom." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PBRuleNodeExtractTopBottom : public PBRuleNodeBase
	{
	public:
			ADD_VAR( ::FloatProperty, ExtractNotBottomZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExtractBottomZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExtractNotTopZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExtractTopZ, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
