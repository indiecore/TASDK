#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_VideoSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_VideoSettings : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, MotionBlurNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FrameSmoothNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VSyncNumber, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
