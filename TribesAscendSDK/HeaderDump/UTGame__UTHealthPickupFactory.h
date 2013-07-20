#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTHealthPickupFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTHealthPickupFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTHealthPickupFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTHealthPickupFactory : public UTItemPickupFactory
	{
	public:
			ADD_VAR( ::BoolProperty, bSuperHeal, 0x1 )
			ADD_VAR( ::IntProperty, HealingAmount, 0xFFFFFFFF )
			void UpdateHUD( class UTHUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHealthPickupFactory.UpdateHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTHUD** )params = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnCopyFor( class Pawn* Recipient )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHealthPickupFactory.SpawnCopyFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Recipient;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int HealAmount( class Pawn* Recipient )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHealthPickupFactory.HealAmount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Recipient;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float BotDesireability( class Pawn* P, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHealthPickupFactory.BotDesireability" );
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
