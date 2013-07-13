#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_Delay." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_Delay." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_Delay." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_Delay : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::FloatProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Duration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultDuration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bStartWillRestart, 0x2 )
			ADD_VAR( ::BoolProperty, bDelayActive, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
