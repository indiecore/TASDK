#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_AIStartFireAt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSeqAct_AIStartFireAt : public SequenceAction
	{
	public:
		ADD_VAR(::ByteProperty, ForcedFireMode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
