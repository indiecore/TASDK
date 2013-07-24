#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerEditCallin." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerEditCallin : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, CallinType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBoundsPopup, 0x2)
		ADD_VAR(::BoolProperty, bPopup, 0x1)
		ADD_VAR(::IntProperty, popupIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BuildupIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CooldownIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PriceIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EnabledIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ORBNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SUPNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TACNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxBOunds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinBounds, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
