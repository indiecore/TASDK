#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Actor.AnimSlotDesc." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimSlotDesc
	{
	public:
		ADD_VAR(::NameProperty, SlotName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumChannels, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
