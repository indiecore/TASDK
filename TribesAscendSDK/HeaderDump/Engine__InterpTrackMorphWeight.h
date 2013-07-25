#pragma once
#include "Engine__InterpTrackFloatBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackMorphWeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackMorphWeight : public InterpTrackFloatBase
	{
	public:
		ADD_VAR(::NameProperty, MorphNodeName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
