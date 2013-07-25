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
		void OnStatsWriteComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.OnStatsWriteComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetStatId(ScriptName StatName, int& StatId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.GetStatId");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = StatName;
			*(int*)(params + 8) = StatId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			StatId = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptName GetStatName(int StatId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.GetStatName");
			byte* params = (byte*)malloc(12);
			*(int*)params = StatId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetFloatStat(int StatId, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.SetFloatStat");
			byte* params = (byte*)malloc(8);
			*(int*)params = StatId;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetIntStat(int StatId, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.SetIntStat");
			byte* params = (byte*)malloc(8);
			*(int*)params = StatId;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementFloatStat(int StatId, float IncBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.IncrementFloatStat");
			byte* params = (byte*)malloc(8);
			*(int*)params = StatId;
			*(float*)(params + 4) = IncBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementIntStat(int StatId, int IncBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.IncrementIntStat");
			byte* params = (byte*)malloc(8);
			*(int*)params = StatId;
			*(int*)(params + 4) = IncBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DecrementFloatStat(int StatId, float DecBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.DecrementFloatStat");
			byte* params = (byte*)malloc(8);
			*(int*)params = StatId;
			*(float*)(params + 4) = DecBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DecrementIntStat(int StatId, int DecBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsWrite.DecrementIntStat");
			byte* params = (byte*)malloc(8);
			*(int*)params = StatId;
			*(int*)(params + 4) = DecBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
