#pragma once
#include "Engine.UIDataStore_GameResource.h"
#include "Engine.UIDataProvider_MenuItem.h"
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_MenuItems : public UIDataStore_GameResource
	{
	public:
		ADD_STRUCT(ScriptArray<class UIDataProvider_MenuItem*>, DynamicProviders, 264)
		ADD_STRUCT(Object::MultiMap_Mirror, OptionProviders, 204)
		ADD_STRUCT(ScriptName, CurrentGameSettingsTag, 196)
		void ClearSet(ScriptName SetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.ClearSet");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = SetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AppendToSet(ScriptName SetName, int NumOptions)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.AppendToSet");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SetName;
			*(int*)&params[8] = NumOptions;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSet(ScriptName SetName, ScriptArray<class UIDataProvider_MenuItem*>& OutProviders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.GetSet");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SetName;
			*(ScriptArray<class UIDataProvider_MenuItem*>*)&params[8] = OutProviders;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutProviders = *(ScriptArray<class UIDataProvider_MenuItem*>*)&params[8];
		}
		void OnGameSettingsChanged(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.OnGameSettingsChanged");
			byte params[12] = { NULL };
			*(class UIDataProvider**)&params[0] = SourceProvider;
			*(ScriptName*)&params[4] = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.Registered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_MenuItems.Unregistered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
