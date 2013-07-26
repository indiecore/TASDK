#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrCaHStats.CapturePointInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CapturePointInfo
	{
	public:
		ADD_VAR(::FloatProperty, RemainingHeldTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PctHeld, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PointOwnershipType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LabelString, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PointLabel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
