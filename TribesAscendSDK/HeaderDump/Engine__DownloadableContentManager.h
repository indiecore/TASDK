#pragma once
#include "Core__Object.h"
#include "Engine__GameEngine.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DownloadableContentManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DownloadableContentManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DownloadableContentManager : public Object
	{
	public:
		ADD_OBJECT(GameEngine, GameEngine)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'TextureCachePathMap'!
		// Here lies the not-yet-implemented method 'InstallDLC'
		// Here lies the not-yet-implemented method 'InstallDLCs'
		// Here lies the not-yet-implemented method 'ClearDLC'
		// Here lies the not-yet-implemented method 'GetDLCTextureCachePath'
		// Here lies the not-yet-implemented method 'AddSectionToObjectList'
		// Here lies the not-yet-implemented method 'MarkPerObjectConfigPendingKill'
		// Here lies the not-yet-implemented method 'UpdateObjectLists'
		// Here lies the not-yet-implemented method 'InstallPackages'
		// Here lies the not-yet-implemented method 'InstallNonPackageFiles'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'OnLoginChange'
		// Here lies the not-yet-implemented method 'OnStorageDeviceChange'
		// Here lies the not-yet-implemented method 'OnContentChange'
		// Here lies the not-yet-implemented method 'RefreshDLC'
		// Here lies the not-yet-implemented method 'RefreshDLCEnumComplete'
		// Here lies the not-yet-implemented method 'AddPackagesToFullyLoad'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
