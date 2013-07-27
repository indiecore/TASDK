#pragma once
#include "UnrealEd.FontFactory.h"
#include "Engine.FontImportOptions.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrueTypeFontFactory : public FontFactory
	{
	public:
		ADD_OBJECT(FontImportOptions, ImportOptions, 200)
	};
}
#undef ADD_OBJECT
