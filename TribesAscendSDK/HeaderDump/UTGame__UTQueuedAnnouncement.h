#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTQueuedAnnouncement." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTQueuedAnnouncement." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTQueuedAnnouncement." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTQueuedAnnouncement : public Info
	{
	public:
			ADD_OBJECT( UTQueuedAnnouncement, nextAnnouncement )
			ADD_VAR( ::IntProperty, MessageIndex, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, PRI )
			ADD_OBJECT( Object, OptionalObject )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
