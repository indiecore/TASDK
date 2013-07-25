#pragma once
#include "TribesGame__TrGame.h"
#include "TribesGame__TrStormCore.h"
#include "TribesGame__TrStormCarrierShield.h"
#include "TribesGame__TrStormControlPoint.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrStorm." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrGame_TrStorm." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TrStorm." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TrStorm : public TrGame
	{
	public:
		ADD_VAR(::FloatProperty, MatchEndingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxCoreHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxShieldHealth, 0xFFFFFFFF)
		ADD_OBJECT(TrStormCore, m_CarrierCore)
		ADD_OBJECT(TrStormCarrierShield, m_CarrierShields)
		ADD_VAR(::FloatProperty, m_fMissileDamageAmount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrGame_TrStorm.Carrier' for the property named 'm_Carriers'!
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'MissileFired'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'ExplodeMissile'
		// Here lies the not-yet-implemented method 'TakeHealthDamage'
		// Here lies the not-yet-implemented method 'CarrierDestroyed'
		// Here lies the not-yet-implemented method 'TakeDamageFromCore'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'EndGame'
		// Here lies the not-yet-implemented method 'DetermineWinningTeam'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
