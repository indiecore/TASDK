#pragma once
#include "Engine.UIDataProvider.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_SimpleElementProvider : public UIDataProvider
	{
	public:
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 88)
		int GetElementCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35585);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
