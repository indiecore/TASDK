#pragma once
#include "Core.Object.h"
#include "TribesGame.TrStreamManager.GameStream.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStreamManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrStreamManager : public Object
	{
	public:
		ADD_VAR(::StrProperty, StreamServer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StreamPath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StreamURL, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WatchEnd, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WatchStart, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TokViewers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TokTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TokName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NewsIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUpdateReady, 0x1)
		ScriptArray<wchar_t> GetTitleAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetTitleAtIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsLiveAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.IsLiveAtIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetViewersAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetViewersAtIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetDescriptionAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetDescriptionAtIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HaveFeature()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.HaveFeature");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetFeatureName(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetFeatureName");
			byte* params = (byte*)malloc(16);
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsStream(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.IsStream");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetTypeCountWatching(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetTypeCountWatching");
			byte* params = (byte*)malloc(5);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetTypeCount(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetTypeCount");
			byte* params = (byte*)malloc(5);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetFeatureDescription(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetFeatureDescription");
			byte* params = (byte*)malloc(16);
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		int ViewerSort(GameStream A, GameStream B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.ViewerSort");
			byte* params = (byte*)malloc(140);
			*(GameStream*)params = A;
			*(GameStream*)(params + 68) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 136);
			free(params);
			return returnVal;
		}
		void LoadStreams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.LoadStreams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetStreamData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetStreamData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenStream(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.OpenStream");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewStreamIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.ViewStreamIndex");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewVideoIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.ViewVideoIndex");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartTVTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.StartTVTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateStreams(bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.UpdateStreams");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckForUpdate(bool bRunIfReady)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.CheckForUpdate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bRunIfReady;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetLatestNews()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetLatestNews");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.CompleteUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
