#pragma once
#include "Engine.PhysicsVolume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPhysicsVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrPhysicsVolume : public PhysicsVolume
	{
	public:
		ADD_VAR(::ByteProperty, m_ContextLocation, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_DefenderTeamIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
