#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ActorFactoryArchetype." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ActorFactoryArchetype." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ActorFactoryArchetype." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactoryArchetype : public ActorFactory
	{
	public:
			ADD_OBJECT( Actor, ArchetypeActor )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
