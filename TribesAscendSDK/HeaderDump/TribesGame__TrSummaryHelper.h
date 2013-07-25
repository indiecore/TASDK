#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSummaryHelper." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSummaryHelper : public Object
	{
	public:
		ADD_VAR(::IntProperty, AWARD_TIER_SIZE, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SortPlayerAwards'
		// Here lies the not-yet-implemented method 'SortMVPAwards'
		// Here lies the not-yet-implemented method 'MVPSort'
		// Here lies the not-yet-implemented method 'AwardSort'
		// Here lies the not-yet-implemented method 'GetAwardFromId'
		// Here lies the not-yet-implemented method 'GetTierTitle'
		// Here lies the not-yet-implemented method 'GetAccoladeFromId'
		// Here lies the not-yet-implemented method 'GetRankFromXP'
		// Here lies the not-yet-implemented method 'GetNextRank'
		// Here lies the not-yet-implemented method 'GetMinTierValue'
		// Here lies the not-yet-implemented method 'GetTieredWeight'
	};
}
#undef ADD_VAR
