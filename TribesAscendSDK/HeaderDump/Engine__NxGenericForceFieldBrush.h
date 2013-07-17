#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NxGenericForceFieldBrush." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NxGenericForceFieldBrush." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NxGenericForceFieldBrush." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NxGenericForceFieldBrush : public Volume
	{
	public:
			ADD_VAR( ::FloatProperty, TorusRadius, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FalloffQuadratic, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FalloffLinear, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Noise, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityTarget, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityMultiplierZ, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityMultiplierY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityMultiplierX, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionTarget, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionMultiplierZ, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionMultiplierY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionMultiplierX, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Constant, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Coordinates, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RBChannel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ExcludeChannel, 0xFFFFFFFF )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NxGenericForceFieldBrush.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StopsProjectile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NxGenericForceFieldBrush.StopsProjectile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
