#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_ModifyHealth." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_ModifyHealth." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_ModifyHealth." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ModifyHealth : public SequenceAction
	{
	public:
			ADD_OBJECT( Actor, Instigator )
			ADD_VAR( ::BoolProperty, bHeal, 0x1 )
			ADD_VAR( ::FloatProperty, Amount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Momentum, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bFalloff, 0x4 )
			ADD_VAR( ::BoolProperty, bRadial, 0x2 )
			ADD_VAR( ::FloatProperty, Radius, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
