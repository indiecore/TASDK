#pragma once
#include "Core.Object.SHVector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.SHVectorRGB." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SHVectorRGB
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<SHVector>, R, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<SHVector>, G, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<SHVector>, B, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
