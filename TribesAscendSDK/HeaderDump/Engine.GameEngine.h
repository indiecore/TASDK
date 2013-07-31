#pragma once
#include "Engine.ObjectReferencer.h"
#include "Engine.DownloadableContentEnumerator.h"
#include "Engine.Engine.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.PendingLevel.h"
#include "Engine.Level.h"
#include "Engine.DownloadableContentManager.h"
#include "Engine.InGameAdManager.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameEngine : public Engine
	{
	public:
		enum EFullyLoadPackageType : byte
		{
			FULLYLOAD_Map = 0,
			FULLYLOAD_Game_PreLoadClass = 1,
			FULLYLOAD_Game_PostLoadClass = 2,
			FULLYLOAD_Always = 3,
			FULLYLOAD_Mutator = 4,
			FULLYLOAD_MAX = 5,
		};
		struct LevelStreamingStatus
		{
		public:
			ADD_STRUCT(ScriptName, PackageName, 0)
			ADD_BOOL(bShouldBeLoaded, 8, 0x1)
			ADD_BOOL(bShouldBeVisible, 8, 0x2)
		};
		struct NamedNetDriver
		{
		public:
			ADD_STRUCT(Object::Pointer, NetDriver, 8)
			ADD_STRUCT(ScriptName, NetDriverName, 0)
		};
		struct URL
		{
		public:
			ADD_STRUCT(ScriptString*, Protocol, 0)
			ADD_STRUCT(ScriptString*, Host, 12)
			ADD_STRUCT(int, Port, 24)
			ADD_STRUCT(ScriptString*, Map, 28)
			ADD_STRUCT(ScriptArray<ScriptString*>, Op, 40)
			ADD_STRUCT(ScriptString*, Portal, 52)
			ADD_STRUCT(int, Valid, 64)
		};
		struct FullyLoadedPackagesInfo
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptName>, PackagesToLoad, 16)
			ADD_STRUCT(ScriptArray<class Object*>, LoadedObjects, 28)
			ADD_STRUCT(ScriptString*, Tag, 4)
			ADD_STRUCT(GameEngine::EFullyLoadPackageType, FullyLoadType, 0)
		};
		ADD_OBJECT(PendingLevel, GPendingLevel, 1484)
		ADD_STRUCT(ScriptString*, PendingLevelPlayerControllerClassName, 1488)
		ADD_STRUCT(GameEngine::URL, LastURL, 1500)
		ADD_STRUCT(GameEngine::URL, LastRemoteURL, 1568)
		ADD_STRUCT(ScriptArray<ScriptString*>, ServerActors, 1636)
		ADD_STRUCT(ScriptString*, TravelURL, 1648)
		ADD_STRUCT(byte, TravelType, 1660)
		ADD_BOOL(bWorldWasLoadedThisTick, 1664, 0x1)
		ADD_BOOL(bShouldCommitPendingMapChange, 1664, 0x2)
		ADD_BOOL(bClearAnimSetLinkupCachesOnLoadMap, 1664, 0x4)
		ADD_OBJECT(OnlineSubsystem, OnlineSubsystem, 1668)
		ADD_OBJECT(DownloadableContentEnumerator, DLCEnumerator, 1672)
		ADD_STRUCT(ScriptString*, DownloadableContentEnumeratorClassName, 1676)
		ADD_OBJECT(DownloadableContentManager, DLCManager, 1688)
		ADD_STRUCT(ScriptString*, DownloadableContentManagerClassName, 1692)
		ADD_OBJECT(InGameAdManager, AdManager, 1704)
		ADD_STRUCT(ScriptString*, InGameAdManagerClassName, 1708)
		ADD_STRUCT(ScriptArray<ScriptName>, LevelsToLoadForPendingMapChange, 1720)
		ADD_STRUCT(ScriptArray<class Level*>, LoadedLevelsForPendingMapChange, 1732)
		ADD_STRUCT(ScriptString*, PendingMapChangeFailureDescription, 1744)
		ADD_STRUCT(float, MaxDeltaTime, 1756)
		ADD_STRUCT(ScriptArray<GameEngine::LevelStreamingStatus>, PendingLevelStreamingStatusUpdates, 1760)
		ADD_STRUCT(ScriptArray<class ObjectReferencer*>, ObjectReferencers, 1772)
		ADD_STRUCT(ScriptArray<GameEngine::FullyLoadedPackagesInfo>, PackagesToFullyLoad, 1784)
		ADD_STRUCT(ScriptArray<GameEngine::NamedNetDriver>, NamedNetDrivers, 1796)
		class OnlineSubsystem* GetOnlineSubsystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7627);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineSubsystem**)params;
		}
		class DownloadableContentManager* GetDLCManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14696);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class DownloadableContentManager**)params;
		}
		class DownloadableContentEnumerator* GetDLCEnumerator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14739);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class DownloadableContentEnumerator**)params;
		}
		bool CreateNamedNetDriver(ScriptName NetDriverName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16684);
			byte params[12] = { NULL };
			*(ScriptName*)params = NetDriverName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DestroyNamedNetDriver(ScriptName NetDriverName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16687);
			byte params[8] = { NULL };
			*(ScriptName*)params = NetDriverName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class InGameAdManager* GetAdManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16689);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class InGameAdManager**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
