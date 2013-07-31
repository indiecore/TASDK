#pragma once
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.MorphNodeWeightByBoneAngle.h"
#include "Engine.MorphNodeWeightBase.h"
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
	class MorphNodeWeightByBoneRotation : public MorphNodeWeightBase
	{
	public:
		ADD_STRUCT(ScriptArray<MorphNodeWeightByBoneAngle::BoneAngleMorph>, WeightArray, 144)
		ADD_OBJECT(MaterialInstanceConstant, MaterialInstanceConstant, 168)
		ADD_STRUCT(ScriptName, ScalarParameterName, 160)
		ADD_STRUCT(int, MaterialSlotId, 156)
		ADD_BOOL(bControlMaterialParameter, 140, 0x2)
		ADD_BOOL(bInvertBoneAxis, 140, 0x1)
		ADD_STRUCT(Object::EAxis, BoneAxis, 136)
		ADD_STRUCT(ScriptName, BoneName, 128)
		ADD_STRUCT(float, NodeWeight, 124)
		ADD_STRUCT(float, Angle, 120)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
