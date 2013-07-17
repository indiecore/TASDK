#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshGoalFilter_OutSideOfDotProductWedge." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshGoalFilter_OutSideOfDotProductWedge." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshGoalFilter_OutSideOfDotProductWedge." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshGoalFilter_OutSideOfDotProductWedge : public NavMeshGoal_Filter
	{
	public:
			ADD_VAR( ::FloatProperty, Epsilon, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Rotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Location, 0xFFFFFFFF )
			bool OutsideOfDotProductWedge( class NavMeshGoal_GenericFilterContainer* FilterContainer, Vector InLocation, Rotator InRotation, float InEpsilon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoalFilter_OutSideOfDotProductWedge.OutsideOfDotProductWedge" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class NavMeshGoal_GenericFilterContainer** )( params + 0 ) = FilterContainer;
				*( Vector* )( params + 4 ) = InLocation;
				*( Rotator* )( params + 16 ) = InRotation;
				*( float* )( params + 28 ) = InEpsilon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
