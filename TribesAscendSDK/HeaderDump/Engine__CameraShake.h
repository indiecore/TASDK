#pragma once
#include "Core__Object.h"
#include "Engine__CameraAnim.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraShake." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CameraShake." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CameraShake." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CameraShake : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.CameraShake.VOscillator' for the property named 'LocOscillation'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.CameraShake.ROscillator' for the property named 'RotOscillation'!
		ADD_VAR(::BoolProperty, bSingleInstance, 0x1)
		ADD_VAR(::BoolProperty, bRandomAnimSegment, 0x2)
		ADD_VAR(::FloatProperty, OscillationDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OscillationBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OscillationBlendOutTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.CameraShake.FOscillator' for the property named 'FOVOscillation'!
		ADD_OBJECT(CameraAnim, Anim)
		ADD_VAR(::FloatProperty, AnimPlayRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AnimBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RandomAnimSegmentDuration, 0xFFFFFFFF)
		float GetLocOscillationMagnitude()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraShake.GetLocOscillationMagnitude");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetRotOscillationMagnitude()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraShake.GetRotOscillationMagnitude");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
