#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerTime : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bBoundsPopup, 0x10)
		ADD_VAR(::BoolProperty, bRespawnTimePopup, 0x8)
		ADD_VAR(::BoolProperty, bOverTimeLimitPopup, 0x4)
		ADD_VAR(::BoolProperty, bTimeLimitPopup, 0x2)
		ADD_VAR(::BoolProperty, bWarmupTimePopup, 0x1)
		ADD_VAR(::IntProperty, MaxBOunds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinBounds, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
