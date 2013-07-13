#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DynamicSMActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DynamicSMActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DynamicSMActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DynamicSMActor : public Actor
	{
	public:
			ADD_STRUCT( ::VectorProperty, ReplicatedMeshScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, ReplicatedMeshRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ReplicatedMeshTranslation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSafeBaseIfAsleep, 0x4 )
			ADD_VAR( ::BoolProperty, bPawnCanBaseOn, 0x2 )
			ADD_VAR( ::BoolProperty, bForceStaticDecals, 0x1 )
			ADD_OBJECT( MaterialInterface, ReplicatedMaterial )
			ADD_OBJECT( StaticMesh, ReplicatedMesh )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
