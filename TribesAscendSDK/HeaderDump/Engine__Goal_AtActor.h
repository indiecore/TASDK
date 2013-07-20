#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Goal_AtActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Goal_AtActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Goal_AtActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Goal_AtActor : public PathGoalEvaluator
	{
	public:
			ADD_VAR( ::BoolProperty, bKeepPartial, 0x1 )
			ADD_VAR( ::FloatProperty, GoalDist, 0xFFFFFFFF )
			ADD_OBJECT( Actor, GoalActor )
			bool AtActor( class Pawn* P, class Actor* Goal, float Dist, bool bReturnPartial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Goal_AtActor.AtActor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Pawn** )params = P;
				*( class Actor** )( params + 4 ) = Goal;
				*( float* )( params + 8 ) = Dist;
				*( bool* )( params + 12 ) = bReturnPartial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Goal_AtActor.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
