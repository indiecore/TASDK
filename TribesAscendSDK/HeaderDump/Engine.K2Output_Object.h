#pragma once
#include "Engine.K2Output.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class K2Output_Object : public K2Output
	{
	public:
		ADD_OBJECT(ScriptClass, ObjClass, 92)
	};
}
#undef ADD_OBJECT
