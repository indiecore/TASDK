#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKAnimNodeJumpLeanOffset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKAnimNodeJumpLeanOffset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKAnimNodeJumpLeanOffset." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimNodeJumpLeanOffset : public AnimNodeAimOffset
	{
	public:
			ADD_VAR( ::FloatProperty, BlendTimeToGo, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeanWeightTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeanWeight, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, OldAimProfileName, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeAimOffset, CachedAimNode )
			ADD_VAR( ::BoolProperty, bOldDoubleJumping, 0x10 )
			ADD_VAR( ::BoolProperty, bDoubleJumping, 0x8 )
			ADD_VAR( ::BoolProperty, bOldDodging, 0x4 )
			ADD_VAR( ::BoolProperty, bDodging, 0x2 )
			ADD_VAR( ::BoolProperty, bMultiplyByZVelocity, 0x1 )
			ADD_VAR( ::FloatProperty, MaxLeanChangeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, JumpLeanStrength, 0xFFFFFFFF )
			void SetLeanWeight( float WeightTarget, float BlendTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKAnimNodeJumpLeanOffset.SetLeanWeight" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = WeightTarget;
				*( float* )( params + 4 ) = BlendTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
