#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCrowdSpawnInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCrowdSpawnInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCrowdSpawnInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdSpawnInterface : public Interface
	{
	public:
			void GetSpawnPosition( class SeqAct_GameCrowdSpawner* Spawner, Vector &SpawnPos, Rotator &SpawnRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdSpawnInterface.GetSpawnPosition" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class SeqAct_GameCrowdSpawner** )params = Spawner;
				*( Vector* )( params + 4 ) = SpawnPos;
				*( Rotator* )( params + 16 ) = SpawnRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SpawnPos = *( Vector* )( params + 4 );
				SpawnRot = *( Rotator* )( params + 16 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
