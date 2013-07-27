#pragma once
#include "Engine.ApexGenericAsset.h"
#include "Engine.MaterialInterface.h"
#include "Engine.ApexAsset.h"
#include "Core.Object.h"
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
	class ApexClothingAsset : public ApexAsset
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 112)
		ADD_STRUCT(float, LodWeightsBenefitsBias, 160)
		ADD_STRUCT(float, LodWeightsBias, 156)
		ADD_STRUCT(float, LodWeightsDistanceWeight, 152)
		ADD_STRUCT(float, LodWeightsMaxDistance, 148)
		ADD_STRUCT(float, ContinuousDistanceThreshold, 144)
		ADD_STRUCT(float, ContinuousRotationThreshold, 140)
		ADD_STRUCT(float, MaxDistanceBlendTime, 136)
		ADD_STRUCT(int, UVChannelForTangentUpdate, 132)
		ADD_BOOL(bRecomputeNormals, 128, 0x8)
		ADD_BOOL(bSlowStart, 128, 0x4)
		ADD_BOOL(bFallbackSkinning, 128, 0x2)
		ADD_BOOL(bUseHardwareCloth, 128, 0x1)
		ADD_OBJECT(ApexGenericAsset, ApexClothingLibrary, 124)
		ADD_STRUCT(Object::Pointer, MApexAsset, 108)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
