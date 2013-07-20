#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTAmmoPickupFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTAmmoPickupFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTAmmoPickupFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTAmmoPickupFactory : public UTItemPickupFactory
	{
	public:
			ADD_OBJECT( ScriptClass, TargetWeapon )
			ADD_VAR( ::IntProperty, AmmoAmount, 0xFFFFFFFF )
			void SpawnCopyFor( class Pawn* Recipient )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAmmoPickupFactory.SpawnCopyFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Recipient;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateHUD( class UTHUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAmmoPickupFactory.UpdateHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTHUD** )params = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float BotDesireability( class Pawn* P, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTAmmoPickupFactory.BotDesireability" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
