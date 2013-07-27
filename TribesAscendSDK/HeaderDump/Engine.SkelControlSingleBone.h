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
	class SkelControlSingleBone : public SkelControlBase
	{
	public:
		ADD_STRUCT(ScriptName, RotationSpaceBoneName, 228)
		ADD_STRUCT(Object::Rotator, BoneRotation, 216)
		ADD_STRUCT(ScriptName, TranslationSpaceBoneName, 208)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, BoneRotationSpace, 205)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, BoneTranslationSpace, 204)
		ADD_STRUCT(Object::Vector, BoneTranslation, 192)
		ADD_BOOL(bRemoveMeshRotation, 188, 0x10)
		ADD_BOOL(bAddRotation, 188, 0x8)
		ADD_BOOL(bAddTranslation, 188, 0x4)
		ADD_BOOL(bApplyRotation, 188, 0x2)
		ADD_BOOL(bApplyTranslation, 188, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
