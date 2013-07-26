#pragma once
#include "Engine.LevelStreaming.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LevelStreamingDistance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LevelStreamingDistance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LevelStreamingDistance : public LevelStreaming
	{
	public:
		ADD_VAR(::FloatProperty, MaxDistance, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Origin, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
