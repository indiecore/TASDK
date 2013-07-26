#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameViewportClient.PerPlayerSplitscreenData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PerPlayerSplitscreenData
	{
	public:
		ADD_VAR(::FloatProperty, OriginY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OriginX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
