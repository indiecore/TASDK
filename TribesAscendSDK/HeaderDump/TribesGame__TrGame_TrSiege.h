#pragma once
#include "TribesGame__TrGame.h"
#include "TribesGame__TrPowerGenerator_Siege.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrSiege." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrSiege : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_CurrentPhase, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasCoreDestroyedInRoundOne, 0x1)
		ADD_VAR(::FloatProperty, m_bRoundOneTimeSecs, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'OnGeneratorBlownUp'
		// Here lies the not-yet-implemented method 'OnCoreBlownUp'
		// Here lies the not-yet-implemented method 'IsInRoundOne'
		// Here lies the not-yet-implemented method 'RoundOneOver'
		// Here lies the not-yet-implemented method 'ResetGame'
		// Here lies the not-yet-implemented method 'SetPhase'
		// Here lies the not-yet-implemented method 'SwapTeams'
		// Here lies the not-yet-implemented method 'EndGame'
	};
}
#undef ADD_VAR
