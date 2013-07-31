#pragma once
#include "Engine.UIDataStore_StringBase.h"
#include "Engine.UIRoot.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_InputAlias : public UIDataStore_StringBase
	{
	public:
		struct UIInputKeyData
		{
		public:
			ADD_STRUCT(ScriptString*, ButtonFontMarkupString, 12)
			ADD_STRUCT(UIRoot::RawInputKeyEventData, InputKeyData, 0)
		};
		struct UIDataStoreInputAlias
		{
		public:
			ADD_STRUCT(UIDataStore_InputAlias::UIInputKeyData, PlatformInputKeys, 8)
			ADD_STRUCT(ScriptName, AliasName, 0)
		};
		ADD_STRUCT(ScriptArray<UIDataStore_InputAlias::UIDataStoreInputAlias>, InputAliases, 120)
		ScriptString* GetAliasFontMarkup(ScriptName DesiredAlias, UIRoot::EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28570);
			byte params[21] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			*(UIRoot::EInputPlatformType*)&params[8] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* GetAliasFontMarkupByIndex(int AliasIndex, UIRoot::EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28574);
			byte params[17] = { NULL };
			*(int*)params = AliasIndex;
			*(UIRoot::EInputPlatformType*)&params[4] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		ScriptName GetAliasInputKeyName(ScriptName DesiredAlias, UIRoot::EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28578);
			byte params[17] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			*(UIRoot::EInputPlatformType*)&params[8] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[12];
		}
		ScriptName GetAliasInputKeyNameByIndex(int AliasIndex, UIRoot::EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28582);
			byte params[13] = { NULL };
			*(int*)params = AliasIndex;
			*(UIRoot::EInputPlatformType*)&params[4] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		bool GetAliasInputKeyData(UIRoot::RawInputKeyEventData& out_InputKeyData, ScriptName DesiredAlias, UIRoot::EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28586);
			byte params[25] = { NULL };
			*(UIRoot::RawInputKeyEventData*)params = out_InputKeyData;
			*(ScriptName*)&params[12] = DesiredAlias;
			*(UIRoot::EInputPlatformType*)&params[20] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_InputKeyData = *(UIRoot::RawInputKeyEventData*)params;
			return *(bool*)&params[24];
		}
		bool GetAliasInputKeyDataByIndex(UIRoot::RawInputKeyEventData& out_InputKeyData, int AliasIndex, UIRoot::EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28591);
			byte params[21] = { NULL };
			*(UIRoot::RawInputKeyEventData*)params = out_InputKeyData;
			*(int*)&params[12] = AliasIndex;
			*(UIRoot::EInputPlatformType*)&params[16] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_InputKeyData = *(UIRoot::RawInputKeyEventData*)params;
			return *(bool*)&params[20];
		}
		int FindInputAliasIndex(ScriptName DesiredAlias)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28596);
			byte params[12] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool HasAliasMappingForPlatform(ScriptName DesiredAlias, UIRoot::EInputPlatformType DesiredPlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28599);
			byte params[13] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			*(UIRoot::EInputPlatformType*)&params[8] = DesiredPlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_STRUCT
