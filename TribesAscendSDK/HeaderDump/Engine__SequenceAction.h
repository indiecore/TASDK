#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceAction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SequenceAction : public SequenceOp
	{
	public:
		ADD_VAR(::BoolProperty, bCallHandler, 0x1)
		ADD_VAR(::NameProperty, HandlerName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
