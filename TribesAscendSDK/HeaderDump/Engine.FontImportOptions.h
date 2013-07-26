#pragma once
#include "Core.Object.h"
#include "Engine.FontImportOptions.FontImportOptionsData.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FontImportOptions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FontImportOptions : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<FontImportOptionsData>, Data, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
