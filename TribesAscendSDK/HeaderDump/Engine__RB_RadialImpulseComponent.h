#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_RadialImpulseComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_RadialImpulseComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_RadialImpulseComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_RadialImpulseComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bCauseFracture, 0x2 )
			ADD_VAR( ::BoolProperty, bVelChange, 0x1 )
			ADD_VAR( ::FloatProperty, ImpulseRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ImpulseStrength, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ImpulseFalloff, 0xFFFFFFFF )
			void FireImpulse( Vector Origin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_RadialImpulseComponent.FireImpulse" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Origin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
