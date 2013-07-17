#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTAirVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTAirVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTAirVehicle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTAirVehicle : public UTVehicle
	{
	public:
			ADD_VAR( ::FloatProperty, LastRadarLockWarnTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RadarLockMessage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PushForce, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoLand, 0x1 )
			void LockOnWarning( class UDKProjectile* IncomingMissile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAirVehicle.LockOnWarning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKProjectile** )( params + 0 ) = IncomingMissile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDriving( bool bNewDriving )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAirVehicle.SetDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewDriving;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RecommendLongRangedAttack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAirVehicle.RecommendLongRangedAttack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Dodge( byte DoubleClickMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAirVehicle.Dodge" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = DoubleClickMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
