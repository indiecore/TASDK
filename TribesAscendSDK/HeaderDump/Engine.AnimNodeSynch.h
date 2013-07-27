#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.AnimNodeSequence.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeSynch : public AnimNodeBlendBase
	{
	public:
		struct SynchGroup
		{
		public:
			ADD_STRUCT(ScriptArray<class AnimNodeSequence*>, SeqNodes, 0)
			ADD_STRUCT(float, RateScale, 28)
			ADD_BOOL(bFireSlaveNotifies, 24, 0x1)
			ADD_STRUCT(ScriptName, GroupName, 16)
			ADD_OBJECT(AnimNodeSequence, MasterNode, 12)
		};
		ADD_STRUCT(ScriptArray<AnimNodeSynch::SynchGroup>, Groups, 244)
		void AddNodeToGroup(class AnimNodeSequence* SeqNode, ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11109);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(ScriptName*)&params[4] = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveNodeFromGroup(class AnimNodeSequence* SeqNode, ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11112);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(ScriptName*)&params[4] = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class AnimNodeSequence* GetMasterNodeOfGroup(ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11115);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNodeSequence**)&params[8];
		}
		void ForceRelativePosition(ScriptName GroupName, float RelativePosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11118);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			*(float*)&params[8] = RelativePosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetRelativePosition(ScriptName GroupName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11121);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void SetGroupRateScale(ScriptName GroupName, float NewRateScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11124);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			*(float*)&params[8] = NewRateScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
