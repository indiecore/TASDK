#pragma once
#include "Engine__Volume.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LevelStreamingVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LevelStreamingVolume : public Volume
	{
	public:
		ADD_VAR(::FloatProperty, TestVolumeDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Usage, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, StreamingUsage, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTestDistanceToVolume, 0x4)
		ADD_VAR(::BoolProperty, bDisabled, 0x2)
		ADD_VAR(::BoolProperty, bEditorPreVisOnly, 0x1)
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'CreateCheckpointRecord'
		// Here lies the not-yet-implemented method 'ApplyCheckpointRecord'
	};
}
#undef ADD_VAR
