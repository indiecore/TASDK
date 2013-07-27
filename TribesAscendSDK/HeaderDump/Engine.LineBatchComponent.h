#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class LineBatchComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<Object::Pointer>, BatchedLines, 496)
		ADD_STRUCT(ScriptArray<Object::Pointer>, BatchedPoints, 508)
		ADD_STRUCT(float, DefaultLifeTime, 520)
		ADD_STRUCT(Object::Pointer, FPrimitiveDrawInterfaceView, 492)
		ADD_STRUCT(Object::Pointer, FPrimitiveDrawInterfaceVfTable, 488)
	};
}
#undef ADD_STRUCT
