#pragma once
#include "TribesGame.TrProj_TrackingMissile.h"
#include "TribesGame.TrPlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrSeekingMissileManager.SeekingMissileInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeekingMissileInfo
	{
	public:
		ADD_OBJECT(TrProj_TrackingMissile, Missile)
		ADD_OBJECT(TrPlayerController, VictimController)
	};
}
#undef ADD_OBJECT
