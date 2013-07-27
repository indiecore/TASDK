#pragma once
#include "Core.Object.h"
#include "Engine.GameplayEventsWriter.h"
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
	class GenericParamListStatEntry : public Object
	{
	public:
		ADD_OBJECT(GameplayEventsWriter, Writer, 64)
		ADD_STRUCT(Object::Pointer, StatEvent, 60)
		void AddFloat(ScriptName ParamName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18131);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParamName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddInt(ScriptName ParamName, int Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18134);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParamName;
			*(int*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVector(ScriptName ParamName, Vector Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18137);
			byte params[20] = { NULL };
			*(ScriptName*)params = ParamName;
			*(Vector*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddString(ScriptName ParamName, ScriptString* Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18140);
			byte params[20] = { NULL };
			*(ScriptName*)params = ParamName;
			*(ScriptString**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetFloat(ScriptName ParamName, float& out_Float)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18143);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParamName;
			*(float*)&params[8] = out_Float;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Float = *(float*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetInt(ScriptName ParamName, int& out_int)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18147);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParamName;
			*(int*)&params[8] = out_int;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_int = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetVector(ScriptName ParamName, Vector& out_vector)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18151);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParamName;
			*(Vector*)&params[8] = out_vector;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_vector = *(Vector*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetString(ScriptName ParamName, ScriptString*& out_string)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18155);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParamName;
			*(ScriptString**)&params[8] = out_string;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_string = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		void CommitToDisk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18159);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
