#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NxForceFieldTornado." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NxForceFieldTornado." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NxForceFieldTornado." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NxForceFieldTornado : public NxForceField
	{
	public:
			ADD_VAR( ::FloatProperty, SelfRotationStrength, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, BSpecialRadialForceMode, 0x1 )
			ADD_VAR( ::FloatProperty, HeightOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EscapeVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LiftFalloffHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceTopRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LiftStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotationalStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RadialStrength, 0xFFFFFFFF )
			ADD_OBJECT( ForceFieldShape, Shape )
			void DoInitRBPhys(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NxForceFieldTornado.DoInitRBPhys" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
