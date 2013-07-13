#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ActorFactoryFracturedStaticMesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ActorFactoryFracturedStaticMesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ActorFactoryFracturedStaticMesh." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactoryFracturedStaticMesh : public ActorFactory
	{
	public:
			ADD_STRUCT( ::VectorProperty, DrawScale3D, 0xFFFFFFFF )
			ADD_OBJECT( FracturedStaticMesh, FracturedStaticMesh )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
