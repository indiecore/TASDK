#pragma once
#include "Engine.GameEngine.h"
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
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
	class DownloadableContentManager : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<Object::Pointer>, DLCConfigCacheChanges, 60)
		ADD_STRUCT(ScriptArray<ScriptString*>, InstalledDLC, 72)
		ADD_STRUCT(ScriptArray<ScriptClass*>, ClassesToReload, 144)
		ADD_STRUCT(ScriptArray<class Object*>, ObjectsToReload, 156)
		ADD_OBJECT(GameEngine, GameEngine, 168)
		ADD_STRUCT(Object::Map_Mirror, TextureCachePathMap, 84)
		bool InstallDLC(OnlineSubsystem::OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallDLC");
			byte params[72] = { NULL };
			*(OnlineSubsystem::OnlineContent*)&params[0] = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundle = *(OnlineSubsystem::OnlineContent*)&params[0];
			return *(bool*)&params[68];
		}
		void InstallDLCs(ScriptArray<OnlineSubsystem::OnlineContent>& DLCBundles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallDLCs");
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem::OnlineContent>*)&params[0] = DLCBundles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundles = *(ScriptArray<OnlineSubsystem::OnlineContent>*)&params[0];
		}
		void ClearDLC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.ClearDLC");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetDLCTextureCachePath(ScriptName TextureCacheName, ScriptString*& Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.GetDLCTextureCachePath");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = TextureCacheName;
			*(ScriptString**)&params[8] = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Path = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		void AddSectionToObjectList(ScriptString* Section)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.AddSectionToObjectList");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Section;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MarkPerObjectConfigPendingKill(ScriptString* Section)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.MarkPerObjectConfigPendingKill");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Section;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateObjectLists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.UpdateObjectLists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstallPackages(OnlineSubsystem::OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallPackages");
			byte params[68] = { NULL };
			*(OnlineSubsystem::OnlineContent*)&params[0] = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundle = *(OnlineSubsystem::OnlineContent*)&params[0];
		}
		void InstallNonPackageFiles(OnlineSubsystem::OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallNonPackageFiles");
			byte params[68] = { NULL };
			*(OnlineSubsystem::OnlineContent*)&params[0] = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundle = *(OnlineSubsystem::OnlineContent*)&params[0];
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.OnLoginChange");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStorageDeviceChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.OnStorageDeviceChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnContentChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.OnContentChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshDLC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.RefreshDLC");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshDLCEnumComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.RefreshDLCEnumComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPackagesToFullyLoad(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.AddPackagesToFullyLoad");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
