#pragma once
#include "Engine.ParticleModuleOrientationBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleOrientationAxisLock : public ParticleModuleOrientationBase
	{
	public:
		enum EParticleAxisLock : byte
		{
			EPAL_NONE = 0,
			EPAL_X = 1,
			EPAL_Y = 2,
			EPAL_Z = 3,
			EPAL_NEGATIVE_X = 4,
			EPAL_NEGATIVE_Y = 5,
			EPAL_NEGATIVE_Z = 6,
			EPAL_ROTATE_X = 7,
			EPAL_ROTATE_Y = 8,
			EPAL_ROTATE_Z = 9,
			EPAL_MAX = 10,
		};
		ADD_STRUCT(ParticleModuleOrientationAxisLock::EParticleAxisLock, LockAxisFlags, 72)
	};
}
#undef ADD_STRUCT
