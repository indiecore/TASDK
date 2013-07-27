#pragma once
#include "Engine.SkelControlBase.h"
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
namespace UnrealScript
{
	class SkelControl_CCD_IK : public SkelControlBase
	{
	public:
		ADD_STRUCT(ScriptArray<float>, AngleConstraint, 244)
		ADD_STRUCT(float, MaxAngleSteps, 256)
		ADD_BOOL(bNoTurnOptimization, 240, 0x2)
		ADD_BOOL(bStartFromTail, 240, 0x1)
		ADD_STRUCT(float, Precision, 236)
		ADD_STRUCT(int, IterationsCount, 232)
		ADD_STRUCT(int, MaxPerBoneIterations, 228)
		ADD_STRUCT(int, NumBones, 224)
		ADD_STRUCT(Vector, EffectorTranslationFromBone, 212)
		ADD_STRUCT(ScriptName, EffectorSpaceBoneName, 204)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, EffectorLocationSpace, 200)
		ADD_STRUCT(Vector, EffectorLocation, 188)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
