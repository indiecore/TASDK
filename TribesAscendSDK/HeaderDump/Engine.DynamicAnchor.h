#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Controller.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DynamicAnchor : public NavigationPoint
	{
	public:
		ADD_OBJECT(Controller, CurrentUser, 692)
	};
}
#undef ADD_OBJECT
