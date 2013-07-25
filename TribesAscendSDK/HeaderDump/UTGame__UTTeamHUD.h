#pragma once
#include "UTGame__UTHUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTTeamHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTTeamHUD : public UTHUD
	{
	public:
		ADD_VAR(::FloatProperty, TeamScaleModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldRightScore, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldLeftScore, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RightTeamPulseTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftTeamPulseTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'TeamIconCenterPoints'!
		ADD_VAR(::IntProperty, ScoreTransitionTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastScores, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowDirectional, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
