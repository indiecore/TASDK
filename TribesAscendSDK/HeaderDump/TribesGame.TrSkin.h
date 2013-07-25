#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSkin." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrSkin." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrSkin : public Object
	{
	public:
		ADD_VAR(::StrProperty, ItemName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, InfoPanelDescription, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TranslucencySortPriority, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ItemId, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SkinMeleeDevice)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
