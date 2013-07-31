#pragma once
#include "Engine.UIDataStore_StringAliasMap.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasBindingMap : public UIDataStore_StringAliasMap
	{
	public:
		static const auto SABM_FIND_FIRST_BIND = -2;
		struct ControllerMap
		{
		public:
			ADD_STRUCT(ScriptString*, PS3Mapping, 20)
			ADD_STRUCT(ScriptString*, XBoxMapping, 8)
			ADD_STRUCT(ScriptName, KeyName, 0)
		};
		struct BindCacheElement
		{
		public:
			ADD_STRUCT(int, FieldIndex, 20)
			ADD_STRUCT(ScriptString*, MappingString, 8)
			ADD_STRUCT(ScriptName, KeyName, 0)
		};
		ADD_STRUCT(ScriptArray<UDKUIDataStore_StringAliasBindingMap::ControllerMap>, ControllerMapArray, 260)
		ADD_STRUCT(Object::Map_Mirror, CommandToBindNames, 200)
		ADD_STRUCT(int, FakePlatform, 196)
		int GetStringWithFieldName(ScriptString* FieldName, ScriptString*& MappedString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35667);
			byte params[28] = { NULL };
			*(ScriptString**)params = FieldName;
			*(ScriptString**)&params[12] = MappedString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MappedString = *(ScriptString**)&params[12];
			return *(int*)&params[24];
		}
		int GetBoundStringWithFieldName(ScriptString* FieldName, ScriptString*& MappedString, int& StartIndex, ScriptString*& BindString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35671);
			byte params[44] = { NULL };
			*(ScriptString**)params = FieldName;
			*(ScriptString**)&params[12] = MappedString;
			*(int*)&params[24] = StartIndex;
			*(ScriptString**)&params[28] = BindString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MappedString = *(ScriptString**)&params[12];
			StartIndex = *(int*)&params[24];
			BindString = *(ScriptString**)&params[28];
			return *(int*)&params[40];
		}
		bool FindMappingInBoundKeyCache(ScriptString* Command, ScriptString*& MappingStr, int& FieldIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35677);
			byte params[32] = { NULL };
			*(ScriptString**)params = Command;
			*(ScriptString**)&params[12] = MappingStr;
			*(int*)&params[24] = FieldIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MappingStr = *(ScriptString**)&params[12];
			FieldIndex = *(int*)&params[24];
			return *(bool*)&params[28];
		}
		void AddMappingToBoundKeyCache(ScriptString* Command, ScriptString* MappingStr, int FieldIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35682);
			byte params[28] = { NULL };
			*(ScriptString**)params = Command;
			*(ScriptString**)&params[12] = MappingStr;
			*(int*)&params[24] = FieldIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearBoundKeyCache()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35686);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
