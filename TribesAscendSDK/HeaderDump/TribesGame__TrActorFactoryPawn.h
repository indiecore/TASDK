#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrActorFactoryPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrActorFactoryPawn : public UTActorFactoryAI
	{
	public:
		ADD_VAR(::FloatProperty, GroundSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NextTeam, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
