#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Input." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Input." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Input." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Input : public Interaction
	{
	public:
			ADD_VAR( ::FloatProperty, CurrentDeltaTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentDelta, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentEvent, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
