#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PBRuleNodeCycle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PBRuleNodeCycle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PBRuleNodeCycle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PBRuleNodeCycle : public PBRuleNodeBase
	{
	public:
			ADD_VAR( ::BoolProperty, bFixRepeatSize, 0x1 )
			ADD_VAR( ::IntProperty, CycleSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RepeatSize, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RepeatAxis, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
