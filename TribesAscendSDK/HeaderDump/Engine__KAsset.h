#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.KAsset." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.KAsset." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.KAsset." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class KAsset : public Actor
	{
	public:
			ADD_OBJECT( PhysicsAsset, ReplicatedPhysAsset )
			ADD_OBJECT( SkeletalMesh, ReplicatedMesh )
			ADD_VAR( ::BoolProperty, bBlockPawns, 0x4 )
			ADD_VAR( ::BoolProperty, bWakeOnLevelStart, 0x2 )
			ADD_VAR( ::BoolProperty, bDamageAppliesImpulse, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
