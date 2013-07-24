#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Main." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Main : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bSwingingCamera, 0x1)
		ADD_VAR(::StrProperty, TabOffset, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, QueueTimer, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAnimInit, 0x2)
		ADD_VAR(::IntProperty, FeatureSwapTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FeatureShowTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActiveFeature, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoldDealId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumQuit, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
