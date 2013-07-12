#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.OnlineStatsRead." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.OnlineStatsRead." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.OnlineStatsRead." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineStatsRead : public OnlineStats
	{
	public:
			ADD_VAR( ::IntProperty, TitleId, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ViewName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TotalRowsInView, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SortColumnId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ViewId, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
