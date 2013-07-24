#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_Mover." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Mover : public SequenceEvent
	{
	public:
		ADD_VAR(::FloatProperty, StayOpenTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
