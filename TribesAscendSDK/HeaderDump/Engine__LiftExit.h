#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LiftExit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LiftExit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LiftExit." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LiftExit : public NavigationPoint
	{
	public:
			bool CanBeReachedFromLiftBy( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LiftExit.CanBeReachedFromLiftBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bExitOnly, 0x1 )
			ADD_OBJECT( LiftCenter, MyLiftCenter )
			void WaitForLift( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LiftExit.WaitForLift" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SuggestMovePreparation( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.LiftExit.SuggestMovePreparation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
