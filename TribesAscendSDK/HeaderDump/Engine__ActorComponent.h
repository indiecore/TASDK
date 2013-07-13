#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ActorComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ActorComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ActorComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ActorComponent : public Component
	{
	public:
			ADD_VAR( ::ByteProperty, TickGroup, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNeedsUpdateTransform, 0x8 )
			ADD_VAR( ::BoolProperty, bNeedsReattach, 0x4 )
			ADD_VAR( ::BoolProperty, bTickInEditor, 0x2 )
			ADD_VAR( ::BoolProperty, bAttached, 0x1 )
			ADD_OBJECT( Actor, Owner )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
