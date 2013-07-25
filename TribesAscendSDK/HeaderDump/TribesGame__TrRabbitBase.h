#pragma once
#include "Engine__SoundNodeWave.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTCarriedObject.h"
#include "Engine__MaterialInstanceConstant.h"
#include "UTGame__UTGameObjective.h"
#include "TribesGame__TrAnimNodeBlendList.h"
#include "Engine__PlayerController.h"
#include "Engine__Pawn.h"
#include "TribesGame__TrFlagRabbit.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRabbitBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRabbitBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRabbitBase : public UTGameObjective
	{
	public:
		ADD_OBJECT(TrAnimNodeBlendList, m_OpenCloseBlendList)
		ADD_OBJECT(ScriptClass, CTFAnnouncerMessagesClass)
		ADD_OBJECT(MaterialInstanceConstant, MIC_FlagBaseColor)
		ADD_OBJECT(MaterialInstanceConstant, FlagBaseMaterial)
		ADD_VAR(::FloatProperty, BaseExitTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NearBaseRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldLowZOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MidFieldHighZOffset, 0xFFFFFFFF)
		ADD_OBJECT(TrFlagRabbit, myFlag)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'GetBestViewTarget'
		// Here lies the not-yet-implemented method 'GetLocationMessageIndex'
		// Here lies the not-yet-implemented method 'GetLocationSpeechFor'
		// Here lies the not-yet-implemented method 'ObjectiveChanged'
		// Here lies the not-yet-implemented method 'GetFlag'
		// Here lies the not-yet-implemented method 'IsActive'
		// Here lies the not-yet-implemented method 'OnFlagComesHome'
		// Here lies the not-yet-implemented method 'OnFlagTaken'
		// Here lies the not-yet-implemented method 'SpawnHelpTextCollisionProxy'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
