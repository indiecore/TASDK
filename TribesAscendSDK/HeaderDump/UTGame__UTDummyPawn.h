#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDummyPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDummyPawn : public UTPawn
	{
	public:
		ADD_OBJECT(UTSeqAct_DummyWeaponFire, FireAction)
	};
}
#undef ADD_OBJECT
