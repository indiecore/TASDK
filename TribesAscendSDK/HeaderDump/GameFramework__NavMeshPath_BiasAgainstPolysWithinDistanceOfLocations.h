#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations : public NavMeshPathConstraint
	{
	public:
			ADD_VAR( ::FloatProperty, DistanceToCheck, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Rotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Location, 0xFFFFFFFF )
			bool BiasAgainstPolysWithinDistanceOfLocations( class NavigationHandle* NavHandle, Vector InLocation, Rotator InRotation, float InDistanceToCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.BiasAgainstPolysWithinDistanceOfLocations" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class NavigationHandle** )params = NavHandle;
				*( Vector* )( params + 4 ) = InLocation;
				*( Rotator* )( params + 16 ) = InRotation;
				*( float* )( params + 28 ) = InDistanceToCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
