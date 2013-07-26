#pragma once
#include "Engine.ApexComponentBase.h"
#include "Core.Object.Pointer.h"
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
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ComponentDynamicResources, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
