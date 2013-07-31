#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.h"
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
	class ModelComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<Object::Pointer>, Nodes, 500)
		ADD_STRUCT(ScriptArray<Object::Pointer>, Elements, 512)
		ADD_STRUCT(int, ComponentIndex, 496)
		ADD_STRUCT(int, ZoneIndex, 492)
		ADD_OBJECT(Object, Model, 488)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
