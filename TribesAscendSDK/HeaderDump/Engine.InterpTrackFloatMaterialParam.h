#pragma once
#include "Engine.InterpTrackFloatBase.h"
#include "Engine.MaterialInterface.h"
#include "Engine.EngineTypes.h"
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
	class InterpTrackFloatMaterialParam : public InterpTrackFloatBase
	{
	public:
		ADD_STRUCT(ScriptArray<EngineTypes::MaterialReferenceList>, Materials, 148)
		ADD_BOOL(bNeedsMaterialRefsUpdate, 172, 0x1)
		ADD_STRUCT(ScriptName, ParamName, 164)
		ADD_OBJECT(MaterialInterface, Material, 160)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
