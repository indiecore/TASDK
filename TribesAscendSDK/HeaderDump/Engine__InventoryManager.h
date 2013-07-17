#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.InventoryManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.InventoryManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.InventoryManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InventoryManager : public Actor
	{
	public:
			bool HandlePickupQuery( ScriptClass* ItemClass, class Actor* Pickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.HandlePickupQuery" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = ItemClass;
				*( class Actor** )( params + 4 ) = Pickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AddInventory( class Inventory* NewItem, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.AddInventory" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Inventory** )( params + 0 ) = NewItem;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bMustHoldWeapon, 0x1 )
			ADD_OBJECT( Weapon, LastAttemptedSwitchToWeapon )
			ADD_OBJECT( Weapon, PendingWeapon )
			ADD_OBJECT( Inventory, InventoryChain )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetPendingFireLength( class Weapon* InWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.GetPendingFireLength" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetPendingFire( class Weapon* InWeapon, int InFiringMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.SetPendingFire" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( int* )( params + 4 ) = InFiringMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPendingFire( class Weapon* InWeapon, int InFiringMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.ClearPendingFire" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( int* )( params + 4 ) = InFiringMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPendingFire( class Weapon* InWeapon, int InFiringMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.IsPendingFire" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( int* )( params + 4 ) = InFiringMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearAllPendingFire( class Weapon* InWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.ClearAllPendingFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InventoryActors( ScriptClass* BaseClass, class Inventory* &Inv )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.InventoryActors" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = BaseClass;
				*( class Inventory** )( params + 4 ) = Inv;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Inv = *( class Inventory** )( params + 4 );
			}

			void SetupFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.SetupFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Inventory* FindInventoryType( ScriptClass* DesiredClass, bool bAllowSubclass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.FindInventoryType" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = DesiredClass;
				*( bool* )( params + 4 ) = bAllowSubclass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Inventory** )( params + function->return_val_offset() );
			}

			class Inventory* CreateInventory( ScriptClass* NewInventoryItemClass, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.CreateInventory" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = NewInventoryItemClass;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Inventory** )( params + function->return_val_offset() );
			}

			void RemoveFromInventory( class Inventory* ItemToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.RemoveFromInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Inventory** )( params + 0 ) = ItemToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DiscardInventory(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.DiscardInventory" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OwnerDied(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.OwnerDied" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawHUD( class HUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.DrawHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )( params + 0 ) = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetWeaponRatingFor( class Weapon* W )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.GetWeaponRatingFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = W;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class Weapon* GetBestWeapon( bool bForceADifferentWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.GetBestWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bForceADifferentWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Weapon** )( params + function->return_val_offset() );
			}

			void SwitchToBestWeapon( bool bForceADifferentWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.SwitchToBestWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bForceADifferentWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PrevWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.PrevWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NextWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.NextWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCurrentWeapon( class Weapon* DesiredWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.SetCurrentWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = DesiredWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InternalSetCurrentWeapon( class Weapon* DesiredWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.InternalSetCurrentWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = DesiredWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSetCurrentWeapon( class Weapon* DesiredWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.ServerSetCurrentWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = DesiredWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPendingWeapon( class Weapon* DesiredWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.SetPendingWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = DesiredWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CancelWeaponChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.CancelWeaponChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearPendingWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.ClearPendingWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangedWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.ChangedWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWeaponSet( class Weapon* NewWeapon, bool bOptionalSet, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.ClientWeaponSet" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Weapon** )( params + 0 ) = NewWeapon;
				*( bool* )( params + 4 ) = bOptionalSet;
				*( bool* )( params + 8 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.InventoryManager.UpdateController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
