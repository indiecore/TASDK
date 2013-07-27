#pragma once
#include "Engine.SkelControlBase.h"
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
namespace UnrealScript
{
	class SkelControlLookAt : public SkelControlBase
	{
	public:
		ADD_STRUCT(int, ControlBoneIndex, 316)
		ADD_STRUCT(float, LastCalcTime, 312)
		ADD_STRUCT(Object::Vector, BaseBonePos, 300)
		ADD_STRUCT(Object::Vector, BaseLookDir, 288)
		ADD_STRUCT(Object::Vector, LimitLookDir, 276)
		ADD_STRUCT(float, LookAtAlphaBlendTimeToGo, 272)
		ADD_STRUCT(float, LookAtAlphaTarget, 268)
		ADD_STRUCT(float, LookAtAlpha, 264)
		ADD_STRUCT(ScriptName, AllowRotationOtherBoneName, 256)
		ADD_STRUCT(float, DeadZoneAngle, 252)
		ADD_STRUCT(float, OuterMaxAngle, 248)
		ADD_STRUCT(float, MaxAngle, 244)
		ADD_STRUCT(Object::Vector, ActorSpaceLookAtTarget, 232)
		ADD_STRUCT(Object::Vector, DesiredTargetLocation, 220)
		ADD_STRUCT(float, TargetLocationInterpSpeed, 216)
		ADD_BOOL(bAllowRotationZ, 212, 0x400)
		ADD_BOOL(bAllowRotationY, 212, 0x200)
		ADD_BOOL(bAllowRotationX, 212, 0x100)
		ADD_BOOL(bShowLimit, 212, 0x80)
		ADD_BOOL(bNotifyBeyondLimit, 212, 0x40)
		ADD_BOOL(bDisableBeyondLimit, 212, 0x20)
		ADD_BOOL(bLimitBasedOnRefPose, 212, 0x10)
		ADD_BOOL(bEnableLimit, 212, 0x8)
		ADD_BOOL(bInvertUpAxis, 212, 0x4)
		ADD_BOOL(bDefineUpAxis, 212, 0x2)
		ADD_BOOL(bInvertLookAtAxis, 212, 0x1)
		ADD_STRUCT(ScriptName, TargetSpaceBoneName, 204)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, AllowRotationSpace, 203)
		ADD_STRUCT(Object::EAxis, UpAxis, 202)
		ADD_STRUCT(Object::EAxis, LookAtAxis, 201)
		ADD_STRUCT(SkelControlBase::EBoneControlSpace, TargetLocationSpace, 200)
		ADD_STRUCT(Object::Vector, TargetLocation, 188)
		void SetTargetLocation(Object::Vector NewTargetLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.SetTargetLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewTargetLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolateTargetLocation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.InterpolateTargetLocation");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLookAtAlpha(float DesiredAlpha, float DesiredBlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.SetLookAtAlpha");
			byte params[8] = { NULL };
			*(float*)&params[0] = DesiredAlpha;
			*(float*)&params[4] = DesiredBlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanLookAtPoint(Object::Vector PointLoc, bool bDrawDebugInfo, bool bDebugUsePersistentLines, bool bDebugFlushLinesFirst)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkelControlLookAt.CanLookAtPoint");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = PointLoc;
			*(bool*)&params[12] = bDrawDebugInfo;
			*(bool*)&params[16] = bDebugUsePersistentLines;
			*(bool*)&params[20] = bDebugFlushLinesFirst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
