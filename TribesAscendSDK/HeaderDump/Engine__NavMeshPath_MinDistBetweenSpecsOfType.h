#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPath_MinDistBetweenSpecsOfType : public NavMeshPathConstraint
	{
	public:
			ADD_VAR( ::ByteProperty, EdgeType, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinDistBetweenEdgeTypes, 0xFFFFFFFF )
			bool EnforceMinDist( class NavigationHandle* NavHandle, float InMinDist, byte InEdgeType, Vector LastLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_MinDistBetweenSpecsOfType.EnforceMinDist" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( class NavigationHandle** )( params + 0 ) = NavHandle;
				*( float* )( params + 4 ) = InMinDist;
				*( byte* )( params + 8 ) = InEdgeType;
				*( Vector* )( params + 12 ) = LastLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_MinDistBetweenSpecsOfType.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
