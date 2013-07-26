#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Core.Subsystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Subsystem : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_FExec, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
