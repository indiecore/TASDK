#pragma once
#include "Engine.SequenceAction.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_GetLocationAndRotation : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptName, SocketOrBoneName, 268)
		ADD_STRUCT(Vector, Rotation, 256)
		ADD_STRUCT(Vector, RotationVector, 244)
		ADD_STRUCT(Vector, Location, 232)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25693);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
