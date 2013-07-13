#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_ServerScoring." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_ServerScoring." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_ServerScoring." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_ServerScoring : public GFxTrPage
	{
	public:
			ADD_VAR( ::BoolProperty, bBoundsPopup, 0x8 )
			ADD_VAR( ::BoolProperty, bLivesPopup, 0x4 )
			ADD_VAR( ::BoolProperty, bRoundsPopup, 0x2 )
			ADD_VAR( ::BoolProperty, bScorePopup, 0x1 )
			ADD_VAR( ::IntProperty, ScoreNumber, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxBOunds, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinBounds, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GameType, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
