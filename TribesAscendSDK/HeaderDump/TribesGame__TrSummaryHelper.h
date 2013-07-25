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
		void SortPlayerAwards(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& AwardArray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.SortPlayerAwards");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = AwardArray;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			AwardArray = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void SortMVPAwards(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& AwardArray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.SortMVPAwards");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = AwardArray;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			AwardArray = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		int MVPSort(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrSummaryHelper.MVPAward'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrSummaryHelper.MVPAward'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.MVPSort");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrSummaryHelper.MVPAward'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrSummaryHelper.MVPAward'!
void**)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 24);
			free(params);
			return returnVal;
		}
		int AwardSort(
// WARNING: Unknown structure type 'ScriptStruct PlatformCommon.TgPlayerProfile.PropertyPair'!
void* A, 
// WARNING: Unknown structure type 'ScriptStruct PlatformCommon.TgPlayerProfile.PropertyPair'!
void* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.AwardSort");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct PlatformCommon.TgPlayerProfile.PropertyPair'!
void**)params = A;
			*(
// WARNING: Unknown structure type 'ScriptStruct PlatformCommon.TgPlayerProfile.PropertyPair'!
void**)(params + 8) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		ScriptClass* GetAwardFromId(int AwardId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.GetAwardFromId");
			byte* params = (byte*)malloc(8);
			*(int*)params = AwardId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetTierTitle(int val, ScriptClass* award)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.GetTierTitle");
			byte* params = (byte*)malloc(20);
			*(int*)params = val;
			*(ScriptClass**)(params + 4) = award;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptClass* GetAccoladeFromId(int AccoladeId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.GetAccoladeFromId");
			byte* params = (byte*)malloc(8);
			*(int*)params = AccoladeId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetRankFromXP(int XP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.GetRankFromXP");
			byte* params = (byte*)malloc(8);
			*(int*)params = XP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetNextRank(ScriptClass* Rank)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.GetNextRank");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = Rank;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		int GetMinTierValue(int AwardId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.GetMinTierValue");
			byte* params = (byte*)malloc(8);
			*(int*)params = AwardId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetTieredWeight(int AwardId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSummaryHelper.GetTieredWeight");
			byte* params = (byte*)malloc(12);
			*(int*)params = AwardId;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
