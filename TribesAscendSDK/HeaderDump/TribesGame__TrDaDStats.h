#pragma once
#include "TribesGame__GfxTrHud.h"
#include "Core__Object.h"
#include "TribesGame__TrGameReplicationInfo.h"
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDaDStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrDaDStats." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDaDStats." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDaDStats : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrDaDStats.DaDScoreInfo' for the property named 'EnemyDaDScore'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrDaDStats.DaDScoreInfo' for the property named 'FriendlyDaDScore'!
		ADD_OBJECT(TrPlayerController, TrPC)
		ADD_OBJECT(GfxTrHud, m_MoviePlayer)
		ADD_VAR(::IntProperty, RoundNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamScore, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForcingUpdate, 0x2)
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MyTeam, 0xFFFFFFFF)
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.Initialize");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)(params + 4) = MP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Show()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.Show");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.Hide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.Tick");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.UpdateTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeamScore(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.UpdateTeamScore");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTime(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.UpdateTime");
			byte* params = (byte*)malloc(4);
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDStats.ForceUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
