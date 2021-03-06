#pragma once
#include "Engine.PBRuleNodeBase.h"
#include "Engine.MaterialInterface.h"
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
	class PBRuleNodeWindowWall : public PBRuleNodeBase
	{
	public:
		ADD_OBJECT(MaterialInterface, Material, 136)
		ADD_STRUCT(float, YOffset, 132)
		ADD_BOOL(bScaleWindowWithCell, 128, 0x1)
		ADD_STRUCT(float, WindowPosZ, 124)
		ADD_STRUCT(float, WindowPosX, 120)
		ADD_STRUCT(float, WindowSizeZ, 116)
		ADD_STRUCT(float, WindowSizeX, 112)
		ADD_STRUCT(float, CellMaxSizeZ, 108)
		ADD_STRUCT(float, CellMaxSizeX, 104)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
