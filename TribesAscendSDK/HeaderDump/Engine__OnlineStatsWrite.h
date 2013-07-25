#pragma once
#include "Engine__OnlineStats.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineStatsWrite." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsWrite : public OnlineStats
	{
	public:
		ADD_VAR(::IntProperty, RatingId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'OnStatsWriteComplete'
		// Here lies the not-yet-implemented method 'GetStatId'
		// Here lies the not-yet-implemented method 'GetStatName'
		// Here lies the not-yet-implemented method 'SetFloatStat'
		// Here lies the not-yet-implemented method 'SetIntStat'
		// Here lies the not-yet-implemented method 'IncrementFloatStat'
		// Here lies the not-yet-implemented method 'IncrementIntStat'
		// Here lies the not-yet-implemented method 'DecrementFloatStat'
		// Here lies the not-yet-implemented method 'DecrementIntStat'
	};
}
#undef ADD_VAR
