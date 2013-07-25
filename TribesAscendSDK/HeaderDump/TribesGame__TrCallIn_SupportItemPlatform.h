#pragma once
#include "Engine__Actor.h"
#include "TribesGame__TrGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_SupportItemPlatform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_SupportItemPlatform." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_SupportItemPlatform : public Actor
	{
	public:
		ADD_OBJECT(TrGameObjective, r_DeployedItem)
		ADD_VAR(::ByteProperty, DefenderTeamIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ItemAttachPointName, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetBoundingCylinder'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'ScriptGetTeamNum'
		// Here lies the not-yet-implemented method 'HideMesh'
		// Here lies the not-yet-implemented method 'Tick'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
