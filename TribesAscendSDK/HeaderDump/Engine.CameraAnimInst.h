#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Camera.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.CameraAnim.h"
#include "Engine.InterpTrackInstMove.h"
#include "Engine.InterpTrackMove.h"
#include "Engine.InterpGroupInst.h"
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
	class CameraAnimInst : public Object
	{
	public:
		ADD_STRUCT(Vector, LastCameraLoc, 416)
		ADD_STRUCT(float, LastPPSettingsAlpha, 412)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, LastPPSettings, 192)
		ADD_STRUCT(Object::Matrix, UserPlaySpaceMatrix, 128)
		ADD_STRUCT(Camera::ECameraAnimPlaySpace, PlaySpace, 124)
		ADD_OBJECT(AnimNodeSequence, SourceAnimNode, 120)
		ADD_OBJECT(InterpTrackInstMove, MoveInst, 116)
		ADD_OBJECT(InterpTrackMove, MoveTrack, 112)
		ADD_STRUCT(float, RemainingTime, 108)
		ADD_STRUCT(float, CurrentBlendWeight, 104)
		ADD_STRUCT(float, TransientScaleModifier, 100)
		ADD_STRUCT(float, BasePlayScale, 96)
		ADD_STRUCT(float, PlayRate, 92)
		ADD_STRUCT(float, CurBlendOutTime, 88)
		ADD_STRUCT(float, CurBlendInTime, 84)
		ADD_STRUCT(float, BlendOutTime, 80)
		ADD_STRUCT(float, BlendInTime, 76)
		ADD_BOOL(bBlendingOut, 72, 0x10)
		ADD_BOOL(bBlendingIn, 72, 0x8)
		ADD_BOOL(bAutoReleaseWhenFinished, 72, 0x4)
		ADD_BOOL(bFinished, 72, 0x2)
		ADD_BOOL(bLooping, 72, 0x1)
		ADD_STRUCT(float, CurTime, 68)
		ADD_OBJECT(InterpGroupInst, InterpGroupInst, 64)
		ADD_OBJECT(CameraAnim, CamAnim, 60)
		void SetPlaySpace(Camera::ECameraAnimPlaySpace NewSpace, Rotator UserPlaySpace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9499);
			byte params[13] = { NULL };
			*(Camera::ECameraAnimPlaySpace*)params = NewSpace;
			*(Rotator*)&params[4] = UserPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Play(class CameraAnim* Anim, class Actor* CamActor, float InRate, float InScale, float InBlendInTime, float InBlendOutTime, bool bInLoop, bool bRandomStartTime, float Duration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12164);
			byte params[36] = { NULL };
			*(class CameraAnim**)params = Anim;
			*(class Actor**)&params[4] = CamActor;
			*(float*)&params[8] = InRate;
			*(float*)&params[12] = InScale;
			*(float*)&params[16] = InBlendInTime;
			*(float*)&params[20] = InBlendOutTime;
			*(bool*)&params[24] = bInLoop;
			*(bool*)&params[28] = bRandomStartTime;
			*(float*)&params[32] = Duration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Update(float NewRate, float NewScale, float NewBlendInTime, float NewBlendOutTime, float NewDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12174);
			byte params[20] = { NULL };
			*(float*)params = NewRate;
			*(float*)&params[4] = NewScale;
			*(float*)&params[8] = NewBlendInTime;
			*(float*)&params[12] = NewBlendOutTime;
			*(float*)&params[16] = NewDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdvanceAnim(float DeltaTime, bool bJump)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12180);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			*(bool*)&params[4] = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Stop(bool bImmediate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12183);
			byte params[4] = { NULL };
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyTransientScaling(float Scalar)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12185);
			byte params[4] = { NULL };
			*(float*)params = Scalar;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
