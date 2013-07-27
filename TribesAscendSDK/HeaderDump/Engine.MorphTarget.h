#pragma once
#include "Core.Object.h"
#include "Engine.MaterialInstanceConstant.h"
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
	class MorphTarget : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<int>, MorphLODModels, 60)
		ADD_OBJECT(MaterialInstanceConstant, MaterialInstanceConstant, 84)
		ADD_STRUCT(ScriptName, ScalarParameterName, 76)
		ADD_STRUCT(int, MaterialSlotId, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
