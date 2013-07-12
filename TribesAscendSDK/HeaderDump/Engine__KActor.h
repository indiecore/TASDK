#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.KActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.KActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.KActor." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class KActor : public DynamicSMActor
	{
	public:
			ADD_STRUCT( ::RotatorProperty, InitialRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitialLocation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ReplicatedDrawScale3D, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngErrorAccumulator, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxPhysicsVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StayUprightMaxTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StayUprightTorqueFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastSlideTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastImpactTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDisableClientSidePawnInteractions, 0x80 )
			ADD_VAR( ::BoolProperty, bNeedsRBStateReplication, 0x40 )
			ADD_VAR( ::BoolProperty, bLimitMaxPhysicsVelocity, 0x20 )
			ADD_VAR( ::BoolProperty, bEnableStayUprightSpring, 0x10 )
			ADD_VAR( ::BoolProperty, bSlideActive, 0x8 )
			ADD_VAR( ::BoolProperty, bCurrentSlide, 0x4 )
			ADD_VAR( ::BoolProperty, bWakeOnLevelStart, 0x2 )
			ADD_VAR( ::BoolProperty, bDamageAppliesImpulse, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
