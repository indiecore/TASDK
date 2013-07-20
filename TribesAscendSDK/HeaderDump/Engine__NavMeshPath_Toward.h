#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshPath_Toward." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshPath_Toward." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshPath_Toward." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPath_Toward : public NavMeshPathConstraint
	{
	public:
			ADD_STRUCT( ::VectorProperty, GoalPoint, 0xFFFFFFFF )
			ADD_OBJECT( Actor, GoalActor )
			bool TowardGoal( class NavigationHandle* NavHandle, class Actor* Goal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_Toward.TowardGoal" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class NavigationHandle** )params = NavHandle;
				*( class Actor** )( params + 4 ) = Goal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TowardPoint( class NavigationHandle* NavHandle, Vector Point )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_Toward.TowardPoint" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class NavigationHandle** )params = NavHandle;
				*( Vector* )( params + 4 ) = Point;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.NavMeshPath_Toward.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
