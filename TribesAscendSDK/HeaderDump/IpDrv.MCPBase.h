#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.MCPBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MCPBase : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_FTickableObject, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
