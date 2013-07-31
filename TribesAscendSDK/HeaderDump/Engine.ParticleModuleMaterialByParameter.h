#pragma once
#include "Engine.ParticleModuleMaterialBase.h"
#include "Engine.MaterialInterface.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleMaterialByParameter : public ParticleModuleMaterialBase
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, MaterialParameters, 72)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, DefaultMaterials, 84)
	};
}
#undef ADD_STRUCT
