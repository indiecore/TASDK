#pragma once
#include "Engine__InterpTrackInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackInstParticleReplay." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstParticleReplay : public InterpTrackInst
	{
	public:
		ADD_VAR(::FloatProperty, LastUpdatePosition, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
