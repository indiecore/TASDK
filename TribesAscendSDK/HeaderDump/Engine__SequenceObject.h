#pragma once
#include "Core__Object.h"
#include "Engine__Sequence.h"
#include "Engine__WorldInfo.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ObjColor'!
		ADD_VAR(::StrProperty, ObjCategory, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ObjName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ObjPosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ObjPosX, 0xFFFFFFFF)
		ADD_OBJECT(Sequence, ParentSequence)
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
		// Here lies the not-yet-implemented method 'ScriptLog'
		// Here lies the not-yet-implemented method 'GetWorldInfo'
		// Here lies the not-yet-implemented method 'IsValidLevelSequenceObject'
		// Here lies the not-yet-implemented method 'IsPastingIntoLevelSequenceAllowed'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
