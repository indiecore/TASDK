#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDaDStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDaDStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDaDStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDaDStats : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrDaDStats.DaDScoreInfo' for the property named 'EnemyDaDScore'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrDaDStats.DaDScoreInfo' for the property named 'FriendlyDaDScore'!
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::IntProperty, RoundNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamScore, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForcingUpdate, 0x2)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
