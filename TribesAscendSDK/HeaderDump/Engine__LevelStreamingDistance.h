#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LevelStreamingDistance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LevelStreamingDistance." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LevelStreamingDistance." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LevelStreamingDistance : public LevelStreaming
	{
	public:
			ADD_VAR( ::FloatProperty, MaxDistance, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Origin, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
