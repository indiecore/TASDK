#pragma once
#include "Engine__SoundNodeWave.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTCarriedObject.h"
#include "Engine__MaterialInstanceConstant.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFBase : public UTGameObjective
	{
	public:
		ADD_OBJECT(ScriptClass, CTFAnnouncerMessagesClass)
		ADD_OBJECT(MaterialInstanceConstant, MIC_FlagBaseColor)
		ADD_OBJECT(MaterialInstanceConstant, FlagBaseMaterial)
		ADD_VAR(::FloatProperty, BaseExitTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NearBaseRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldLowZOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldHighZOffset, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, FlagType)
		ADD_OBJECT(UTCarriedObject, myFlag)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'GetBestViewTarget'
		// Here lies the not-yet-implemented method 'GetLocationMessageIndex'
		// Here lies the not-yet-implemented method 'GetLocationSpeechFor'
		// Here lies the not-yet-implemented method 'ObjectiveChanged'
		// Here lies the not-yet-implemented method 'GetFlag'
		// Here lies the not-yet-implemented method 'SetAlarm'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'IsActive'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
