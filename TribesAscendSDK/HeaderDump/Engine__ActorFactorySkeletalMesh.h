#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ActorFactorySkeletalMesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ActorFactorySkeletalMesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ActorFactorySkeletalMesh." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactorySkeletalMesh : public ActorFactory
	{
	public:
			ADD_VAR( ::NameProperty, AnimSequenceName, 0xFFFFFFFF )
			ADD_OBJECT( AnimSet, AnimSet )
			ADD_OBJECT( SkeletalMesh, SkeletalMesh )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
