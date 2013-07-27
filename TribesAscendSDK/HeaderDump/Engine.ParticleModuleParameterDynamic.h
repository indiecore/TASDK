#pragma once
#include "Engine.ParticleModuleParameterBase.h"
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
namespace UnrealScript
{
	class ParticleModuleParameterDynamic : public ParticleModuleParameterBase
	{
	public:
		enum EEmitterDynamicParameterValue : byte
		{
			EDPV_UserSet = 0,
			EDPV_VelocityX = 1,
			EDPV_VelocityY = 2,
			EDPV_VelocityZ = 3,
			EDPV_VelocityMag = 4,
			EDPV_MAX = 5,
		};
		struct EmitterDynamicParameter
		{
		public:
			ADD_STRUCT(DistributionFloat::RawDistributionFloat, ParamValue, 20)
			ADD_BOOL(bScaleVelocityByParamValue, 16, 0x1)
			ADD_STRUCT(ParticleModuleParameterDynamic::EEmitterDynamicParameterValue, ValueMethod, 12)
			ADD_BOOL(bSpawnTimeOnly, 8, 0x2)
			ADD_BOOL(bUseEmitterTime, 8, 0x1)
			ADD_STRUCT(ScriptName, ParamName, 0)
		};
		ADD_STRUCT(ScriptArray<ParticleModuleParameterDynamic::EmitterDynamicParameter>, DynamicParams, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
