#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_RadialForceActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_RadialForceActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_RadialForceActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_RadialForceActor : public RigidBodyBase
	{
	public:
			ADD_VAR( ::BoolProperty, bForceActive, 0x1 )
			ADD_VAR( ::BoolProperty, bForceApplyToProjectiles, 0x10 )
			ADD_VAR( ::BoolProperty, bForceApplyToRigidBodies, 0x8 )
			ADD_VAR( ::BoolProperty, bForceApplyToFluid, 0x4 )
			ADD_VAR( ::BoolProperty, bForceApplyToCloth, 0x2 )
			ADD_VAR( ::ByteProperty, RadialForceMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ForceFalloff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpinTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SwirlStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceStrength, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
