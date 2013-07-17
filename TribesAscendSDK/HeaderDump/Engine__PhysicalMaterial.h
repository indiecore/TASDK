#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PhysicalMaterial." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PhysicalMaterial." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PhysicalMaterial." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PhysicalMaterial : public Object
	{
	public:
			void* FindPhysEffectInfo( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicalMaterial.FindPhysEffectInfo" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, MaterialIndex, 0xFFFFFFFF )
			void FindFractureSounds( class SoundCue* &OutSoundExplosion, class SoundCue* &OutSoundSingle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicalMaterial.FindFractureSounds" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class SoundCue** )( params + 0 ) = OutSoundExplosion;
				*( class SoundCue** )( params + 4 ) = OutSoundSingle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutSoundExplosion = *( class SoundCue** )( params + 0 );
				OutSoundSingle = *( class SoundCue** )( params + 4 );
			}

			ADD_OBJECT( SoundCue, FractureSoundSingle )
			ADD_OBJECT( SoundCue, FractureSoundExplosion )
			ADD_OBJECT( PhysicalMaterial, Parent )
			class PhysicalMaterialPropertyBase* GetPhysicalMaterialProperty( ScriptClass* DesiredClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PhysicalMaterial.GetPhysicalMaterialProperty" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = DesiredClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PhysicalMaterialPropertyBase** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( PhysicalMaterialPropertyBase, PhysicalMaterialProperty )
			ADD_VAR( ::FloatProperty, Friction, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Restitution, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceConeFriction, 0x1 )
			ADD_VAR( ::BoolProperty, bEnableAnisotropicFriction, 0x2 )
			ADD_STRUCT( ::VectorProperty, AnisoFrictionDir, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FrictionV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Density, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MagneticResponse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WindResponse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ImpactThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ImpactReFireDelay, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, ImpactEffect )
			ADD_OBJECT( SoundCue, ImpactSound )
			ADD_VAR( ::FloatProperty, SlideThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SlideReFireDelay, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, SlideEffect )
			ADD_OBJECT( SoundCue, SlideSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
