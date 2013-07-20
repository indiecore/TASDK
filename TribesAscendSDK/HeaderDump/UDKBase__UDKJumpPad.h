#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKJumpPad." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKJumpPad." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKJumpPad." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKJumpPad : public NavigationPoint
	{
	public:
			ADD_VAR( ::FloatProperty, JumpAirControl, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, JumpTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, JumpSound )
			ADD_OBJECT( PathNode, JumpTarget )
			ADD_STRUCT( ::VectorProperty, JumpVelocity, 0xFFFFFFFF )
			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKJumpPad.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostTouch( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKJumpPad.PostTouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SuggestMovePreparation( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKJumpPad.SuggestMovePreparation" );
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
