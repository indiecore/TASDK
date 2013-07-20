#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice_Melee." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice_Melee." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice_Melee." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_Melee : public TrDevice_AutoFire
	{
	public:
			ADD_OBJECT( AnimNodeSequence, FiringAnimSeqNode )
			void OwningClientPlayHit( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.OwningClientPlayHit" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireAnimation( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.PlayFireAnimation" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int CalcAmountToLoad(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.CalcAmountToLoad" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool HasAmmo( byte FireModeNum, int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.HasAmmo" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = FireModeNum;
				*( int* )( params + 4 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetBuildUpTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.GetBuildUpTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void FireAmmunition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.FireAmmunition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float ModifyInstantHitDamage( byte FiringMode, void* Impact, float Damage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.ModifyInstantHitDamage" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( float* )( params + 84 ) = Damage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void AttemptFlagFumble( class TrPawn* Victim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Melee.AttemptFlagFumble" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )params = Victim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
