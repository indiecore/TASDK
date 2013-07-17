#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshGoal_At." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshGoal_At." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshGoal_At." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshGoal_At : public NavMeshPathGoalEvaluator
	{
	public:
			ADD_VAR( ::BoolProperty, bKeepPartial, 0x1 )
			ADD_VAR( ::FloatProperty, GoalDist, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Goal, 0xFFFFFFFF )
			void RecycleNative(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_At.RecycleNative" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AtActor( class NavigationHandle* NavHandle, class Actor* GoalActor, float Dist, bool bReturnPartial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_At.AtActor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class NavigationHandle** )( params + 0 ) = NavHandle;
				*( class Actor** )( params + 4 ) = GoalActor;
				*( float* )( params + 8 ) = Dist;
				*( bool* )( params + 12 ) = bReturnPartial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AtLocation( class NavigationHandle* NavHandle, Vector GoalLocation, float Dist, bool bReturnPartial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_At.AtLocation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class NavigationHandle** )( params + 0 ) = NavHandle;
				*( Vector* )( params + 4 ) = GoalLocation;
				*( float* )( params + 16 ) = Dist;
				*( bool* )( params + 20 ) = bReturnPartial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshGoal_At.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
