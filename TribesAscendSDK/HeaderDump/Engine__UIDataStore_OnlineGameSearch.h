#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_OnlineGameSearch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_OnlineGameSearch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_OnlineGameSearch." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_OnlineGameSearch : public UIDataStore_Remote
	{
	public:
			ADD_VAR( ::IntProperty, ActiveSearchIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SelectedIndex, 0xFFFFFFFF )
			ADD_OBJECT( OnlineSubsystem, OnlineSub )
			ADD_VAR( ::NameProperty, SearchResultsName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
