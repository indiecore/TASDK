#pragma once
#include "Core.Object.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SoundNode.h"
#include "Engine.AudioDevice.h"
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
	class SoundCue : public Object
	{
	public:
		class SoundNodeEditorData
		{
		public:
			ADD_STRUCT(int, NodePosY, 4)
			ADD_STRUCT(int, NodePosX, 0)
		};
		ADD_STRUCT(ScriptString*, FaceFXAnimName, 168)
		ADD_OBJECT(FaceFXAnimSet, FaceFXAnimSetRef, 152)
		ADD_STRUCT(ScriptString*, FaceFXGroupName, 156)
		ADD_STRUCT(ScriptName, SoundGroup, 188)
		ADD_STRUCT(int, CurrentPlayCount, 184)
		ADD_STRUCT(int, MaxConcurrentPlayCount, 180)
		ADD_STRUCT(float, Duration, 148)
		ADD_STRUCT(float, PitchMultiplier, 144)
		ADD_STRUCT(float, VolumeMultiplier, 140)
		ADD_STRUCT(float, MaxAudibleDistance, 136)
		ADD_OBJECT(SoundNode, FirstNode, 72)
		ADD_STRUCT(AudioDevice::ESoundClassName, SoundClassName, 68)
		ADD_STRUCT(ScriptName, SoundClass, 60)
		float GetCueDuration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundCue.GetCueDuration");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
