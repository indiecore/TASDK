#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Core.DistributionFloat.h"
#include "Core.DistributionVector.h"
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
	class ParticleModuleTypeDataBeam : public ParticleModuleTypeDataBase
	{
	public:
		enum EBeamMethod : byte
		{
			PEBM_Distance = 0,
			PEBM_EndPoints = 1,
			PEBM_EndPoints_Interpolated = 2,
			PEBM_UserSet_EndPoints = 3,
			PEBM_UserSet_EndPoints_Interpolated = 4,
			PEBM_MAX = 5,
		};
		enum EBeamEndPointMethod : byte
		{
			PEBEPM_Calculated = 0,
			PEBEPM_Distribution = 1,
			PEBEPM_Distribution_Constant = 2,
			PEBEPM_MAX = 3,
		};
		ADD_BOOL(RenderTessellation, 224, 0x8)
		ADD_BOOL(RenderLines, 224, 0x4)
		ADD_BOOL(RenderDirectLine, 224, 0x2)
		ADD_BOOL(RenderGeometry, 224, 0x1)
		ADD_STRUCT(int, TextureTile, 220)
		ADD_STRUCT(DistributionVector::RawDistributionVector, EndPointDirection, 192)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, TargetStrength, 164)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, EmitterStrength, 136)
		ADD_STRUCT(int, TessellationFactor, 132)
		ADD_STRUCT(DistributionVector::RawDistributionVector, EndPoint, 104)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Distance, 76)
		ADD_STRUCT(ParticleModuleTypeDataBeam::EBeamEndPointMethod, EndPointMethod, 73)
		ADD_STRUCT(ParticleModuleTypeDataBeam::EBeamMethod, BeamMethod, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
