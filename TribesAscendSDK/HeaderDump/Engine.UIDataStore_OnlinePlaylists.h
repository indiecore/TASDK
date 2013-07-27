#pragma once
#include "Engine.UIDataStore.h"
#include "Engine.UIResourceDataProvider.h"
#include "Core.Object.h"
#include "Engine.UIRoot.h"
#include "Engine.OnlinePlaylistProvider.h"
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
	class UIDataStore_OnlinePlaylists : public UIDataStore
	{
	public:
		static const const char* RANKEDPROVIDERTAG;
		static const const char* UNRANKEDPROVIDERTAG;
		ADD_STRUCT(ScriptArray<class UIResourceDataProvider*>, RankedDataProviders, 140)
		ADD_STRUCT(ScriptArray<class UIResourceDataProvider*>, UnRankedDataProviders, 152)
		ADD_OBJECT(ScriptClass, ProviderClass, 136)
		ADD_STRUCT(ScriptString*, ProviderClassName, 124)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 120)
		int GetProviderCount(ScriptName ProviderTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetProviderCount");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool GetResourceProviders(ScriptName ProviderTag, ScriptArray<class UIResourceDataProvider*>& out_Providers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetResourceProviders");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(ScriptArray<class UIResourceDataProvider*>*)&params[8] = out_Providers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Providers = *(ScriptArray<class UIResourceDataProvider*>*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetResourceProviderFields(ScriptName ProviderTag, ScriptArray<ScriptName>& ProviderFieldTags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetResourceProviderFields");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(ScriptArray<ScriptName>*)&params[8] = ProviderFieldTags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ProviderFieldTags = *(ScriptArray<ScriptName>*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetProviderFieldValue(ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, UIRoot::UIProviderScriptFieldValue& out_FieldValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetProviderFieldValue");
			byte params[108] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(ScriptName*)&params[8] = SearchField;
			*(int*)&params[16] = ProviderIndex;
			*(UIRoot::UIProviderScriptFieldValue*)&params[20] = out_FieldValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_FieldValue = *(UIRoot::UIProviderScriptFieldValue*)&params[20];
			return *(bool*)&params[104];
		}
		int FindProviderIndexByFieldValue(ScriptName ProviderTag, ScriptName SearchField, UIRoot::UIProviderScriptFieldValue& ValueToSearchFor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.FindProviderIndexByFieldValue");
			byte params[104] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(ScriptName*)&params[8] = SearchField;
			*(UIRoot::UIProviderScriptFieldValue*)&params[16] = ValueToSearchFor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueToSearchFor = *(UIRoot::UIProviderScriptFieldValue*)&params[16];
			return *(int*)&params[100];
		}
		bool GetPlaylistProvider(ScriptName ProviderTag, int ProviderIndex, class UIResourceDataProvider*& out_Provider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetPlaylistProvider");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(int*)&params[8] = ProviderIndex;
			*(class UIResourceDataProvider**)&params[12] = out_Provider;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Provider = *(class UIResourceDataProvider**)&params[12];
			return *(bool*)&params[16];
		}
		class OnlinePlaylistProvider* GetOnlinePlaylistProvider(ScriptName ProviderTag, int PlaylistId, int& ProviderIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetOnlinePlaylistProvider");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(int*)&params[8] = PlaylistId;
			*(int*)&params[12] = ProviderIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ProviderIndex = *(int*)&params[12];
			return *(class OnlinePlaylistProvider**)&params[16];
		}
	};
	const const char* UIDataStore_OnlinePlaylists::RANKEDPROVIDERTAG = "PlaylistsRanked";
	const const char* UIDataStore_OnlinePlaylists::UNRANKEDPROVIDERTAG = "PlaylistsUnranked";
}
#undef ADD_STRUCT
#undef ADD_OBJECT
