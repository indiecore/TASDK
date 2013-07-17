#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDmgType_Base." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDmgType_Base." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDmgType_Base." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDmgType_Base : public UTDamageType
	{
	public:
			ADD_VAR( ::IntProperty, DBWeaponId, 0xFFFFFFFF )
			float CalculateRangeDamageFalloff( float Dist, float damageRange, class TrPlayerController* TrPCDamager, byte EquipPoint, bool bMinDamageAlwaysApplied )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDmgType_Base.CalculateRangeDamageFalloff" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( float* )( params + 0 ) = Dist;
				*( float* )( params + 4 ) = damageRange;
				*( class TrPlayerController** )( params + 8 ) = TrPCDamager;
				*( byte* )( params + 12 ) = EquipPoint;
				*( bool* )( params + 16 ) = bMinDamageAlwaysApplied;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			class Actor* GetActorCausingDamage( class Controller* EventInstigator, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDmgType_Base.GetActorCausingDamage" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = EventInstigator;
				*( class Actor** )( params + 4 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			Vector ModifyOverheadNumberLocation( Vector InLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDmgType_Base.ModifyOverheadNumberLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = InLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float GetDamageScale( class Actor* DamageCauser, float Dist, ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDmgType_Base.GetDamageScale" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )( params + 0 ) = DamageCauser;
				*( float* )( params + 4 ) = Dist;
				*( ScriptClass** )( params + 8 ) = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstArmor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstNonArmoredObjectives, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EnergyDrainAmount, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_RingingSound )
			ADD_VAR( ::NameProperty, m_nmTakeHitSoundMode, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bCausesGib, 0x1 )
			ADD_VAR( ::FloatProperty, m_fGibRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fGibStrength, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_GibFalloff, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bEnableMotors, 0x2 )
			ScriptName GetRandomDeathAnimName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDmgType_Base.GetRandomDeathAnimName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstGenerators, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nKillIconIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_nmCameraShake, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bOffhandType, 0x10 )
			ADD_VAR( ::BoolProperty, m_bImpulsesFlags, 0x8 )
			ADD_VAR( ::BoolProperty, m_bIgnoreDamageFalloff, 0x4 )
			ADD_VAR( ::FloatProperty, m_fDamageMultiplierAgainstShrike, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBulletDamageRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinDamagePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinDamageRangePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxDamageRangePct, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponTypeId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponBaseId, 0xFFFFFFFF )
			float VehicleDamageScalingFor( class Vehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDmgType_Base.VehicleDamageScalingFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void GetCameraShake( int Damage, ScriptName &outCameraShakeName, float &outScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDmgType_Base.GetCameraShake" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = Damage;
				*( ScriptName* )( params + 4 ) = outCameraShakeName;
				*( float* )( params + 12 ) = outScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				outCameraShakeName = *( ScriptName* )( params + 4 );
				outScale = *( float* )( params + 12 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
