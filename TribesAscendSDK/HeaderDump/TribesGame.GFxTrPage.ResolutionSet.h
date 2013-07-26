#pragma once
#include "PlatformCommon.TgPlayerProfile.PropertyPair.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxTrPage.ResolutionSet." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxTrPage.ResolutionSet." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ResolutionSet
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<PropertyPair>, Res, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Index, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
