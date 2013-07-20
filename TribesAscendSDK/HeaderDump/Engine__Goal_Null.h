#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Goal_Null." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Goal_Null." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Goal_Null." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Goal_Null : public PathGoalEvaluator
	{
	public:
			bool GoUntilBust( class Pawn* P, int InMaxPathVisits )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Goal_Null.GoUntilBust" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( int* )( params + 4 ) = InMaxPathVisits;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Recycle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Goal_Null.Recycle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
