#pragma once
#include "Engine.CodecMovie.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CodecMovieFallback." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CodecMovieFallback : public CodecMovie
	{
	public:
		ADD_VAR(::FloatProperty, CurrentTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
