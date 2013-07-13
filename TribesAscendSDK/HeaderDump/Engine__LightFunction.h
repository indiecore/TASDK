#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LightFunction." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LightFunction." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LightFunction." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LightFunction : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, DisabledBrightness, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Scale, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, SourceMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
