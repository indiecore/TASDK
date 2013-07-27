#pragma once
#include "Core.Object.h"
#include "Engine.Sequence.h"
#include "Engine.WorldInfo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class SequenceObject : public Object
	{
	public:
		ADD_STRUCT(int, ObjInstanceVersion, 60)
		ADD_STRUCT(ScriptArray<ScriptString*>, ObjRemoveInProject, 100)
		ADD_STRUCT(int, DrawHeight, 136)
		ADD_STRUCT(int, DrawWidth, 132)
		ADD_BOOL(bSuppressAutoComment, 128, 0x10)
		ADD_BOOL(bOutputObjCommentToScreen, 128, 0x8)
		ADD_BOOL(bDrawLast, 128, 0x4)
		ADD_BOOL(bDrawFirst, 128, 0x2)
		ADD_BOOL(bDeletable, 128, 0x1)
		ADD_STRUCT(ScriptString*, ObjComment, 116)
		ADD_STRUCT(Object::Color, ObjColor, 112)
		ADD_STRUCT(ScriptString*, ObjCategory, 88)
		ADD_STRUCT(ScriptString*, ObjName, 76)
		ADD_STRUCT(int, ObjPosY, 72)
		ADD_STRUCT(int, ObjPosX, 68)
		ADD_OBJECT(Sequence, ParentSequence, 64)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4399);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void ScriptLog(ScriptString* LogText, bool bWarning)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6710);
			byte params[16] = { NULL };
			*(ScriptString**)params = LogText;
			*(bool*)&params[12] = bWarning;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class WorldInfo* GetWorldInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6713);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class WorldInfo**)params;
		}
		bool IsValidLevelSequenceObject()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6715);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsPastingIntoLevelSequenceAllowed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6717);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
