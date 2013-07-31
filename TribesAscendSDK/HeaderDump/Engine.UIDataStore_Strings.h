#pragma once
#include "Engine.UIConfigFileProvider.h"
#include "Engine.UIDataStore_StringBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_Strings : public UIDataStore_StringBase
	{
	public:
		ADD_STRUCT(ScriptArray<class UIConfigFileProvider*>, LocFileProviders, 120)
	};
}
#undef ADD_STRUCT
