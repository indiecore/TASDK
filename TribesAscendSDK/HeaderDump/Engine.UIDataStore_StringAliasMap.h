#pragma once
#include "Engine.UIDataStore_StringBase.h"
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_StringAliasMap : public UIDataStore_StringBase
	{
	public:
		class UIMenuInputMap
		{
		public:
			ADD_STRUCT(ScriptString*, MappedText, 16)
			ADD_STRUCT(ScriptName, Set, 8)
			ADD_STRUCT(ScriptName, FieldName, 0)
		};
		ADD_STRUCT(ScriptArray<UIDataStore_StringAliasMap::UIMenuInputMap>, MenuInputMapArray, 120)
		ADD_STRUCT(int, PlayerIndex, 192)
		ADD_STRUCT(Object::Map_Mirror, MenuInputSets, 132)
		class LocalPlayer* GetPlayerOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_StringAliasMap.GetPlayerOwner");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)&params[0];
		}
		int FindMappingWithFieldName(ScriptString* FieldName, ScriptString* SetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_StringAliasMap.FindMappingWithFieldName");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = FieldName;
			*(ScriptString**)&params[12] = SetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[24];
		}
		int GetStringWithFieldName(ScriptString* FieldName, ScriptString*& MappedString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_StringAliasMap.GetStringWithFieldName");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = FieldName;
			*(ScriptString**)&params[12] = MappedString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MappedString = *(ScriptString**)&params[12];
			return *(int*)&params[24];
		}
	};
}
#undef ADD_STRUCT
