#pragma once
#include "Engine.PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LineBatchComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LineBatchComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LineBatchComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, DefaultLifeTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'FPrimitiveDrawInterfaceView'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'FPrimitiveDrawInterfaceVfTable'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
