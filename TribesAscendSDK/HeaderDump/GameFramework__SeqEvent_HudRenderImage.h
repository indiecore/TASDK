#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqEvent_HudRenderImage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqEvent_HudRenderImage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqEvent_HudRenderImage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_HudRenderImage : public SeqEvent_HudRender
	{
	public:
			ADD_VAR( ::FloatProperty, VL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, V, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, U, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, YL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, XL, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, DisplayTexture )
			ADD_STRUCT( ::VectorProperty, DisplayLocation, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
