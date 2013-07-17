#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSkelControl_CantileverBeam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSkelControl_CantileverBeam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSkelControl_CantileverBeam." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSkelControl_CantileverBeam : public SkelControlLookAt
	{
	public:
			Vector EntireBeamVelocity(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKSkelControl_CantileverBeam.EntireBeamVelocity" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, PercentBeamVelocityTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpringDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpringStiffness, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Velocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitialWorldSpaceGoalOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, WorldSpaceGoal, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
