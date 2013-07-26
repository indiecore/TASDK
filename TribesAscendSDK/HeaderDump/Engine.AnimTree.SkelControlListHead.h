#pragma once
#include "Engine.SkelControlBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimTree.SkelControlListHead." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AnimTree.SkelControlListHead." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkelControlListHead
	{
	public:
		ADD_VAR(::IntProperty, DrawY, 0xFFFFFFFF)
		ADD_OBJECT(SkelControlBase, ControlHead)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
