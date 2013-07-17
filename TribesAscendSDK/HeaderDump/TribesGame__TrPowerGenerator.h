#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPowerGenerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPowerGenerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPowerGenerator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPowerGenerator : public TrGameObjective
	{
	public:
			bool IsGeneratingPower(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.IsGeneratingPower" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeScalePlayRate, m_AnimNodeScale )
			ADD_VAR( ::FloatProperty, m_fAutoRestoreHealthEffectsInterpSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAutoRestoreHealthTimeStamp, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nDowntimeRemaining, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bFullyRestoringHealthEffects, 0x2 )
			ADD_VAR( ::BoolProperty, m_bAutoRestoreHealthEnabled, 0x1 )
			ADD_VAR( ::FloatProperty, m_fAutoRestoreHealthTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxMorphDamage, 0xFFFFFFFF )
			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldShowHelpText( byte HelpTextType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.ShouldShowHelpText" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = HelpTextType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDamageHealthEffects( int DamageAmount, int HitBoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.PlayDamageHealthEffects" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( int* )( params + 4 ) = HitBoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoRepairs( int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.DoRepairs" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( int* )( params + 0 ) = HealAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( class Actor** )( params + 8 ) = DamageCauser;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( void** )( params + 16 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DamageAllMorphs( float DamageAmount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.DamageAllMorphs" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DamageAmount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRestoreHealthEffects( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.PlayRestoreHealthEffects" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGeneratorDowntime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.UpdateGeneratorDowntime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGeneratorPower( bool bPowered )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.UpdateGeneratorPower" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bPowered;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AutoRestoreHealth( bool bFullyRestore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.AutoRestoreHealth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bFullyRestore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddToPoweredObjectives( class TrDeployable* dep )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.AddToPoweredObjectives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrDeployable** )( params + 0 ) = dep;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Texture2D* GetMarker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.GetMarker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture2D** )( params + function->return_val_offset() );
			}

			void GiveDestroyAccolade( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.GiveDestroyAccolade" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )( params + 0 ) = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AwardUpgradeAssists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPowerGenerator.AwardUpgradeAssists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
