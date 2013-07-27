#pragma once
#include "Core.Object.h"
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
namespace UnrealScript
{
	class TrStreamManager : public Object
	{
	public:
		enum STREAMTYPE : byte
		{
			VST_NONE = 0,
			VST_HIREZ = 1,
			VST_TWITCH = 2,
			VST_TRAINING = 3,
			VST_COMMUNITY = 4,
			VST_NEWS = 5,
			VST_MAX = 6,
		};
		class GameStream
		{
		public:
			ADD_STRUCT(TrStreamManager::STREAMTYPE, Type, 4)
			ADD_BOOL(bFeatured, 0, 0x2)
			ADD_STRUCT(ScriptString*, Title, 8)
			ADD_BOOL(bLive, 0, 0x1)
			ADD_STRUCT(ScriptString*, Viewers, 32)
			ADD_STRUCT(ScriptString*, Description, 56)
			ADD_STRUCT(ScriptString*, ChannelName, 44)
			ADD_STRUCT(ScriptString*, Stream, 20)
		};
		ADD_STRUCT(ScriptArray<TrStreamManager::GameStream>, Streams, 164)
		ADD_STRUCT(ScriptString*, StreamServer, 152)
		ADD_STRUCT(ScriptString*, StreamPath, 140)
		ADD_STRUCT(ScriptString*, StreamURL, 128)
		ADD_STRUCT(ScriptString*, WatchEnd, 116)
		ADD_STRUCT(ScriptString*, WatchStart, 104)
		ADD_STRUCT(ScriptString*, TokViewers, 92)
		ADD_STRUCT(ScriptString*, TokTitle, 80)
		ADD_STRUCT(ScriptString*, TokName, 68)
		ADD_STRUCT(int, NewsIndex, 64)
		ADD_BOOL(bUpdateReady, 60, 0x1)
		ScriptString* GetTitleAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetTitleAtIndex");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool IsLiveAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.IsLiveAtIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetViewersAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetViewersAtIndex");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetDescriptionAtIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetDescriptionAtIndex");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool HaveFeature()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.HaveFeature");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		ScriptString* GetFeatureName(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetFeatureName");
			byte params[16] = { NULL };
			*(int*)&params[0] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool IsStream(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.IsStream");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetTypeCountWatching(TrStreamManager::STREAMTYPE Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetTypeCountWatching");
			byte params[5] = { NULL };
			*(TrStreamManager::STREAMTYPE*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetTypeCount(TrStreamManager::STREAMTYPE Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetTypeCount");
			byte params[5] = { NULL };
			*(TrStreamManager::STREAMTYPE*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		ScriptString* GetFeatureDescription(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.GetFeatureDescription");
			byte params[16] = { NULL };
			*(int*)&params[0] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int ViewerSort(TrStreamManager::GameStream A, TrStreamManager::GameStream B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.ViewerSort");
			byte params[140] = { NULL };
			*(TrStreamManager::GameStream*)&params[0] = A;
			*(TrStreamManager::GameStream*)&params[68] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[136];
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
		void OpenStream(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.OpenStream");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewStreamIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.ViewStreamIndex");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewVideoIndex(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.ViewVideoIndex");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartTVTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.StartTVTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateStreams(bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.UpdateStreams");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckForUpdate(bool bRunIfReady)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStreamManager.CheckForUpdate");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bRunIfReady;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
#undef ADD_BOOL
#undef ADD_STRUCT
