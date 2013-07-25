#pragma once
#include "TribesGame__GfxTrHud.h"
#include "Core__Object.h"
#include "TribesGame__TrGameReplicationInfo.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRabbitLeaderboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrRabbitLeaderboard." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRabbitLeaderboard." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRabbitLeaderboard : public Object
	{
	public:
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::BoolProperty, bIsActive, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrRabbitLeaderboard.LeaderboardSlot' for the property named 'LeaderboardSlots'!
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_VAR(::BoolProperty, bInitialized, 0x2)
		ADD_VAR(::BoolProperty, bUpdated, 0x1)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevSlots, 0xFFFFFFFF)
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.Initialize");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)(params + 4) = MP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Show()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.Show");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.Hide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.Tick");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdatePlayers(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.UpdatePlayers");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool UpdateLeaderboard(int Index, ScriptName PRIName, ScriptArray<wchar_t> PlayerName, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.UpdateLeaderboard");
			byte* params = (byte*)malloc(32);
			*(int*)params = Index;
			*(ScriptName*)(params + 4) = PRIName;
			*(ScriptArray<wchar_t>*)(params + 12) = PlayerName;
			*(int*)(params + 24) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void UpdateTime(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.UpdateTime");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRabbitLeaderboard.ForceUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
