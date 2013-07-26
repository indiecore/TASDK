#pragma once
#include "Core.Object.LinearColor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ProcBuilding.PBMaterialParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ProcBuilding.PBMaterialParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBMaterialParam
	{
	public:
		ADD_VAR(::NameProperty, ParamName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, Color, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
