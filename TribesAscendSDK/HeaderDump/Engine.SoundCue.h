#pragma once
#include "Core.Object.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SoundNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundCue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SoundCue." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SoundCue : public Object
	{
	public:
		ADD_VAR(::StrProperty, FaceFXAnimName, 0xFFFFFFFF)
		ADD_OBJECT(FaceFXAnimSet, FaceFXAnimSetRef)
		ADD_VAR(::StrProperty, FaceFXGroupName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SoundGroup, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentPlayCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxConcurrentPlayCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VolumeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxAudibleDistance, 0xFFFFFFFF)
		ADD_OBJECT(SoundNode, FirstNode)
		ADD_VAR(::ByteProperty, SoundClassName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SoundClass, 0xFFFFFFFF)
		float GetCueDuration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SoundCue.GetCueDuration");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
