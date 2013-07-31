#pragma once
#include "Engine.Interaction.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TgBrowserInteraction : public Interaction
	{
	public:
		ADD_STRUCT(Object::Pointer, VfTable_FCallbackEventDevice, 108)
	};
}
#undef ADD_STRUCT
