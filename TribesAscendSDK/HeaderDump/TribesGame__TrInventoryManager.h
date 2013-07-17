#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrInventoryManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrInventoryManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrInventoryManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrInventoryManager : public UTInventoryManager
	{
	public:
			class TrDevice* GetDeviceByEquipPoint( byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.GetDeviceByEquipPoint" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrDevice** )( params + function->return_val_offset() );
			}

			bool AddInventory( class Inventory* NewItem, bool bDoNotActivate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.AddInventory" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Inventory** )( params + 0 ) = NewItem;
				*( bool* )( params + 4 ) = bDoNotActivate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, c_bRetryEquippingPrimaryWeapon, 0x1 )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_VAR( ::ByteProperty, m_PreviousDeviceEquipPoint, 0xFFFFFFFF )
			ADD_OBJECT( TrDevice, m_RealLastDevice )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrDevice* GetDeviceByWeaponClass( ScriptClass* DeviceClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.GetDeviceByWeaponClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = DeviceClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrDevice** )( params + function->return_val_offset() );
			}

			class TrDevice* GetDeviceByWeaponId( int WeaponId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.GetDeviceByWeaponId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = WeaponId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrDevice** )( params + function->return_val_offset() );
			}

			void TrGetWeaponList( bool bInhandOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.TrGetWeaponList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )( params + 12 ) = bInhandOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DiscardEquippedDeployable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.DiscardEquippedDeployable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustWeapon( int NewOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.AdjustWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = NewOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPendingWeapon( class Weapon* DesiredWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.SetPendingWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = DesiredWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveFromInventory( class Inventory* ItemToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.RemoveFromInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Inventory** )( params + 0 ) = ItemToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AutoFireWeapon( byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.AutoFireWeapon" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchWeaponByEquipPoint( byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.SwitchWeaponByEquipPoint" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchToPreviousWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.SwitchToPreviousWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerAutoFireWeapon( byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrInventoryManager.ServerAutoFireWeapon" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
