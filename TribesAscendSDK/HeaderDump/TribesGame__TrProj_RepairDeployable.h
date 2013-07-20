#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_RepairDeployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_RepairDeployable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_RepairDeployable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_RepairDeployable : public TrProj_Mine
	{
	public:
			ADD_VAR( ::FloatProperty, m_fTickFrequency, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeSinceLastTick, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, RepairBeamSound )
			ADD_VAR( ::FloatProperty, m_fVehicleRepairPercentage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRepairPercentage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRepairBuff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRepairRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCheckNearbyActorsFrequency, 0xFFFFFFFF )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_RepairDeployable.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitProjectile( Vector Direction, ScriptClass* ClassToInherit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_RepairDeployable.InitProjectile" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = Direction;
				*( ScriptClass** )( params + 12 ) = ClassToInherit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ArmedTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_RepairDeployable.ArmedTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_RepairDeployable.HitWall" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckRepair(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_RepairDeployable.CheckRepair" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Explode( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_RepairDeployable.Explode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetonateObsolete( bool bDetonateFromDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_RepairDeployable.DetonateObsolete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDetonateFromDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
