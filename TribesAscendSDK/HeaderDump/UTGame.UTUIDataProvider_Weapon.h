#pragma once
#include "UTGame.UTUIResourceDataProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_Weapon : public UTUIResourceDataProvider
	{
	public:
		ADD_STRUCT(ScriptString*, Description, 188)
		ADD_STRUCT(ScriptString*, Flags, 176)
		ADD_STRUCT(ScriptString*, AmmoClassPath, 164)
		ADD_STRUCT(ScriptString*, ClassName, 152)
	};
}
#undef ADD_STRUCT
