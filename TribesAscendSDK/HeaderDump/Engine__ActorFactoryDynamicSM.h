#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ActorFactoryDynamicSM." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ActorFactoryDynamicSM." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ActorFactoryDynamicSM." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactoryDynamicSM : public ActorFactory
	{
	public:
			ADD_VAR( ::ByteProperty, CollisionType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCastDynamicShadow, 0x10 )
			ADD_VAR( ::BoolProperty, bUseCompartment, 0x8 )
			ADD_VAR( ::BoolProperty, bBlockRigidBody, 0x4 )
			ADD_VAR( ::BoolProperty, bNotifyRigidBodyCollision, 0x2 )
			ADD_VAR( ::BoolProperty, bNoEncroachCheck, 0x1 )
			ADD_STRUCT( ::VectorProperty, DrawScale3D, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, StaticMesh )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
