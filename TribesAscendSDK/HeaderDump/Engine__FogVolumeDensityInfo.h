#pragma once
#include "Engine__Info.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FogVolumeDensityInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FogVolumeDensityInfo : public Info
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'ShouldSaveForCheckpoint'
		// Here lies the not-yet-implemented method 'CreateCheckpointRecord'
		// Here lies the not-yet-implemented method 'ApplyCheckpointRecord'
	};
}
#undef ADD_VAR
