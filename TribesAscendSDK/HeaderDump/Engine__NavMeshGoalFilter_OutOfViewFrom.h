#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshGoalFilter_OutOfViewFrom." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshGoalFilter_OutOfViewFrom." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshGoalFilter_OutOfViewFrom." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshGoalFilter_OutOfViewFrom : public NavMeshGoal_Filter
	{
	public:
			ADD_STRUCT( ::VectorProperty, OutOfViewLocation, 0xFFFFFFFF )
			bool MustBeHiddenFromThisPoint( class NavMeshGoal_GenericFilterContainer* FilterContainer, Vector InOutOfViewLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoalFilter_OutOfViewFrom.MustBeHiddenFromThisPoint" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class NavMeshGoal_GenericFilterContainer** )params = FilterContainer;
				*( Vector* )( params + 4 ) = InOutOfViewLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
