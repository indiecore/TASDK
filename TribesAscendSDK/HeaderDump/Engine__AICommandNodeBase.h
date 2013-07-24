#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AICommandNodeBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AICommandNodeBase : public K2NodeBase
	{
	public:
		ADD_OBJECT(DMC_Prototype, UtilityDMC)
	};
}
#undef ADD_OBJECT
