#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqVar_Float." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqVar_Float : public SequenceVariable
	{
	public:
		ADD_VAR(::FloatProperty, FloatValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
