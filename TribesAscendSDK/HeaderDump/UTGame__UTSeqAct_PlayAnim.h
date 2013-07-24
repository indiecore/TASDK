#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_PlayAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSeqAct_PlayAnim : public SequenceAction
	{
	public:
		ADD_VAR(::NameProperty, AnimName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLooping, 0x1)
	};
}
#undef ADD_VAR
