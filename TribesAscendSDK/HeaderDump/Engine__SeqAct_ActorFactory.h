#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_ActorFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_ActorFactory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_ActorFactory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ActorFactory : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::FloatProperty, RemainingDelay, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnedCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastSpawnIdx, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnDelay, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnCount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PointSelection, 0xFFFFFFFF )
			ADD_OBJECT( ActorFactory, Factory )
			ADD_VAR( ::BoolProperty, bCheckSpawnCollision, 0x4 )
			ADD_VAR( ::BoolProperty, bIsSpawning, 0x2 )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_ActorFactory.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
