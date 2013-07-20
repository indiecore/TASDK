#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrSubDevice_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrSubDevice_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrSubDevice_ForceField." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSubDevice_ForceField : public TrSubDevice
	{
	public:
			ADD_VAR( ::FloatProperty, m_MinSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_MaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_MinDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_MaxDamage, 0xFFFFFFFF )
			void InstantFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSubDevice_ForceField.InstantFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float ModifyInstantHitDamage( byte FiringMode, void* Impact, float Damage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSubDevice_ForceField.ModifyInstantHitDamage" );
				byte *params = ( byte* )( malloc( 85 ) );
				*( byte* )params = FiringMode;
				*( void** )( params + 4 ) = Impact;
				*( float* )( params + 84 ) = Damage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
