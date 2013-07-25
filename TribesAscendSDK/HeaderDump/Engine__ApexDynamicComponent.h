#pragma once
#include "Engine__ApexComponentBase.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ApexDynamicComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexDynamicComponent : public ApexComponentBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ComponentDynamicResources'!
	};
}
#undef ADD_STRUCT
