#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_Trace." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_Trace." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_Trace." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_Trace : public SequenceAction
	{
	public:
			ADD_STRUCT( ::VectorProperty, HitLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Distance, 0xFFFFFFFF )
			ADD_OBJECT( Object, HitObject )
			ADD_STRUCT( ::VectorProperty, EndOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StartOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TraceExtent, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bTraceWorld, 0x2 )
			ADD_VAR( ::BoolProperty, bTraceActors, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
