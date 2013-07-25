#pragma once
#include "Engine.SeqAct_LevelStreamingBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_MultiLevelStreaming." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_MultiLevelStreaming : public SeqAct_LevelStreamingBase
	{
	public:
		ADD_VAR(::BoolProperty, bStatusIsOk, 0x2)
		ADD_VAR(::BoolProperty, bUnloadAllOtherLevels, 0x1)
	};
}
#undef ADD_VAR
