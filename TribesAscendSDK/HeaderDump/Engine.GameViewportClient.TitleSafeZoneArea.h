#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameViewportClient.TitleSafeZoneArea." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TitleSafeZoneArea
	{
	public:
		ADD_VAR(::FloatProperty, MaxPercentX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RecommendedPercentX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPercentY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RecommendedPercentY, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
