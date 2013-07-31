#pragma once
#include "Engine.AnimObject.h"
#include "Engine.AnimNode.h"
#include "Core.Object.h"
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
	class SkelControlBase : public AnimObject
	{
	public:
		enum EBoneControlSpace : byte
		{
			BCS_WorldSpace = 0,
			BCS_ActorSpace = 1,
			BCS_ComponentSpace = 2,
			BCS_ParentBoneSpace = 3,
			BCS_BoneSpace = 4,
			BCS_OtherBoneSpace = 5,
			BCS_BaseMeshSpace = 6,
			BCS_MAX = 7,
		};
		ADD_STRUCT(ScriptArray<ScriptName>, StrengthAnimNodeNameList, 132)
		ADD_STRUCT(ScriptArray<class AnimNode*>, CachedNodeList, 144)
		ADD_STRUCT(int, ControlPosY, 184)
		ADD_STRUCT(int, ControlPosX, 180)
		ADD_OBJECT(SkelControlBase, NextControl, 176)
		ADD_STRUCT(int, IgnoreAtOrAboveLOD, 172)
		ADD_STRUCT(int, ControlTickTag, 168)
		ADD_STRUCT(float, BoneScale, 164)
		ADD_STRUCT(int, AnimMetaDataUpdateTag, 160)
		ADD_STRUCT(float, AnimMetadataWeight, 156)
		ADD_STRUCT(float, BlendTimeToGo, 128)
		ADD_STRUCT(float, StrengthTarget, 124)
		ADD_BOOL(bEnableEaseInOut, 120, 0x80)
		ADD_BOOL(bShouldTickInScript, 120, 0x40)
		ADD_BOOL(bIgnoreWhenNotRendered, 120, 0x20)
		ADD_BOOL(bPropagateSetActive, 120, 0x10)
		ADD_BOOL(bControlledByAnimMetada, 120, 0x8)
		ADD_BOOL(bInitializedCachedNodeList, 120, 0x4)
		ADD_BOOL(bSetStrengthFromAnimNode, 120, 0x2)
		ADD_BOOL(bPostPhysicsController, 120, 0x1)
		ADD_STRUCT(Object::AlphaBlendType, BlendType, 116)
		ADD_STRUCT(float, BlendOutTime, 112)
		ADD_STRUCT(float, BlendInTime, 108)
		ADD_STRUCT(float, ControlStrength, 104)
		ADD_STRUCT(ScriptName, ControlName, 96)
		void SetSkelControlActive(bool bInActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26298);
			byte params[4] = { NULL };
			*(bool*)params = bInActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlStrength(float NewStrength, float InBlendTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26300);
			byte params[8] = { NULL };
			*(float*)params = NewStrength;
			*(float*)&params[4] = InBlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TickSkelControl(float DeltaTime, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26303);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
