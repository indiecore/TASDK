#pragma once
#include "Engine__SequenceOp.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Sequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Sequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Sequence : public SequenceOp
	{
	public:
		ADD_VAR(::FloatProperty, DefaultViewZoom, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DefaultViewY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DefaultViewX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'LogFile'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
