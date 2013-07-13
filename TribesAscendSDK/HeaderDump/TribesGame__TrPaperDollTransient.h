#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPaperDollTransient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPaperDollTransient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPaperDollTransient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPaperDollTransient : public TrPaperDoll
	{
	public:
			ADD_VAR( ::FloatProperty, m_fBackdropFadeRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBackdropFadeTime, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_BackdropMIC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
