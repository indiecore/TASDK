#pragma once
#include "Engine.UIDataStore_GameResource.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_MenuItems." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_MenuItems : public UIDataStore_GameResource
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'OptionProviders'!
		ADD_VAR(::NameProperty, CurrentGameSettingsTag, 0xFFFFFFFF)
		void ClearSet(ScriptName SetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.ClearSet");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SetName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AppendToSet(ScriptName SetName, int NumOptions)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.AppendToSet");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SetName;
			*(int*)(params + 8) = NumOptions;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSet(ScriptName SetName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutProviders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.GetSet");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SetName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = OutProviders;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutProviders = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
		}
		void OnGameSettingsChanged(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.OnGameSettingsChanged");
			byte* params = (byte*)malloc(12);
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)(params + 4) = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.Registered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.Unregistered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
