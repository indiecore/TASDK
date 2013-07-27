#pragma once
#include "Engine.UIDataStore_StringAliasMap.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_StringAliasMap : public UIDataStore_StringAliasMap
	{
	public:
		ADD_STRUCT(int, FakePlatform, 196)
		int GetStringWithFieldName(ScriptString* FieldName, ScriptString*& MappedString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35688);
			byte params[28] = { NULL };
			*(ScriptString**)params = FieldName;
			*(ScriptString**)&params[12] = MappedString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MappedString = *(ScriptString**)&params[12];
			return *(int*)&params[24];
		}
	};
}
#undef ADD_STRUCT
