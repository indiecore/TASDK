#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrAttachment_ChainGun." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrAttachment_ChainGun." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrAttachment_ChainGun." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAttachment_ChainGun : public TrDeviceAttachment
	{
	public:
			ADD_OBJECT( TrSkelControl_SpinControl, m_BarrelSpinControl )
			ADD_VAR( ::FloatProperty, m_fLastFireTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrSpinTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bSpinningUp, 0x2 )
			ADD_VAR( ::BoolProperty, m_bIsFiring, 0x1 )
			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAttachment_ChainGun.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ThirdPersonFireEffects( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrAttachment_ChainGun.ThirdPersonFireEffects" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
