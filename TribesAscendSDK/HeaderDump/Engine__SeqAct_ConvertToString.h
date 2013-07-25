#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ConvertToString." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ConvertToString : public SequenceAction
	{
	public:
		ADD_VAR(::IntProperty, NumberOfInputs, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VarSeparator, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIncludeVarComment, 0x1)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_ConvertToString.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
