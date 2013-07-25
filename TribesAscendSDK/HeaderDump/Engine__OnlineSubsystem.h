#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineSubsystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineSubsystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.OnlineSubsystem." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystem : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FTickableObject'!
		ADD_VAR(::StrProperty, IniLocPatcherClassName, 0xFFFFFFFF)
		ADD_OBJECT(IniLocPatcher, Patcher)
		ADD_VAR(::BoolProperty, bUseBuildIdOverride, 0x1)
		ADD_VAR(::IntProperty, BuildIdOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AsyncMinCompletionTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
