#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Core.System." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class System : public Subsystem
	{
	public:
		ADD_VAR(::IntProperty, StaleCacheDays, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxStaleCacheSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxOverallCacheSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PackageSizeSoftLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AsyncIOBandwidthLimit, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SavePath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CachePath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CacheExt, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ScreenShotPath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TextureFileCacheExtension, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
