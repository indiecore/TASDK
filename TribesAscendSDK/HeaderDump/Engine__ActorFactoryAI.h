#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ActorFactoryAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ActorFactoryAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ActorFactoryAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorFactoryAI : public ActorFactory
	{
	public:
			ADD_VAR( ::IntProperty, TeamIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGiveDefaultInventory, 0x1 )
			ADD_VAR( ::StrProperty, PawnName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, PawnClass )
			ADD_OBJECT( ScriptClass, ControllerClass )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
