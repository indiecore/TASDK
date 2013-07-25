#pragma once
#include "Core__Object.h"
#include "Engine__LocalPlayer.h"
#include "Engine__GameUISceneClient.h"
#include "Engine__UIInteraction.h"
#include "Engine__UIDataStore.h"
namespace UnrealScript
{
	class UIRoot : public Object
	{
	public:
		bool GetDataStoreStringValue(ScriptArray<wchar_t> InDataStoreMarkup, ScriptArray<wchar_t>& OutStringValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetDataStoreStringValue");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = InDataStoreMarkup;
			*(ScriptArray<wchar_t>*)(params + 12) = OutStringValue;
			*(class LocalPlayer**)(params + 24) = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutStringValue = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool SetDataStoreStringValue(ScriptArray<wchar_t> InDataStoreMarkup, ScriptArray<wchar_t> InStringValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.SetDataStoreStringValue");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = InDataStoreMarkup;
			*(ScriptArray<wchar_t>*)(params + 12) = InStringValue;
			*(class LocalPlayer**)(params + 24) = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		byte GetInputPlatformType(class LocalPlayer* OwningPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetInputPlatformType");
			byte* params = (byte*)malloc(5);
			*(class LocalPlayer**)params = OwningPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		class UIInteraction* GetCurrentUIController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetCurrentUIController");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIInteraction**)params;
			free(params);
			return returnVal;
		}
		class GameUISceneClient* GetSceneClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetSceneClient");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameUISceneClient**)params;
			free(params);
			return returnVal;
		}
		class UIDataStore* StaticResolveDataStore(ScriptName DataStoreTag, class LocalPlayer* InPlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.StaticResolveDataStore");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = DataStoreTag;
			*(class LocalPlayer**)(params + 8) = InPlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIDataStore**)(params + 12);
			free(params);
			return returnVal;
		}
		bool SetDataStoreFieldValue(ScriptArray<wchar_t> InDataStoreMarkup, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void*& InFieldValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.SetDataStoreFieldValue");
			byte* params = (byte*)malloc(108);
			*(ScriptArray<wchar_t>*)params = InDataStoreMarkup;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void**)(params + 12) = InFieldValue;
			*(class LocalPlayer**)(params + 100) = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InFieldValue = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 104);
			free(params);
			return returnVal;
		}
		bool GetDataStoreFieldValue(ScriptArray<wchar_t> InDataStoreMarkup, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void*& OutFieldValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetDataStoreFieldValue");
			byte* params = (byte*)malloc(108);
			*(ScriptArray<wchar_t>*)params = InDataStoreMarkup;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void**)(params + 12) = OutFieldValue;
			*(class LocalPlayer**)(params + 100) = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutFieldValue = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderFieldValue'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 104);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlineGameInterface()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetOnlineGameInterface");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlinePlayerInterface()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetOnlinePlayerInterface");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlinePlayerInterfaceEx()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIRoot.GetOnlinePlayerInterfaceEx");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params;
			free(params);
			return returnVal;
		}
	};
}
