#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrPaperDollMainMenu." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrPaperDollMainMenu." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrPaperDollMainMenu." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPaperDollMainMenu : public TrPaperDoll
	{
	public:
			ADD_VAR( ::ByteProperty, m_OldContentDataType, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rZeroedRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFullCharacterLightingContrastFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bWasLastMeshSwapRequestMainMenuContentScene, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEditorMode, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
