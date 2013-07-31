#pragma once
#include "Engine.ParticleModule.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberBase : public ParticleModule
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, RequiredModules, 72)
	};
}
#undef ADD_STRUCT
