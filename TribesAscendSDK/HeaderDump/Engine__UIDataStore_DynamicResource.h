#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_DynamicResource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_DynamicResource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_DynamicResource." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_DynamicResource : public UIDataStore
	{
	public:
			ADD_OBJECT( UIDataStore_GameResource, GameResourceDataStore )
			ADD_OBJECT( UIDataProvider_OnlineProfileSettings, ProfileProvider )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
