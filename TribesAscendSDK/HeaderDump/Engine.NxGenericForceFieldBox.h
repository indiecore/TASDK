#pragma once
#include "Engine.NxGenericForceField.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceFieldBox : public NxGenericForceField
	{
	public:
		ADD_STRUCT(Vector, BoxExtent, 700)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21283);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
