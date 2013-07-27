#pragma once
#include "Engine.MaterialInstanceConstant.h"
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
	class MorphNodeWeightByBoneAngle : public MorphNodeWeightBase
	{
	public:
		struct BoneAngleMorph
		{
		public:
			ADD_STRUCT(float, TargetWeight, 4)
			ADD_STRUCT(float, Angle, 0)
		};
		ADD_STRUCT(ScriptArray<MorphNodeWeightByBoneAngle::BoneAngleMorph>, WeightArray, 168)
		ADD_OBJECT(MaterialInstanceConstant, MaterialInstanceConstant, 164)
		ADD_STRUCT(ScriptName, ScalarParameterName, 156)
		ADD_STRUCT(int, MaterialSlotId, 152)
		ADD_STRUCT(ScriptName, AngleBoneName, 144)
		ADD_BOOL(bControlMaterialParameter, 140, 0x4)
		ADD_BOOL(bInvertAngleBoneAxis, 140, 0x2)
		ADD_BOOL(bInvertBaseBoneAxis, 140, 0x1)
		ADD_STRUCT(Object::EAxis, AngleBoneAxis, 137)
		ADD_STRUCT(Object::EAxis, BaseBoneAxis, 136)
		ADD_STRUCT(ScriptName, BaseBoneName, 128)
		ADD_STRUCT(float, NodeWeight, 124)
		ADD_STRUCT(float, Angle, 120)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
