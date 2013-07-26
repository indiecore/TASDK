#pragma once
#include "TribesGame.TrValueModifier.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrFamilyInfo.SkillNode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrFamilyInfo.SkillNode." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkillNode
	{
	public:
		ADD_VAR(::IntProperty, Cost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ParentIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconPosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconPosX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Value, 0xFFFFFFFF)
		ADD_OBJECT(TrValueModifier, ValueModifier)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
