#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.GFxObject.h"
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
	class UTGFxTweenableMoviePlayer : public GFxMoviePlayer
	{
	public:
		enum TweenType : byte
		{
			TWEEN_EaseOut = 0,
			TWEEN_EaseIn = 1,
			TWEEN_Linear = 2,
			TWEEN_MAX = 3,
		};
		struct GFxTween
		{
		public:
			ADD_STRUCT(UTGFxTweenableMoviePlayer::TweenType, ThisTweenType, 96)
			ADD_BOOL(bFinished, 92, 0x1)
			ADD_STRUCT(GFxObject::ASDisplayInfo, displayInfo, 48)
			ADD_STRUCT(ScriptString*, Callback, 36)
			ADD_STRUCT(ScriptString*, MemberName, 24)
			ADD_STRUCT(float, DesiredValue, 20)
			ADD_STRUCT(float, Delta, 16)
			ADD_STRUCT(float, StartValue, 12)
			ADD_STRUCT(float, Duration, 8)
			ADD_STRUCT(float, TweenTime, 4)
			ADD_OBJECT(GFxObject, TargetMC, 0)
		};
		ADD_STRUCT(ScriptArray<UTGFxTweenableMoviePlayer::GFxTween>, TweenList, 380)
		void TweenTo(class GFxObject* MC, float Duration, ScriptString* Member, float Target, UTGFxTweenableMoviePlayer::TweenType NewTweenType, ScriptString* Callback)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37559);
			byte params[37] = { NULL };
			*(class GFxObject**)params = MC;
			*(float*)&params[4] = Duration;
			*(ScriptString**)&params[8] = Member;
			*(float*)&params[20] = Target;
			*(UTGFxTweenableMoviePlayer::TweenType*)&params[24] = NewTweenType;
			*(ScriptString**)&params[28] = Callback;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessTweenCallback(ScriptString* Callback, class GFxObject* TargetMC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37567);
			byte params[16] = { NULL };
			*(ScriptString**)params = Callback;
			*(class GFxObject**)&params[12] = TargetMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37570);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearsTweensOnMovieClip(class GFxObject* MC, bool bReset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37575);
			byte params[8] = { NULL };
			*(class GFxObject**)params = MC;
			*(bool*)&params[4] = bReset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrintTweensToLog()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37580);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TweenComplete(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37582);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
