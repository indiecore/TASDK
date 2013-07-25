#pragma once
#include "Engine.InterpTrackFloatBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackFloatParticleParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackFloatParticleParam : public InterpTrackFloatBase
	{
	public:
		ADD_VAR(::NameProperty, ParamName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
