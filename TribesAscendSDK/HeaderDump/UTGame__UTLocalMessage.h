#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTLocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTLocalMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTLocalMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTLocalMessage : public LocalMessage
	{
	public:
			ADD_VAR( ::FloatProperty, AnnouncementVolume, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowPortrait, 0x1 )
			ADD_VAR( ::FloatProperty, AnnouncementDelay, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AnnouncementPriority, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MessageArea, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
