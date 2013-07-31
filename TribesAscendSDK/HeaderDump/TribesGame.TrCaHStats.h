#pragma once
#include "Core.Object.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrCaHCapturePoint.h"
#include "TribesGame.GfxTrHud.h"
#include "TribesGame.TrGameReplicationInfo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrCaHStats : public Object
	{
	public:
		struct CapturePointInfo
		{
		public:
			ADD_STRUCT(float, RemainingHeldTime, 24)
			ADD_STRUCT(int, PctHeld, 20)
			ADD_STRUCT(int, PointOwnershipType, 16)
			ADD_STRUCT(ScriptString*, LabelString, 4)
			ADD_STRUCT(TrObject::CaHCapturePointLabel, PointLabel, 0)
		};
		ADD_STRUCT(ScriptArray<TrCaHStats::CapturePointInfo>, m_CapturePointData, 108)
		ADD_STRUCT(ScriptArray<class TrCaHCapturePoint*>, m_CapturePoints, 120)
		ADD_OBJECT(TrPlayerController, TrPC, 104)
		ADD_OBJECT(GfxTrHud, m_MoviePlayer, 100)
		ADD_STRUCT(int, RoundNum, 96)
		ADD_STRUCT(int, NumCapturePointsHeld, 88)
		ADD_STRUCT(int, RoundScore, 80)
		ADD_STRUCT(int, TeamScore, 72)
		ADD_BOOL(bForceUpdateNextTick, 68, 0x4)
		ADD_BOOL(bForcingUpdate, 68, 0x2)
		ADD_BOOL(bIsActive, 68, 0x1)
		ADD_STRUCT(int, RemainingTime, 64)
		ADD_STRUCT(int, MyTeam, 60)
		void ReadyToPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73908);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Initialize(class TrPlayerController* PC, class GfxTrHud* MP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73911);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(class GfxTrHud**)&params[4] = MP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Show()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73914);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Hide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73915);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73916);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73918);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCapturePointData(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73919);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTeamScore(class TrGameReplicationInfo* GRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73926);
			byte params[4] = { NULL };
			*(class TrGameReplicationInfo**)params = GRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73933);
			byte params[16] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void ForceUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73939);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
