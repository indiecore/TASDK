#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_Log." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_Log." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_Log." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_Log : public SequenceAction
	{
	public:
			ADD_VAR( ::StrProperty, LogMessage, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetDuration, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIncludeObjComment, 0x2 )
			ADD_VAR( ::BoolProperty, bOutputToScreen, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
