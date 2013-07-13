#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PBRuleNodeComment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PBRuleNodeComment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PBRuleNodeComment." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PBRuleNodeComment : public PBRuleNodeBase
	{
	public:
			ADD_VAR( ::BoolProperty, bFilled, 0x1 )
			ADD_VAR( ::IntProperty, BorderWidth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
