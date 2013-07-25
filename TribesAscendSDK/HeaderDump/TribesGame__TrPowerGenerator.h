#pragma once
#include "TribesGame__TrGameObjective.h"
#include "Engine__Controller.h"
#include "Engine__AnimNodeScalePlayRate.h"
#include "Engine__Actor.h"
#include "TribesGame__TrDeployable.h"
#include "Engine__Texture2D.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPowerGenerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPowerGenerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPowerGenerator : public TrGameObjective
	{
	public:
		ADD_VAR(::FloatProperty, m_fAnimInterpSpeed, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeScalePlayRate, m_AnimNodeScale)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthEffectsInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nDowntimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bFullyRestoringHealthEffects, 0x2)
		ADD_VAR(::BoolProperty, m_bAutoRestoreHealthEnabled, 0x1)
		ADD_VAR(::FloatProperty, m_fAutoRestoreHealthTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxMorphDamage, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IsGeneratingPower'
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ShouldShowHelpText'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'PlayDamageHealthEffects'
		// Here lies the not-yet-implemented method 'DoRepairs'
		// Here lies the not-yet-implemented method 'DamageAllMorphs'
		// Here lies the not-yet-implemented method 'PlayRestoreHealthEffects'
		// Here lies the not-yet-implemented method 'UpdateGeneratorDowntime'
		// Here lies the not-yet-implemented method 'UpdateGeneratorPower'
		// Here lies the not-yet-implemented method 'AutoRestoreHealth'
		// Here lies the not-yet-implemented method 'AddToPoweredObjectives'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'GetMarker'
		// Here lies the not-yet-implemented method 'GiveDestroyAccolade'
		// Here lies the not-yet-implemented method 'AwardUpgradeAssists'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
