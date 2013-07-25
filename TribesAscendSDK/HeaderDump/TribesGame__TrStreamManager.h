#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStreamManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrStreamManager : public Object
	{
	public:
		ADD_VAR(::StrProperty, StreamServer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StreamPath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StreamURL, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WatchEnd, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WatchStart, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TokViewers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TokTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TokName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NewsIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUpdateReady, 0x1)
		// Here lies the not-yet-implemented method 'GetTitleAtIndex'
		// Here lies the not-yet-implemented method 'IsLiveAtIndex'
		// Here lies the not-yet-implemented method 'GetViewersAtIndex'
		// Here lies the not-yet-implemented method 'GetDescriptionAtIndex'
		// Here lies the not-yet-implemented method 'HaveFeature'
		// Here lies the not-yet-implemented method 'GetFeatureName'
		// Here lies the not-yet-implemented method 'IsStream'
		// Here lies the not-yet-implemented method 'GetTypeCountWatching'
		// Here lies the not-yet-implemented method 'GetTypeCount'
		// Here lies the not-yet-implemented method 'GetFeatureDescription'
		// Here lies the not-yet-implemented method 'ViewerSort'
		// Here lies the not-yet-implemented method 'LoadStreams'
		// Here lies the not-yet-implemented method 'GetStreamData'
		// Here lies the not-yet-implemented method 'OpenStream'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ViewStreamIndex'
		// Here lies the not-yet-implemented method 'ViewVideoIndex'
		// Here lies the not-yet-implemented method 'StartTVTimer'
		// Here lies the not-yet-implemented method 'UpdateStreams'
		// Here lies the not-yet-implemented method 'CheckForUpdate'
		// Here lies the not-yet-implemented method 'GetLatestNews'
		// Here lies the not-yet-implemented method 'CompleteUpdate'
	};
}
#undef ADD_VAR
