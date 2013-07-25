#pragma once
#include "UnrealEd.FontFactory.h"
#include "Engine.FontImportOptions.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UnrealEd.TrueTypeFontFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrueTypeFontFactory : public FontFactory
	{
	public:
		ADD_OBJECT(FontImportOptions, ImportOptions)
	};
}
#undef ADD_OBJECT
