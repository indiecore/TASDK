#pragma once
#include "Core.Object.h"
#include "Engine.Settings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineStats : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<Settings::StringIdToStringMapping>, ViewIdMappings, 60)
		bool GetViewId(ScriptName ViewName, int& ViewId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22749);
			byte params[16] = { NULL };
			*(ScriptName*)params = ViewName;
			*(int*)&params[8] = ViewId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ViewId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		ScriptName GetViewName(int ViewId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22753);
			byte params[12] = { NULL };
			*(int*)params = ViewId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
	};
}
#undef ADD_STRUCT
