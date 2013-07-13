#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxEvent_FSCommand." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxEvent_FSCommand." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxEvent_FSCommand." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxEvent_FSCommand : public SequenceEvent
	{
	public:
			ADD_OBJECT( GFxFSCmdHandler_Kismet, Handler )
			ADD_VAR( ::StrProperty, FSCommand, 0xFFFFFFFF )
			ADD_OBJECT( SwfMovie, Movie )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
