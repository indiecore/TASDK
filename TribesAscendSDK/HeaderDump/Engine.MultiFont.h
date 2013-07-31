#pragma once
#include "Engine.Font.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MultiFont : public Font
	{
	public:
		ADD_STRUCT(ScriptArray<float>, ResolutionTestTable, 332)
		int GetResolutionTestTableIndex(float HeightTest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20669);
			byte params[8] = { NULL };
			*(float*)params = HeightTest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
#undef ADD_STRUCT
