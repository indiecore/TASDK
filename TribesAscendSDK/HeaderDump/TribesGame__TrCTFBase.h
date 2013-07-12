#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrCTFBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrCTFBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrCTFBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCTFBase : public UTCTFBase
	{
	public:
			ADD_VAR( ::BoolProperty, r_bIsActive, 0x1 )
			ADD_VAR( ::IntProperty, CTFBlitzIndex, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( TrAnimNodeBlendList, m_OpenCloseBlendList )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
