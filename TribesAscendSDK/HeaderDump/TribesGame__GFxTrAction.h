#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrAction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrAction." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrAction : public Object
	{
	public:
		ADD_OBJECT(GFxTrPage, ActionPage)
		ADD_VAR(::StrProperty, ActionString, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActionNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActionIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
