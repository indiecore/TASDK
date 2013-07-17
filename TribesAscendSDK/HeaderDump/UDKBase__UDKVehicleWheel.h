#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKVehicleWheel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKVehicleWheel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKVehicleWheel." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKVehicleWheel : public SVehicleWheel
	{
	public:
			ADD_VAR( ::FloatProperty, EffectDesiredSpinDir, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDisableWheelOnDeath, 0x2 )
			ADD_VAR( ::BoolProperty, bUseMaterialSpecificEffects, 0x1 )
			void SetParticleEffect( class UDKVehicle* OwnerVehicle, class ParticleSystem* NewTemplate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicleWheel.SetParticleEffect" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UDKVehicle** )( params + 0 ) = OwnerVehicle;
				*( class ParticleSystem** )( params + 4 ) = NewTemplate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OldEffectFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicleWheel.OldEffectFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
