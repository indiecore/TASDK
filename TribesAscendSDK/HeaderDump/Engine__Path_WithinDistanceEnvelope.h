#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Path_WithinDistanceEnvelope." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Path_WithinDistanceEnvelope." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Path_WithinDistanceEnvelope." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Path_WithinDistanceEnvelope : public PathConstraint
	{
	public:
			ADD_STRUCT( ::VectorProperty, EnvelopeTestPoint, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SoftStartPenalty, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOnlyThrowOutNodesThatLeaveEnvelope, 0x2 )
			ADD_VAR( ::BoolProperty, bSoft, 0x1 )
			ADD_VAR( ::FloatProperty, MinDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDistance, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
