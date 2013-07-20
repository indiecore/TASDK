#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTDmgType_RanOver." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTDmgType_RanOver." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTDmgType_RanOver." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDmgType_RanOver : public UTDamageType
	{
	public:
			ADD_VAR( ::IntProperty, NumMessages, 0xFFFFFFFF )
			int IncrementKills( class UTPlayerReplicationInfo* KillerPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDmgType_RanOver.IncrementKills" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerReplicationInfo** )params = KillerPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SmallReward( class UTPlayerController* Killer, int KillCount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDmgType_RanOver.SmallReward" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )params = Killer;
				*( int* )( params + 4 ) = KillCount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnHitEffect( class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDmgType_RanOver.SpawnHitEffect" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class Pawn** )params = P;
				*( float* )( params + 4 ) = Damage;
				*( Vector* )( params + 8 ) = Momentum;
				*( ScriptName* )( params + 20 ) = BoneName;
				*( Vector* )( params + 28 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
