#pragma once
#include "Engine.GameEngine.h"
#include "Core.Object.h"
#include "Core.Object.Map_Mirror.h"
#include "Engine.OnlineSubsystem.OnlineContent.h"
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
		ADD_STRUCT(::NonArithmeticProperty<Map_Mirror>, TextureCachePathMap, 0xFFFFFFFF)
		bool InstallDLC(OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallDLC");
			byte* params = (byte*)malloc(72);
			*(OnlineContent*)params = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DLCBundle = *(OnlineContent*)params;
			auto returnVal = *(bool*)(params + 68);
			free(params);
			return returnVal;
		}
		void InstallDLCs(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& DLCBundles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallDLCs");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = DLCBundles;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DLCBundles = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void ClearDLC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.ClearDLC");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetDLCTextureCachePath(ScriptName TextureCacheName, ScriptArray<wchar_t>& Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.GetDLCTextureCachePath");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = TextureCacheName;
			*(ScriptArray<wchar_t>*)(params + 8) = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Path = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void AddSectionToObjectList(ScriptArray<wchar_t> Section)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.AddSectionToObjectList");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Section;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MarkPerObjectConfigPendingKill(ScriptArray<wchar_t> Section)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.MarkPerObjectConfigPendingKill");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Section;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateObjectLists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.UpdateObjectLists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstallPackages(OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallPackages");
			byte* params = (byte*)malloc(68);
			*(OnlineContent*)params = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DLCBundle = *(OnlineContent*)params;
			free(params);
		}
		void InstallNonPackageFiles(OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.InstallNonPackageFiles");
			byte* params = (byte*)malloc(68);
			*(OnlineContent*)params = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DLCBundle = *(OnlineContent*)params;
			free(params);
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void AddPackagesToFullyLoad(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DownloadableContentManager.AddPackagesToFullyLoad");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
