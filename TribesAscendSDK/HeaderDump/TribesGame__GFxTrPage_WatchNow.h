#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_WatchNow." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_WatchNow : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, strCmntyVideos, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strTrainVideos, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strHiRezVideos, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, strLiveStreams, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumCmntyVideos, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumTrainVideos, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumHiRezVideos, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumLiveStreams, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'UpdateStreams'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'IsFeatured'
	};
}
#undef ADD_VAR
