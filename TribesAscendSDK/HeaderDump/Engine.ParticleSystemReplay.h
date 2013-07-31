#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleSystemReplay : public Object
	{
	public:
		struct ParticleEmitterReplayFrame
		{
		public:
			ADD_STRUCT(Object::Pointer, FrameState, 8)
			ADD_STRUCT(int, OriginalEmitterIndex, 4)
			ADD_STRUCT(int, EmitterType, 0)
		};
		struct ParticleSystemReplayFrame
		{
		public:
			ADD_STRUCT(ScriptArray<ParticleSystemReplay::ParticleEmitterReplayFrame>, Emitters, 0)
		};
		ADD_STRUCT(ScriptArray<ParticleSystemReplay::ParticleSystemReplayFrame>, Frames, 64)
		ADD_STRUCT(int, ClipIDNumber, 60)
	};
}
#undef ADD_STRUCT
