#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GfxTrHudTeam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GfxTrHudTeam." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GfxTrHudTeam." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GfxTrHudTeam : public GfxTrHud
	{
	public:
			ADD_OBJECT( GFxObject, FlagCarrierTF )
			ADD_OBJECT( GFxObject, ScoreTF )
			ADD_OBJECT( GFxObject, ScoreBarMC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
