#pragma once
#include "UDKBase.UDKUIDataProvider_SimpleElementProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_StringArray : public UDKUIDataProvider_SimpleElementProvider
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, Strings, 92)
		int GetElementCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35594);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
