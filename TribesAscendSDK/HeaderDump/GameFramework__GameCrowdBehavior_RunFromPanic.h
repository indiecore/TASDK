#pragma once
#include "Engine__Actor.h"
#include "GameFramework__GameCrowdAgentBehavior.h"
#include "GameFramework__GameCrowdAgent.h"
#include "GameFramework__GameCrowdDestination.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdBehavior_RunFromPanic." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdBehavior_RunFromPanic." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdBehavior_RunFromPanic : public GameCrowdAgentBehavior
	{
	public:
		ADD_VAR(::FloatProperty, TimeToStopPanic, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfPanic, 0xFFFFFFFF)
		ADD_OBJECT(Actor, PanicFocus)
		// Here lies the not-yet-implemented method 'ActivatedBy'
		// Here lies the not-yet-implemented method 'InitBehavior'
		// Here lies the not-yet-implemented method 'StopBehavior'
		// Here lies the not-yet-implemented method 'PropagateViralBehaviorTo'
		// Here lies the not-yet-implemented method 'AllowThisDestination'
		// Here lies the not-yet-implemented method 'AllowBehaviorAt'
		// Here lies the not-yet-implemented method 'GetBehaviorString'
		// Here lies the not-yet-implemented method 'Tick'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
