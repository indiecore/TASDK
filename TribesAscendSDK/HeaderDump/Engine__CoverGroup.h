#pragma once
#include "Engine__Info.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CoverGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CoverGroup : public Info
	{
	public:
		ADD_VAR(::FloatProperty, AutoSelectHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoSelectRadius, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'EnableGroup'
		// Here lies the not-yet-implemented method 'DisableGroup'
		// Here lies the not-yet-implemented method 'ToggleGroup'
		// Here lies the not-yet-implemented method 'OnToggle'
	};
}
#undef ADD_VAR
