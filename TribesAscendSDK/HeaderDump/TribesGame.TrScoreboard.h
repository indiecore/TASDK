#pragma once
#include "Core.Object.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#include "TribesGame.GfxTrHud.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrGameReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrScoreboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrScoreboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrScoreboard." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrScoreboard : public Object
	{
	public:
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::BoolProperty, bIsActive, 0x8)
		ADD_OBJECT(TrPlayerController, TrPC)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrScoreboard.TrScoreboardState' for the property named 'PreviousState'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrScoreboard.TrScoreSlot' for the property named 'ScoreboardSlots'!
		ADD_VAR(::BoolProperty, bCheckPing, 0x10)
		ADD_VAR(::BoolProperty, bInitialized, 0x4)
		ADD_VAR(::BoolProperty, bUpdated, 0x2)
		ADD_VAR(::BoolProperty, bTeamGame, 0x1)
		ADD_VAR(::IntProperty, DSIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BEIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DSOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevActiveSlot, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevDSSLots, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevBESlots, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DSSlots, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BESlots, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAX_PLAYER_INDEX, 0xFFFFFFFF)
		int CreditsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.CreditsSort");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int AssistsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.AssistsSort");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int KillsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.KillsSort");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.Initialize");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)(params + 4) = MP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Show(bool bIsTeamGame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.Show");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsTeamGame;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Hide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.Hide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConfigScoreboard()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.ConfigScoreboard");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePRILists(class TrGameReplicationInfo* TrGRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.UpdatePRILists");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = TrGRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetBestSortArray(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* PRIArray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.GetBestSortArray");
			byte* params = (byte*)malloc(24);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = PRIArray;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		int GetRank(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* PRIArray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.GetRank");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = PRIArray;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ClearSlot(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.ClearSlot");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool UpdateSlot(int Index, class TrPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.UpdateSlot");
			byte* params = (byte*)malloc(12);
			*(int*)params = Index;
			*(class TrPlayerReplicationInfo**)(params + 4) = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateHeaders(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.UpdateHeaders");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsValidScoreboardPlayer(class TrPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrScoreboard.IsValidScoreboardPlayer");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
