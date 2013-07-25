#pragma once
#include "Engine__Engine.h"
#include "Engine__OnlineSubsystem.h"
#include "Engine__PendingLevel.h"
#include "Engine__DownloadableContentEnumerator.h"
#include "Engine__DownloadableContentManager.h"
#include "Engine__InGameAdManager.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameEngine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GameEngine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameEngine." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameEngine : public Engine
	{
	public:
		ADD_OBJECT(PendingLevel, GPendingLevel)
		ADD_VAR(::StrProperty, PendingLevelPlayerControllerClassName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameEngine.URL' for the property named 'LastURL'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameEngine.URL' for the property named 'LastRemoteURL'!
		ADD_VAR(::StrProperty, TravelURL, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TravelType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWorldWasLoadedThisTick, 0x1)
		ADD_VAR(::BoolProperty, bShouldCommitPendingMapChange, 0x2)
		ADD_VAR(::BoolProperty, bClearAnimSetLinkupCachesOnLoadMap, 0x4)
		ADD_OBJECT(OnlineSubsystem, OnlineSubsystem)
		ADD_OBJECT(DownloadableContentEnumerator, DLCEnumerator)
		ADD_VAR(::StrProperty, DownloadableContentEnumeratorClassName, 0xFFFFFFFF)
		ADD_OBJECT(DownloadableContentManager, DLCManager)
		ADD_VAR(::StrProperty, DownloadableContentManagerClassName, 0xFFFFFFFF)
		ADD_OBJECT(InGameAdManager, AdManager)
		ADD_VAR(::StrProperty, InGameAdManagerClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PendingMapChangeFailureDescription, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDeltaTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetOnlineSubsystem'
		// Here lies the not-yet-implemented method 'GetDLCManager'
		// Here lies the not-yet-implemented method 'GetDLCEnumerator'
		// Here lies the not-yet-implemented method 'CreateNamedNetDriver'
		// Here lies the not-yet-implemented method 'DestroyNamedNetDriver'
		// Here lies the not-yet-implemented method 'GetAdManager'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
