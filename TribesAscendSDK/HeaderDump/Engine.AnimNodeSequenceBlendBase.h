#pragma once
#include "Engine.AnimNodeSequence.h"
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
	class AnimNodeSequenceBlendBase : public AnimNodeSequence
	{
	public:
		struct AnimInfo
		{
		public:
			ADD_STRUCT(int, AnimLinkupIndex, 12)
			ADD_OBJECT(AnimSequence, AnimSeq, 8)
			ADD_STRUCT(ScriptName, AnimSeqName, 0)
		};
		struct AnimBlendInfo
		{
		public:
			ADD_STRUCT(float, Weight, 24)
			ADD_STRUCT(AnimNodeSequenceBlendBase::AnimInfo, AnimInfo, 8)
			ADD_STRUCT(ScriptName, AnimName, 0)
		};
		ADD_STRUCT(ScriptArray<AnimNodeSequenceBlendBase::AnimBlendInfo>, Anims, 320)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
