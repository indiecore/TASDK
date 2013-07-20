#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn_CrashLandInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn_CrashLandInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn_CrashLandInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn_CrashLandInfo : public Info
	{
	public:
			ADD_VAR( ::FloatProperty, MomentumTransfer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Damage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageRadius, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, DamageTypeClass )
			ADD_STRUCT( ::VectorProperty, r_CrashLandNormal, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_CrashLandPoint, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fCrashLandTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bPodLanded, 0x1 )
			ADD_OBJECT( Controller, m_Owner )
			ADD_OBJECT( ScriptClass, m_ItemToDeploy )
			bool SpawnCrashLandInfo( class Controller* Initializer, float CrashLandTime, Vector CrashLandPoint, Vector CrashLandNormal, ScriptClass* ItemInDeliveryPod )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_CrashLandInfo.SpawnCrashLandInfo" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )params = Initializer;
				*( float* )( params + 4 ) = CrashLandTime;
				*( Vector* )( params + 8 ) = CrashLandPoint;
				*( Vector* )( params + 20 ) = CrashLandNormal;
				*( ScriptClass** )( params + 32 ) = ItemInDeliveryPod;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_CrashLandInfo.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_CrashLandInfo.InitTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeliveryPodLanded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_CrashLandInfo.DeliveryPodLanded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveSameTeamPawn( class TrPawn* PawnToMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_CrashLandInfo.MoveSameTeamPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )params = PawnToMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformLandingDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrCallIn_CrashLandInfo.PerformLandingDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
