#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MorphNodeBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MorphNodeBase : public AnimObject
	{
	public:
		ADD_VAR(::BoolProperty, bDrawSlider, 0x1)
		ADD_VAR(::NameProperty, NodeName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
