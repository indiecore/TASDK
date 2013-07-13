#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GenericParamListStatEntry." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GenericParamListStatEntry." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GenericParamListStatEntry." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GenericParamListStatEntry : public Object
	{
	public:
			ADD_OBJECT( GameplayEventsWriter, Writer )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
