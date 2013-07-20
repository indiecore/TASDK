#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable_BaseTurret." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable_BaseTurret." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable_BaseTurret." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_BaseTurret : public TrDeployable_Turret
	{
	public:
			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReceivesPowerFromGenerator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.ReceivesPowerFromGenerator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldShowHelpText( byte HelpTextType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.ShouldShowHelpText" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = HelpTextType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SpawnHelpTextCollisionProxy( byte HelpTextType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.SpawnHelpTextCollisionProxy" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = HelpTextType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Texture2D* GetMarker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.GetMarker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture2D** )( params + function->return_val_offset() );
			}

			void GiveDestroyAccolade( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.GiveDestroyAccolade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )params = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RequiresLOSForRepairDeployable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_BaseTurret.RequiresLOSForRepairDeployable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
