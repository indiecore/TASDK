#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKScout." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKScout." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKScout." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKScout : public Scout
	{
	public:
			ADD_VAR( ::NameProperty, SizePersonFindName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, PrototypePawnClass )
			ADD_VAR( ::FloatProperty, MaxDoubleJumpHeight, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRequiresDoubleJump, 0x1 )
			bool SuggestJumpVelocity( Vector &JumpVelocity, Vector Destination, Vector Start, bool bRequireFallLanding )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKScout.SuggestJumpVelocity" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( Vector* )( params + 0 ) = JumpVelocity;
				*( Vector* )( params + 12 ) = Destination;
				*( Vector* )( params + 24 ) = Start;
				*( bool* )( params + 36 ) = bRequireFallLanding;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				JumpVelocity = *( Vector* )( params + 0 );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
