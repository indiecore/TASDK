#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_ActivateRemoteEvent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_ActivateRemoteEvent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_ActivateRemoteEvent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ActivateRemoteEvent : public SequenceAction
	{
	public:
			ADD_VAR( ::BoolProperty, bStatusIsOk, 0x1 )
			ADD_VAR( ::NameProperty, EventName, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Instigator )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
