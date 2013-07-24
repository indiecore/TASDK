#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_PrepareMapChange." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_PrepareMapChange : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bStatusIsOk, 0x2)
		ADD_VAR(::BoolProperty, bIsHighPriority, 0x1)
		ADD_VAR(::NameProperty, MainLevelName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
