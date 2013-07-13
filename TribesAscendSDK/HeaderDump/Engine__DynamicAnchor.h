#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DynamicAnchor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DynamicAnchor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DynamicAnchor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DynamicAnchor : public NavigationPoint
	{
	public:
			ADD_OBJECT( Controller, CurrentUser )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
