#pragma once
#include "Core.Property.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SequenceOp.SeqVarLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SequenceOp.SeqVarLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqVarLink
	{
	public:
		ADD_VAR(::IntProperty, OverrideDelta, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClampedMin, 0x8)
		ADD_VAR(::BoolProperty, bClampedMax, 0x4)
		ADD_VAR(::BoolProperty, bMoving, 0x2)
		ADD_VAR(::BoolProperty, bAllowAnyType, 0x1)
		ADD_OBJECT(Property, CachedProperty)
		ADD_VAR(::IntProperty, DrawX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxVars, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinVars, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHidden, 0x8)
		ADD_VAR(::BoolProperty, bModifiesLinkedObject, 0x4)
		ADD_VAR(::BoolProperty, bSequenceNeverReadsOnlyWritesToThisVar, 0x2)
		ADD_VAR(::BoolProperty, bWriteable, 0x1)
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LinkVar, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LinkDesc, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExpectedType)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
