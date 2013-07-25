#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_GetLocationAndRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_GetLocationAndRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_GetLocationAndRotation : public SequenceAction
	{
	public:
		ADD_VAR(::NameProperty, SocketOrBoneName, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Rotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, RotationVector, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_GetLocationAndRotation.GetObjClassVersion");
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
