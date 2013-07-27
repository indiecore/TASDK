#pragma once
#include "Engine.UIDataStore.h"
#include "Core.Object.h"
#include "Engine.UIResourceCombinationProvider.h"
#include "Engine.UIDataStore_GameResource.h"
#include "Engine.UIDataProvider_OnlineProfileSettings.h"
#include "Engine.UIRoot.h"
#include "Engine.LocalPlayer.h"
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
	class UIDataStore_DynamicResource : public UIDataStore
	{
	public:
		class DynamicResourceProviderDefinition
		{
		public:
			ADD_OBJECT(ScriptClass, ProviderClass, 20)
			ADD_STRUCT(ScriptString*, ProviderClassName, 8)
			ADD_STRUCT(ScriptName, ProviderTag, 0)
		};
		ADD_STRUCT(ScriptArray<UIDataStore_DynamicResource::DynamicResourceProviderDefinition>, ResourceProviderDefinitions, 132)
		ADD_STRUCT(Object::MultiMap_Mirror, ResourceProviders, 144)
		ADD_OBJECT(UIDataStore_GameResource, GameResourceDataStore, 128)
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider, 124)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 120)
		int FindProviderTypeIndex(ScriptName ProviderTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.FindProviderTypeIndex");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptName GenerateProviderAccessTag(int ProviderIndex, int InstanceIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GenerateProviderAccessTag");
			byte params[16] = { NULL };
			*(int*)&params[0] = ProviderIndex;
			*(int*)&params[4] = InstanceIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		int GetProviderCount(ScriptName ProviderTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetProviderCount");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool GetResourceProviders(ScriptName ProviderTag, ScriptArray<class UIResourceCombinationProvider*>& out_Providers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetResourceProviders");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(ScriptArray<class UIResourceCombinationProvider*>*)&params[8] = out_Providers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Providers = *(ScriptArray<class UIResourceCombinationProvider*>*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetResourceProviderFields(ScriptName ProviderTag, ScriptArray<ScriptName>& ProviderFieldTags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetResourceProviderFields");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(ScriptArray<ScriptName>*)&params[8] = ProviderFieldTags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ProviderFieldTags = *(ScriptArray<ScriptName>*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetProviderFieldValue(ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, UIRoot::UIProviderScriptFieldValue& out_FieldValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetProviderFieldValue");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.FindProviderIndexByFieldValue");
			byte params[104] = { NULL };
			*(ScriptName*)&params[0] = ProviderTag;
			*(ScriptName*)&params[8] = SearchField;
			*(UIRoot::UIProviderScriptFieldValue*)&params[16] = ValueToSearchFor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueToSearchFor = *(UIRoot::UIProviderScriptFieldValue*)&params[16];
			return *(int*)&params[100];
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.OnLoginChange");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.Registered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.Unregistered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
