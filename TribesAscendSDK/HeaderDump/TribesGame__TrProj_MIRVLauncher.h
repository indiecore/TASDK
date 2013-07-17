#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_MIRVLauncher." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_MIRVLauncher." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_MIRVLauncher." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_MIRVLauncher : public TrProj_Grenade
	{
	public:
			ADD_VAR( ::IntProperty, m_nSecondaryExplosions, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_SecondaryProjectile )
			Rotator GetRandomSpread( Rotator BaseDirection )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_MIRVLauncher.GetRandomSpread" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = BaseDirection;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void SpawnSecondaryProjectile( Vector Direction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_MIRVLauncher.SpawnSecondaryProjectile" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Direction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Explode( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_MIRVLauncher.Explode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Bounce( class Actor* Other, Vector WallNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_MIRVLauncher.Bounce" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 4 ) = WallNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
