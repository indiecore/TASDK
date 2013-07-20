#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn_Projectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn_Projectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn_Projectile." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn_Projectile : public TrCallIn
	{
	public:
			ADD_STRUCT( ::VectorProperty, m_SavedTargetNormal, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_SavedTargetLocation, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_FiredProjectiles, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, TargetParticleSystem )
			ADD_OBJECT( SoundCue, TargetParticleSound )
			ADD_OBJECT( SoundCue, AreaWarningSound )
			ADD_VAR( ::IntProperty, NumberOfProjectiles, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FireTimeLength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CallRadius, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, ProjectileFireClass )
			bool FireCompletedCallIn( int CallInOffs, Vector TargetLocation, Vector TargetNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_Projectile.FireCompletedCallIn" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )params = CallInOffs;
				*( Vector* )( params + 4 ) = TargetLocation;
				*( Vector* )( params + 16 ) = TargetNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FireProjectile(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_Projectile.FireProjectile" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
