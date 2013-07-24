#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ModifyObjectList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ModifyObjectList : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_VAR(::IntProperty, ListEntriesCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
