#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider_OnlinePlayerStorageArray." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider_OnlinePlayerStorageArray." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider_OnlinePlayerStorageArray." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerStorageArray : public UIDataProvider
	{
	public:
			ADD_VAR( ::StrProperty, ColumnHeaderText, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PlayerStorageName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerStorageId, 0xFFFFFFFF )
			ADD_OBJECT( OnlinePlayerStorage, PlayerStorage )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
