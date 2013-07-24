#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeployableController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeployableController : public AIController
	{
	public:
		ADD_OBJECT(TrPlayerController, m_SpawnedFromController)
	};
}
#undef ADD_OBJECT
