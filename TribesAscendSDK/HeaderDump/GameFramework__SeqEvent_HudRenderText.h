#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqEvent_HudRenderText." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqEvent_HudRenderText." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqEvent_HudRenderText." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_HudRenderText : public SeqEvent_HudRender
	{
	public:
			ADD_VAR( ::ByteProperty, TextDrawMethod, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DisplayText, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DisplayLocation, 0xFFFFFFFF )
			ADD_OBJECT( Font, DisplayFont )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
