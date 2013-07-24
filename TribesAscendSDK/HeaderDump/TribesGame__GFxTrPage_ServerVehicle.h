#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerVehicle : public GFxTrPage
	{
	public:
		ADD_VAR(::FloatProperty, MaxBOunds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinBounds, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBoundsPopup, 0x1)
		ADD_VAR(::IntProperty, PopupNumber, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
