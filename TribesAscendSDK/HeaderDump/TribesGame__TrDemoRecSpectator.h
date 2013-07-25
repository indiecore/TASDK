#pragma once
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDemoRecSpectator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDemoRecSpectator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDemoRecSpectator : public TrPlayerController
	{
	public:
		ADD_VAR(::FloatProperty, AutoSwitchPlayerInterval, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, MyRealViewTarget)
		ADD_VAR(::BoolProperty, bAutoSwitchPlayers, 0x4)
		ADD_VAR(::BoolProperty, bLockRotationToViewTarget, 0x2)
		ADD_VAR(::BoolProperty, bFindPlayer, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
