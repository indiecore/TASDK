#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTSeqAct_DummyWeaponFire." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTSeqAct_DummyWeaponFire." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTSeqAct_DummyWeaponFire." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSeqAct_DummyWeaponFire : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::BoolProperty, bSuppressSounds, 0x1 )
			ADD_OBJECT( Actor, Target )
			ADD_STRUCT( ::RotatorProperty, MaxSpread, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Origin )
			ADD_VAR( ::IntProperty, ShotsFired, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FireMode, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, WeaponClass )
			ADD_VAR( ::IntProperty, ShotsToFire, 0xFFFFFFFF )
			ADD_OBJECT( UTDummyPawn, DummyPawn )
			void Activated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSeqAct_DummyWeaponFire.Activated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyDummyFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSeqAct_DummyWeaponFire.NotifyDummyFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Update( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTSeqAct_DummyWeaponFire.Update" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
