#pragma once
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Engine.Sequence.h"
#include "Engine.WorldInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SequenceObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SequenceObject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SequenceObject : public Object
	{
	public:
		ADD_VAR(::IntProperty, ObjInstanceVersion, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DrawHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DrawWidth, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSuppressAutoComment, 0x10)
		ADD_VAR(::BoolProperty, bOutputObjCommentToScreen, 0x8)
		ADD_VAR(::BoolProperty, bDrawLast, 0x4)
		ADD_VAR(::BoolProperty, bDrawFirst, 0x2)
		ADD_VAR(::BoolProperty, bDeletable, 0x1)
		ADD_VAR(::StrProperty, ObjComment, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, ObjColor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ObjCategory, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ObjName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ObjPosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ObjPosX, 0xFFFFFFFF)
		ADD_OBJECT(Sequence, ParentSequence)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceObject.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void ScriptLog(ScriptArray<wchar_t> LogText, bool bWarning)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceObject.ScriptLog");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = LogText;
			*(bool*)(params + 12) = bWarning;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class WorldInfo* GetWorldInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceObject.GetWorldInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class WorldInfo**)params;
			free(params);
			return returnVal;
		}
		bool IsValidLevelSequenceObject()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceObject.IsValidLevelSequenceObject");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsPastingIntoLevelSequenceAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SequenceObject.IsPastingIntoLevelSequenceAllowed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
