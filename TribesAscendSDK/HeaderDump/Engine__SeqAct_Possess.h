#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Possess." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_Possess." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_Possess : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bTryToLeaveVehicle, 0x2)
		ADD_OBJECT(Pawn, PawnToPossess)
		ADD_VAR(::BoolProperty, bKillOldPawn, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
