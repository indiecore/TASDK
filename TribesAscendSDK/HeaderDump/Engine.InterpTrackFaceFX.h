#pragma once
#include "Engine.InterpTrack.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.FaceFXAsset.h"
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
	class InterpTrackFaceFX : public InterpTrack
	{
	public:
		class FaceFXTrackKey
		{
		public:
			ADD_STRUCT(ScriptString*, FaceFXSeqName, 16)
			ADD_STRUCT(ScriptString*, FaceFXGroupName, 4)
			ADD_STRUCT(float, StartTime, 0)
		};
		class FaceFXSoundCueKey
		{
		public:
			ADD_OBJECT(SoundCue, FaceFXSoundCue, 0)
		};
		ADD_STRUCT(ScriptArray<class FaceFXAnimSet*>, FaceFXAnimSets, 128)
		ADD_STRUCT(ScriptArray<InterpTrackFaceFX::FaceFXTrackKey>, FaceFXSeqs, 140)
		ADD_STRUCT(ScriptArray<InterpTrackFaceFX::FaceFXSoundCueKey>, FaceFXSoundCueKeys, 156)
		ADD_OBJECT(FaceFXAsset, CachedActorFXAsset, 152)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
