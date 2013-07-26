#pragma once
#include "Core.Object.MultiMap_Mirror.h"
#include "Engine.UIDataStore.h"
#include "Engine.UIDataStore_GameResource.h"
#include "Core.Object.Pointer.h"
#include "Engine.UIDataProvider_OnlineProfileSettings.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIRoot.UIProviderScriptFieldValue.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_DynamicResource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_DynamicResource." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_DynamicResource : public UIDataStore
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<MultiMap_Mirror>, ResourceProviders, 0xFFFFFFFF)
		ADD_OBJECT(UIDataStore_GameResource, GameResourceDataStore)
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementProvider, 0xFFFFFFFF)
		int FindProviderTypeIndex(ScriptName ProviderTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.FindProviderTypeIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName GenerateProviderAccessTag(int ProviderIndex, int InstanceIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GenerateProviderAccessTag");
			byte* params = (byte*)malloc(16);
			*(int*)params = ProviderIndex;
			*(int*)(params + 4) = InstanceIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetProviderCount(ScriptName ProviderTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetProviderCount");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetResourceProviders(ScriptName ProviderTag, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Providers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetResourceProviders");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ProviderTag;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = out_Providers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Providers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetResourceProviderFields(ScriptName ProviderTag, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ProviderFieldTags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetResourceProviderFields");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ProviderTag;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = ProviderFieldTags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ProviderFieldTags = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetProviderFieldValue(ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, UIProviderScriptFieldValue& out_FieldValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.GetProviderFieldValue");
			byte* params = (byte*)malloc(108);
			*(ScriptName*)params = ProviderTag;
			*(ScriptName*)(params + 8) = SearchField;
			*(int*)(params + 16) = ProviderIndex;
			*(UIProviderScriptFieldValue*)(params + 20) = out_FieldValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_FieldValue = *(UIProviderScriptFieldValue*)(params + 20);
			auto returnVal = *(bool*)(params + 104);
			free(params);
			return returnVal;
		}
		int FindProviderIndexByFieldValue(ScriptName ProviderTag, ScriptName SearchField, UIProviderScriptFieldValue& ValueToSearchFor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.FindProviderIndexByFieldValue");
			byte* params = (byte*)malloc(104);
			*(ScriptName*)params = ProviderTag;
			*(ScriptName*)(params + 8) = SearchField;
			*(UIProviderScriptFieldValue*)(params + 16) = ValueToSearchFor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueToSearchFor = *(UIProviderScriptFieldValue*)(params + 16);
			auto returnVal = *(int*)(params + 100);
			free(params);
			return returnVal;
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.Registered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_DynamicResource.Unregistered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
