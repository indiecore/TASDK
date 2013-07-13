#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIResourceCombinationProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIResourceCombinationProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIResourceCombinationProvider." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIResourceCombinationProvider : public UIDataProvider
	{
	public:
			ADD_OBJECT( UIDataProvider_OnlineProfileSettings, ProfileProvider )
			ADD_OBJECT( UIResourceDataProvider, StaticDataProvider )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
