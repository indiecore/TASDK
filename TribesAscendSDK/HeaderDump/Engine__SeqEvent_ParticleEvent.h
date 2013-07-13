#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqEvent_ParticleEvent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqEvent_ParticleEvent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqEvent_ParticleEvent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_ParticleEvent : public SequenceEvent
	{
	public:
			ADD_VAR( ::BoolProperty, UseRelfectedImpactVector, 0x1 )
			ADD_STRUCT( ::VectorProperty, EventNormal, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EventParticleTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EventVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EventEmitterTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EventPosition, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, EventType, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
