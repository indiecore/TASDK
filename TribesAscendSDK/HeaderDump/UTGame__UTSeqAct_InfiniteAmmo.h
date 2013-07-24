#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_InfiniteAmmo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSeqAct_InfiniteAmmo : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bInfiniteAmmo, 0x1)
	};
}
#undef ADD_VAR
