#pragma once
#include "Core.Component.h"
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
	class DistributionVector : public Component
	{
	public:
		enum EDistributionVectorLockFlags : byte
		{
			EDVLF_None = 0,
			EDVLF_XY = 1,
			EDVLF_XZ = 2,
			EDVLF_YZ = 3,
			EDVLF_XYZ = 4,
			EDVLF_MAX = 5,
		};
		enum EDistributionVectorMirrorFlags : byte
		{
			EDVMF_Same = 0,
			EDVMF_Different = 1,
			EDVMF_Mirror = 2,
			EDVMF_MAX = 3,
		};
		struct RawDistributionVector : public RawDistribution
		{
		};
		ADD_BOOL(bIsDirty, 76, 0x2)
		ADD_BOOL(bCanBeBaked, 76, 0x1)
		ADD_STRUCT(Object::Pointer, VfTable_FCurveEdInterface, 72)
		Vector GetVectorValue(float F, int LastExtreme)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3442);
			byte params[20] = { NULL };
			*(float*)params = F;
			*(int*)&params[4] = LastExtreme;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
