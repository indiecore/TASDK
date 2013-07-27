#pragma once
#include "Core.Subsystem.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class System : public Subsystem
	{
	public:
		ADD_STRUCT(int, StaleCacheDays, 64)
		ADD_STRUCT(int, MaxStaleCacheSize, 68)
		ADD_STRUCT(int, MaxOverallCacheSize, 72)
		ADD_STRUCT(int, PackageSizeSoftLimit, 76)
		ADD_STRUCT(float, AsyncIOBandwidthLimit, 80)
		ADD_STRUCT(ScriptString*, SavePath, 84)
		ADD_STRUCT(ScriptString*, CachePath, 96)
		ADD_STRUCT(ScriptString*, CacheExt, 108)
		ADD_STRUCT(ScriptString*, ScreenShotPath, 120)
		ADD_STRUCT(ScriptArray<ScriptString*>, Paths, 132)
		ADD_STRUCT(ScriptArray<ScriptString*>, ScriptPaths, 156)
		ADD_STRUCT(ScriptArray<ScriptString*>, FRScriptPaths, 168)
		ADD_STRUCT(ScriptArray<ScriptName>, Suppress, 192)
		ADD_STRUCT(ScriptArray<ScriptString*>, Extensions, 204)
		ADD_STRUCT(ScriptString*, TextureFileCacheExtension, 240)
		ADD_STRUCT(ScriptArray<ScriptString*>, LocalizationPaths, 228)
		ADD_STRUCT(ScriptArray<ScriptString*>, CutdownPaths, 180)
		ADD_STRUCT(ScriptArray<ScriptString*>, SeekFreePCExtensions, 216)
		ADD_STRUCT(ScriptArray<ScriptString*>, SeekFreePCPaths, 144)
	};
}
#undef ADD_STRUCT
