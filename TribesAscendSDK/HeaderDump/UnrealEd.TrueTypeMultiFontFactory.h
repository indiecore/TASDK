#pragma once
#include "UnrealEd.TrueTypeFontFactory.h"
#include "Engine.Font.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrueTypeMultiFontFactory : public TrueTypeFontFactory
	{
	public:
		ADD_STRUCT(ScriptArray<float>, ResTests, 204)
		ADD_STRUCT(ScriptArray<float>, ResHeights, 216)
		ADD_STRUCT(ScriptArray<class Font*>, ResFonts, 228)
	};
}
#undef ADD_STRUCT
