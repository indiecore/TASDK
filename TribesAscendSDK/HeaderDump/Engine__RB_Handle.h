#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_Handle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_Handle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_Handle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_Handle : public ActorComponent
	{
	public:
			ADD_STRUCT( ::VectorProperty, Location, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, StepSize, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Destination, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularDamping, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LinearDampingScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LinearStiffnessScale3D, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearStiffness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDamping, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInterpolating, 0x4 )
			ADD_VAR( ::BoolProperty, bRotationConstrained, 0x2 )
			ADD_VAR( ::BoolProperty, bInHardware, 0x1 )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, GrabbedBoneName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
