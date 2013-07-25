#pragma once
#include "Engine__NxGenericForceField.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxGenericForceFieldBox." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceFieldBox : public NxGenericForceField
	{
	public:
		ADD_STRUCT(::VectorProperty, BoxExtent, 0xFFFFFFFF)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxGenericForceFieldBox.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
