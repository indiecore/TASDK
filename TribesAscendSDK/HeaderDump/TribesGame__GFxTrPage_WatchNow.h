#pragma once
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
	};
}
#undef ADD_VAR
