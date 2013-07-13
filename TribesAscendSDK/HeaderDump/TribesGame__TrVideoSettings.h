#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVideoSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVideoSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVideoSettings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVideoSettings : public GFxObject
	{
	public:
			ADD_VAR( ::IntProperty, m_Cached_Resolution, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_VideoSettingsCount, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, m_VideoSettingsList )
			ADD_VAR( ::IntProperty, m_ResolutionCount, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, m_ResolutionList )
			ADD_VAR( ::IntProperty, m_Cached_ShadowDetail, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_TextureDetail, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_ScreenType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_MotionBlur, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_VerticalSync, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_Cached_SmoothFramerate, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
