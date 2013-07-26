#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AITree.AITreeUtilityInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AITree.AITreeUtilityInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AITreeUtilityInfo
	{
	public:
		ADD_VAR(::FloatProperty, UtilityRating, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, CommandClass)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
