#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.UIDataProvider_OnlinePlayerStorage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.UIDataProvider_OnlinePlayerStorage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.UIDataProvider_OnlinePlayerStorage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerStorage : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
			ADD_VAR( ::IntProperty, DeviceStorageSizeNeeded, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWasErrorLastRead, 0x1 )
			ADD_VAR( ::NameProperty, ProviderName, 0xFFFFFFFF )
			ADD_OBJECT( OnlinePlayerStorage, Profile )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
