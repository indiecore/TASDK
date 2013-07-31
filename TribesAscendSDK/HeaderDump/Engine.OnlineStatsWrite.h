#pragma once
#include "Engine.OnlineStats.h"
#include "Engine.Settings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsWrite : public OnlineStats
	{
	public:
		ADD_STRUCT(ScriptArray<Settings::StringIdToStringMapping>, StatMappings, 72)
		ADD_STRUCT(ScriptArray<Settings::SettingsProperty>, Properties, 84)
		ADD_STRUCT(ScriptArray<int>, ViewIds, 96)
		ADD_STRUCT(ScriptArray<int>, ArbitratedViewIds, 108)
		ADD_STRUCT(int, RatingId, 120)
		void OnStatsWriteComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22875);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetStatId(ScriptName StatName, int& StatId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22877);
			byte params[16] = { NULL };
			*(ScriptName*)params = StatName;
			*(int*)&params[8] = StatId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StatId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		ScriptName GetStatName(int StatId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22881);
			byte params[12] = { NULL };
			*(int*)params = StatId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		void SetFloatStat(int StatId, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22884);
			byte params[8] = { NULL };
			*(int*)params = StatId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetIntStat(int StatId, int Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22887);
			byte params[8] = { NULL };
			*(int*)params = StatId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFloatStat(int StatId, float IncBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22890);
			byte params[8] = { NULL };
			*(int*)params = StatId;
			*(float*)&params[4] = IncBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementIntStat(int StatId, int IncBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22893);
			byte params[8] = { NULL };
			*(int*)params = StatId;
			*(int*)&params[4] = IncBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DecrementFloatStat(int StatId, float DecBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22896);
			byte params[8] = { NULL };
			*(int*)params = StatId;
			*(float*)&params[4] = DecBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DecrementIntStat(int StatId, int DecBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22899);
			byte params[8] = { NULL };
			*(int*)params = StatId;
			*(int*)&params[4] = DecBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
