#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeamHUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeamHUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeamHUD." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeamHUD : public UTHUD
	{
	public:
			ADD_VAR( ::FloatProperty, TeamScaleModifier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldRightScore, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldLeftScore, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RightTeamPulseTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftTeamPulseTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ScoreTransitionTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastScores, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowDirectional, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
