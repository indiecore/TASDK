#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Path_TowardGoal." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Path_TowardGoal." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Path_TowardGoal." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Path_TowardGoal : public PathConstraint
	{
	public:
			ADD_OBJECT( Actor, GoalActor )
			bool TowardGoal( class Pawn* P, class Actor* Goal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Path_TowardGoal.TowardGoal" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( class Actor** )( params + 4 ) = Goal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Path_TowardGoal.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
