#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshGoalFilter_NotNearOtherAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshGoalFilter_NotNearOtherAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshGoalFilter_NotNearOtherAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshGoalFilter_NotNearOtherAI : public NavMeshGoal_Filter
	{
	public:
			ADD_VAR( ::FloatProperty, DistanceToCheck, 0xFFFFFFFF )
			bool NotNearOtherAI( class NavMeshGoal_GenericFilterContainer* FilterContainer, float InDistanceToCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoalFilter_NotNearOtherAI.NotNearOtherAI" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavMeshGoal_GenericFilterContainer** )params = FilterContainer;
				*( float* )( params + 4 ) = InDistanceToCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
