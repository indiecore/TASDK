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
	class GameSkelCtrl_Recoil : public SkelControlBase
	{
	public:
		enum ERecoilStart : byte
		{
			ERS_Zero = 0,
			ERS_Random = 1,
			ERS_MAX = 2,
		};
		struct RecoilParams
		{
		public:
			ADD_STRUCT(byte, Padding, 3)
			ADD_STRUCT(GameSkelCtrl_Recoil::ERecoilStart, Z, 2)
			ADD_STRUCT(GameSkelCtrl_Recoil::ERecoilStart, Y, 1)
			ADD_STRUCT(GameSkelCtrl_Recoil::ERecoilStart, X, 0)
		};
		struct RecoilDef
		{
		public:
			ADD_STRUCT(Vector, LocOffset, 100)
			ADD_STRUCT(GameSkelCtrl_Recoil::RecoilParams, LocParams, 96)
			ADD_STRUCT(Vector, LocSinOffset, 84)
			ADD_STRUCT(Vector, LocFrequency, 72)
			ADD_STRUCT(Vector, LocAmplitude, 60)
			ADD_STRUCT(Rotator, RotOffset, 48)
			ADD_STRUCT(GameSkelCtrl_Recoil::RecoilParams, RotParams, 44)
			ADD_STRUCT(Vector, RotSinOffset, 32)
			ADD_STRUCT(Vector, RotFrequency, 20)
			ADD_STRUCT(Vector, RotAmplitude, 8)
			ADD_STRUCT(float, TimeDuration, 4)
			ADD_STRUCT(float, TimeToGo, 0)
		};
		ADD_STRUCT(Object::Vector2D, Aim, 304)
		ADD_STRUCT(GameSkelCtrl_Recoil::RecoilDef, Recoil, 192)
		ADD_BOOL(bApplyControl, 188, 0x8)
		ADD_BOOL(bOldPlayRecoil, 188, 0x4)
		ADD_BOOL(bPlayRecoil, 188, 0x2)
		ADD_BOOL(bBoneSpaceRecoil, 188, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
