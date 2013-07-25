#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_AttachToActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_AttachToActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_AttachToActor : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bDetach, 0x1)
		ADD_VAR(::BoolProperty, bHardAttach, 0x2)
		ADD_VAR(::BoolProperty, bUseRelativeOffset, 0x4)
		ADD_VAR(::BoolProperty, bUseRelativeRotation, 0x8)
		ADD_STRUCT(::RotatorProperty, RelativeRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RelativeOffset, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_AttachToActor.GetObjClassVersion");
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
