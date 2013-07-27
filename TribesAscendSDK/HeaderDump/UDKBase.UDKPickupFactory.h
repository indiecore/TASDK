#pragma once
#include "Core.Object.h"
#include "Engine.PickupFactory.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKPickupFactory : public PickupFactory
	{
	public:
		ADD_STRUCT(ScriptName, GlowEmissiveParam, 868)
		ADD_OBJECT(MaterialInstanceConstant, MIC_VisibilitySecondMaterial, 860)
		ADD_OBJECT(MaterialInstanceConstant, MIC_Visibility, 856)
		ADD_STRUCT(ScriptName, VisibilityParamName, 848)
		ADD_STRUCT(Vector, PivotTranslation, 836)
		ADD_STRUCT(float, YawRotationRate, 832)
		ADD_STRUCT(float, BobBaseOffset, 828)
		ADD_STRUCT(float, BobSpeed, 824)
		ADD_STRUCT(float, BobOffset, 820)
		ADD_STRUCT(float, BobTimer, 816)
		ADD_STRUCT(ScriptName, BaseMaterialParamName, 808)
		ADD_STRUCT(Object::LinearColor, BaseEmissive, 792)
		ADD_STRUCT(Object::LinearColor, BaseTargetEmissive, 776)
		ADD_STRUCT(float, PulseThreshold, 772)
		ADD_STRUCT(float, BasePulseTime, 768)
		ADD_STRUCT(float, BasePulseRate, 764)
		ADD_STRUCT(Object::LinearColor, BaseDimEmissive, 748)
		ADD_STRUCT(Object::LinearColor, BaseBrightEmissive, 732)
		ADD_OBJECT(MaterialInstanceConstant, BaseMaterialInstance, 728)
		ADD_BOOL(bDoVisibilityFadeIn, 720, 0x80)
		ADD_BOOL(bUpdatingPickup, 720, 0x40)
		ADD_BOOL(bRotatingPickup, 720, 0x20)
		ADD_BOOL(bRandomStart, 720, 0x10)
		ADD_BOOL(bFloatingPickup, 720, 0x8)
		ADD_BOOL(bIsDisabled, 720, 0x4)
		ADD_BOOL(bPulseBase, 720, 0x2)
		ADD_BOOL(bIsRespawning, 720, 0x1)
		void SetPickupVisible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35231);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPickupHidden()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35232);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
