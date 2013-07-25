#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Log." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_Log." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Log : public SequenceAction
	{
	public:
		ADD_VAR(::StrProperty, LogMessage, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIncludeObjComment, 0x2)
		ADD_VAR(::BoolProperty, bOutputToScreen, 0x1)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Log.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
