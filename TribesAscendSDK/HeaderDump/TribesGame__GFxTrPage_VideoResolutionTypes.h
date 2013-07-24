#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_VideoResolutionTypes." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_VideoResolutionTypes : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bShowingSixteenbyTen, 0x4)
		ADD_VAR(::BoolProperty, bShowingSixteenByNine, 0x2)
		ADD_VAR(::BoolProperty, bShowingFourByThree, 0x1)
		ADD_VAR(::IntProperty, SixteenbyTen, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SixteenByNine, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FourByThree, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
