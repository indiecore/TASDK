#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable_ForceField." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_ForceField : public TrDeployable
	{
	public:
			ADD_VAR( ::FloatProperty, m_LightFlashBrightness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutHitOtherFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInHitOtherFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutHitOtherFlashTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInHitOtherFlashTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutTakeHitFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInTakeHitFlashRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fOutTakeHitFlashTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInTakeHitFlashTimeLength, 0xFFFFFFFF )
			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_ForceField.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnHealthChanged( bool wasDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_ForceField.OnHealthChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = wasDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDamageHealthEffects( int DamageAmount, int HitBoneIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_ForceField.PlayDamageHealthEffects" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = DamageAmount;
				*( int* )( params + 4 ) = HitBoneIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayHitOtherEffects( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_ForceField.PlayHitOtherEffects" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_ForceField.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Texture2D* GetMarker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_ForceField.GetMarker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture2D** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
