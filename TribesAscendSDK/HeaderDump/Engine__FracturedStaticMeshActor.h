#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.FracturedStaticMeshActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.FracturedStaticMeshActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.FracturedStaticMeshActor." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class FracturedStaticMeshActor : public Actor
	{
	public:
			ADD_OBJECT( MaterialInterface, MI_LoseChunkPreviousMaterial )
			ADD_OBJECT( SoundCue, SingleChunkFractureSound )
			ADD_OBJECT( SoundCue, ExplosionFractureSound )
			ADD_VAR( ::FloatProperty, FractureCullMaxDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FractureCullMinDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ChunkHealthScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBreakChunksOnActorTouch, 0x2 )
			ADD_VAR( ::BoolProperty, bHasShownMissingSoundWarning, 0x1 )
			ADD_VAR( ::IntProperty, MaxPartsToSpawnAtOnce, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
