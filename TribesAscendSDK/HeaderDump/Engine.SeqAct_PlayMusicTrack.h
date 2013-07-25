#pragma once
#include "Engine.SequenceAction.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.MusicTrackDataStructures.MusicTrackStruct' for the property named 'MusicTrack'!
	};
}
#undef ADD_STRUCT
