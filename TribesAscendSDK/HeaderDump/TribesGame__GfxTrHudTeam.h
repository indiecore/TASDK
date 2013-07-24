#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GfxTrHudTeam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GfxTrHudTeam : public GfxTrHud
	{
	public:
		ADD_OBJECT(GFxObject, FlagCarrierTF)
		ADD_OBJECT(GFxObject, ScoreTF)
		ADD_OBJECT(GFxObject, ScoreBarMC)
	};
}
#undef ADD_OBJECT
