#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Core.DistributionFloat.h"
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
	class ParticleModuleTypeDataBeam2 : public ParticleModuleTypeDataBase
	{
	public:
		enum EBeam2Method : byte
		{
			PEB2M_Distance = 0,
			PEB2M_Target = 1,
			PEB2M_Branch = 2,
			PEB2M_MAX = 3,
		};
		enum EBeamTaperMethod : byte
		{
			PEBTM_None = 0,
			PEBTM_Full = 1,
			PEBTM_Partial = 2,
			PEBTM_MAX = 3,
		};
		class BeamTargetData
		{
		public:
			ADD_STRUCT(float, TargetPercentage, 8)
			ADD_STRUCT(ScriptName, TargetName, 0)
		};
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, TaperScale, 172)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, TaperFactor, 144)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Distance, 116)
		ADD_STRUCT(ScriptName, BranchParentName, 108)
		ADD_STRUCT(int, UpVectorStepSize, 104)
		ADD_BOOL(RenderTessellation, 100, 0x10)
		ADD_BOOL(RenderLines, 100, 0x8)
		ADD_BOOL(RenderDirectLine, 100, 0x4)
		ADD_BOOL(RenderGeometry, 100, 0x2)
		ADD_BOOL(bAlwaysOn, 100, 0x1)
		ADD_STRUCT(int, InterpolationPoints, 96)
		ADD_STRUCT(float, Speed, 92)
		ADD_STRUCT(int, MaxBeamCount, 88)
		ADD_STRUCT(int, Sheets, 84)
		ADD_STRUCT(float, TextureTileDistance, 80)
		ADD_STRUCT(int, TextureTile, 76)
		ADD_STRUCT(ParticleModuleTypeDataBeam2::EBeamTaperMethod, TaperMethod, 73)
		ADD_STRUCT(ParticleModuleTypeDataBeam2::EBeam2Method, BeamMethod, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
