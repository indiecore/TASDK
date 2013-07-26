#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.MusicTrackDataStructures.MusicTrackStruct.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_PlayMusicTrack." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_PlayMusicTrack : public SequenceAction
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<MusicTrackStruct>, MusicTrack, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
