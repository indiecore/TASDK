#pragma once
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
namespace UnrealScript
{
	class PrimitiveComponentFactory : public Object
	{
	public:
		ADD_BOOL(CastShadow, 60, 0x80)
		ADD_BOOL(HiddenEditor, 60, 0x40)
		ADD_BOOL(HiddenGame, 60, 0x20)
		ADD_BOOL(BlockRigidBody, 60, 0x10)
		ADD_BOOL(BlockNonZeroExtent, 60, 0x8)
		ADD_BOOL(BlockZeroExtent, 60, 0x4)
		ADD_BOOL(BlockActors, 60, 0x2)
		ADD_BOOL(CollideActors, 60, 0x1)
	};
}
#undef ADD_BOOL
