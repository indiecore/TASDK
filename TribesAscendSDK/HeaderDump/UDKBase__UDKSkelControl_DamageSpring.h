#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSkelControl_DamageSpring." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSkelControl_DamageSpring." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSkelControl_DamageSpring." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_DamageSpring : public UDKSkelControl_Damage
	{
	public:
			ADD_VAR( ::FloatProperty, MomentumPortion, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHitTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastHitMomentum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RandomPortion, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, CurrentAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AVModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpringStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Falloff, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, MinAngle, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, MaxAngle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
