#pragma once
#include "Engine.AnimNotify.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.ParticleSystem.h"
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
	class AnimNotify_Trails : public AnimNotify
	{
	public:
		class TrailSample
		{
		public:
			ADD_STRUCT(Object::Vector, SecondEdgeSample, 28)
			ADD_STRUCT(Object::Vector, ControlPointSample, 16)
			ADD_STRUCT(Object::Vector, FirstEdgeSample, 4)
			ADD_STRUCT(float, RelativeTime, 0)
		};
		class TrailSocketSamplePoint
		{
		public:
			ADD_STRUCT(Object::Vector, Velocity, 12)
			ADD_STRUCT(Object::Vector, Position, 0)
		};
		class TrailSamplePoint
		{
		public:
			ADD_STRUCT(AnimNotify_Trails::TrailSocketSamplePoint, SecondEdgeSample, 52)
			ADD_STRUCT(AnimNotify_Trails::TrailSocketSamplePoint, ControlPointSample, 28)
			ADD_STRUCT(AnimNotify_Trails::TrailSocketSamplePoint, FirstEdgeSample, 4)
			ADD_STRUCT(float, RelativeTime, 0)
		};
		ADD_STRUCT(ScriptArray<AnimNotify_Trails::TrailSamplePoint>, TrailSampleData, 108)
		ADD_STRUCT(ScriptArray<AnimNotify_Trails::TrailSample>, TrailSampledData, 124)
		ADD_OBJECT(AnimNodeSequence, AnimNodeSeq, 144)
		ADD_STRUCT(float, TimeStep, 140)
		ADD_STRUCT(float, CurrentTime, 136)
		ADD_STRUCT(float, SamplesPerSecond, 120)
		ADD_STRUCT(float, SampleTimeStep, 104)
		ADD_STRUCT(float, EndTime, 100)
		ADD_STRUCT(float, LastStartTime, 96)
		ADD_STRUCT(ScriptName, SecondEdgeSocketName, 88)
		ADD_STRUCT(ScriptName, ControlPointSocketName, 80)
		ADD_STRUCT(ScriptName, FirstEdgeSocketName, 72)
		ADD_BOOL(bResampleRequired, 68, 0x8)
		ADD_BOOL(bSkipIfOwnerIsHidden, 68, 0x4)
		ADD_BOOL(bPreview, 68, 0x2)
		ADD_BOOL(bIsExtremeContent, 68, 0x1)
		ADD_OBJECT(ParticleSystem, PSTemplate, 64)
		int GetNumSteps(int InLastTrailIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify_Trails.GetNumSteps");
			byte params[8] = { NULL };
			*(int*)&params[0] = InLastTrailIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
