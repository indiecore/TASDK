#pragma once
#include "Engine.AnimNodeBlendBase.h"
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
	class AnimNodeAimOffset : public AnimNodeBlendBase
	{
	public:
		enum EAnimAimDir : byte
		{
			ANIMAIM_LEFTUP = 0,
			ANIMAIM_CENTERUP = 1,
			ANIMAIM_RIGHTUP = 2,
			ANIMAIM_LEFTCENTER = 3,
			ANIMAIM_CENTERCENTER = 4,
			ANIMAIM_RIGHTCENTER = 5,
			ANIMAIM_LEFTDOWN = 6,
			ANIMAIM_CENTERDOWN = 7,
			ANIMAIM_RIGHTDOWN = 8,
			ANIMAIM_MAX = 9,
		};
		enum EAimID : byte
		{
			EAID_LeftUp = 0,
			EAID_LeftDown = 1,
			EAID_RightUp = 2,
			EAID_RightDown = 3,
			EAID_ZeroUp = 4,
			EAID_ZeroDown = 5,
			EAID_ZeroLeft = 6,
			EAID_ZeroRight = 7,
			EAID_CellLU = 8,
			EAID_CellCU = 9,
			EAID_CellRU = 10,
			EAID_CellLC = 11,
			EAID_CellCC = 12,
			EAID_CellRC = 13,
			EAID_CellLD = 14,
			EAID_CellCD = 15,
			EAID_CellRD = 16,
			EAID_MAX = 17,
		};
		struct AimTransform
		{
		public:
			ADD_STRUCT(Vector, Translation, 16)
			ADD_STRUCT(Object::Quat, Quaternion, 0)
		};
		struct AimComponent
		{
		public:
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, RD, 272)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, RC, 240)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, RU, 208)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, CD, 176)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, CC, 144)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, CU, 112)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, LD, 80)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, LC, 48)
			ADD_STRUCT(AnimNodeAimOffset::AimTransform, LU, 16)
			ADD_STRUCT(ScriptName, BoneName, 0)
		};
		struct AimOffsetProfile
		{
		public:
			ADD_STRUCT(ScriptArray<AnimNodeAimOffset::AimComponent>, AimComponents, 24)
			ADD_STRUCT(ScriptName, AnimName_RD, 100)
			ADD_STRUCT(ScriptName, AnimName_RC, 92)
			ADD_STRUCT(ScriptName, AnimName_RU, 84)
			ADD_STRUCT(ScriptName, AnimName_CD, 76)
			ADD_STRUCT(ScriptName, AnimName_CC, 68)
			ADD_STRUCT(ScriptName, AnimName_CU, 60)
			ADD_STRUCT(ScriptName, AnimName_LD, 52)
			ADD_STRUCT(ScriptName, AnimName_LC, 44)
			ADD_STRUCT(ScriptName, AnimName_LU, 36)
			ADD_STRUCT(Object::Vector2D, VerticalRange, 16)
			ADD_STRUCT(Object::Vector2D, HorizontalRange, 8)
			ADD_STRUCT(ScriptName, ProfileName, 0)
		};
		ADD_STRUCT(ScriptArray<byte>, RequiredBones, 272)
		ADD_STRUCT(ScriptArray<byte>, AimCpntIndexLUT, 284)
		ADD_STRUCT(ScriptArray<AnimNodeAimOffset::AimOffsetProfile>, Profiles, 300)
		ADD_STRUCT(int, CurrentProfileIndex, 312)
		ADD_OBJECT(AnimNodeAimOffset, TemplateNode, 296)
		ADD_STRUCT(AnimNodeAimOffset::EAnimAimDir, ForcedAimDir, 268)
		ADD_STRUCT(int, PassThroughAtOrAboveLOD, 264)
		ADD_BOOL(bSynchronizeNodesInEditor, 260, 0x8)
		ADD_BOOL(bPassThroughWhenNotRendered, 260, 0x4)
		ADD_BOOL(bBakeFromAnimations, 260, 0x2)
		ADD_BOOL(bForceAimDir, 260, 0x1)
		ADD_STRUCT(Object::Vector2D, AngleOffset, 252)
		ADD_STRUCT(Object::Vector2D, Aim, 244)
		void SetActiveProfileByName(ScriptName ProfileName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10809);
			byte params[8] = { NULL };
			*(ScriptName*)params = ProfileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveProfileByIndex(int ProfileIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10811);
			byte params[4] = { NULL };
			*(int*)params = ProfileIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
