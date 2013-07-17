#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrEffectForm." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrEffectForm." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrEffectForm." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrEffectForm : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, m_bIsManaged, 0x2 )
			ADD_OBJECT( Material, m_BodyMat )
			ADD_VAR( ::ByteProperty, m_ePriority, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bApplied, 0x1 )
			ADD_OBJECT( SoundCue, m_SoundCue )
			ADD_OBJECT( ParticleSystem, m_PSC )
			ADD_VAR( ::ByteProperty, m_eMatType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBodyMatFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBodyMatFadeInTime, 0xFFFFFFFF )
			class Material* GetOverwriteMat(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEffectForm.GetOverwriteMat" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Material** )( params + function->return_val_offset() );
			}

			class Material* GetMatApplyToPawn( ScriptClass* PawnClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEffectForm.GetMatApplyToPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = PawnClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Material** )( params + function->return_val_offset() );
			}

			class Material* GetMatApplyToWeapon( ScriptClass* devClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEffectForm.GetMatApplyToWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = devClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Material** )( params + function->return_val_offset() );
			}

			class Material* GetMatApplyToAttachment( ScriptClass* attClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEffectForm.GetMatApplyToAttachment" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = attClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Material** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
