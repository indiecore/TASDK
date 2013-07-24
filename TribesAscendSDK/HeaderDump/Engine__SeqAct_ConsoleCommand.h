#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ConsoleCommand." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ConsoleCommand : public SequenceAction
	{
	public:
		ADD_VAR(::StrProperty, Command, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
