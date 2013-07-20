#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshGoal_PolyEncompassesAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshGoal_PolyEncompassesAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshGoal_PolyEncompassesAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshGoal_PolyEncompassesAI : public NavMeshPathGoalEvaluator
	{
	public:
			ADD_STRUCT( ::VectorProperty, OverrideExtentToCheck, 0xFFFFFFFF )
			bool MakeSureAIFits( class NavigationHandle* NavHandle, Vector InOverrideExtentToCheck )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_PolyEncompassesAI.MakeSureAIFits" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class NavigationHandle** )params = NavHandle;
				*( Vector* )( params + 4 ) = InOverrideExtentToCheck;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_PolyEncompassesAI.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
