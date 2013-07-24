#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Level." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Level : public LevelBase
	{
	public:
		ADD_VAR(::FloatProperty, LightmapTotalSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ShadowmapTotalSize, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
