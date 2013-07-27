#pragma once
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
	class GameTypes : public Object
	{
	public:
		static const const char* LOADING_MOVIE;
		enum EShakeParam : byte
		{
			ESP_OffsetRandom = 0,
			ESP_OffsetZero = 1,
			ESP_MAX = 2,
		};
		class AICmdHistoryItem
		{
		public:
			ADD_OBJECT(ScriptClass, CmdClass, 0)
			ADD_STRUCT(float, TimeStamp, 4)
			ADD_STRUCT(ScriptString*, VerboseString, 8)
		};
		class SpecialMoveStruct
		{
		public:
			ADD_STRUCT(ScriptName, SpecialMoveName, 0)
			ADD_OBJECT(GamePawn, InteractionPawn, 8)
			ADD_OBJECT(Actor, InteractionActor, 12)
			ADD_STRUCT(int, Flags, 16)
		};
		class GameSpecialMoveInfo
		{
		public:
			ADD_STRUCT(ScriptName, SpecialMoveName, 0)
			ADD_OBJECT(ScriptClass, SpecialMoveClass, 8)
			ADD_OBJECT(GameSpecialMove, SpecialMoveInstance, 12)
		};
		class TakeHitInfo
		{
		public:
			ADD_STRUCT(Object::Vector, HitLocation, 0)
			ADD_STRUCT(Object::Vector, Momentum, 12)
			ADD_OBJECT(ScriptClass, DamageType, 24)
			ADD_OBJECT(Pawn, InstigatedBy, 28)
			ADD_STRUCT(byte, HitBoneIndex, 32)
			ADD_OBJECT(PhysicalMaterial, PhysicalMaterial, 36)
			ADD_STRUCT(float, Damage, 40)
			ADD_STRUCT(Object::Vector, RadialDamageOrigin, 44)
		};
		class ScreenShakeAnimStruct
		{
		public:
			ADD_OBJECT(CameraAnim, Anim, 0)
			ADD_BOOL(bUseDirectionalAnimVariants, 4, 0x1)
			ADD_OBJECT(CameraAnim, Anim_Left, 8)
			ADD_OBJECT(CameraAnim, Anim_Right, 12)
			ADD_OBJECT(CameraAnim, Anim_Rear, 16)
			ADD_STRUCT(float, AnimPlayRate, 20)
			ADD_STRUCT(float, AnimScale, 24)
			ADD_STRUCT(float, AnimBlendInTime, 28)
			ADD_STRUCT(float, AnimBlendOutTime, 32)
			ADD_BOOL(bRandomSegment, 36, 0x1)
			ADD_STRUCT(float, RandomSegmentDuration, 40)
			ADD_BOOL(bSingleInstance, 44, 0x1)
		};
		class ShakeParams
		{
		public:
			ADD_STRUCT(GameTypes::EShakeParam, X, 0)
			ADD_STRUCT(GameTypes::EShakeParam, Y, 1)
			ADD_STRUCT(GameTypes::EShakeParam, Z, 2)
			ADD_STRUCT(byte, Padding, 3)
		};
		class ScreenShakeStruct
		{
		public:
			ADD_STRUCT(float, TimeToGo, 0)
			ADD_STRUCT(float, TimeDuration, 4)
			ADD_STRUCT(Object::Vector, RotAmplitude, 8)
			ADD_STRUCT(Object::Vector, RotFrequency, 20)
			ADD_STRUCT(Object::Vector, RotSinOffset, 32)
			ADD_STRUCT(GameTypes::ShakeParams, RotParam, 44)
			ADD_STRUCT(Object::Vector, LocAmplitude, 48)
			ADD_STRUCT(Object::Vector, LocFrequency, 60)
			ADD_STRUCT(Object::Vector, LocSinOffset, 72)
			ADD_STRUCT(GameTypes::ShakeParams, LocParam, 84)
			ADD_STRUCT(float, FOVAmplitude, 88)
			ADD_STRUCT(float, FOVFrequency, 92)
			ADD_STRUCT(float, FOVSinOffset, 96)
			ADD_STRUCT(GameTypes::EShakeParam, FOVParam, 100)
			ADD_STRUCT(ScriptName, ShakeName, 104)
			ADD_BOOL(bOverrideTargetingDampening, 112, 0x1)
			ADD_STRUCT(float, TargetingDampening, 116)
		};
	};
	const const char* GameTypes::LOADING_MOVIE = "LoadingMovie";
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
