#pragma once
#include "Engine.Volume.h"
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
	class ReverbVolume : public Volume
	{
	public:
		enum ReverbPreset : byte
		{
			REVERB_Default = 0,
			REVERB_Bathroom = 1,
			REVERB_StoneRoom = 2,
			REVERB_Auditorium = 3,
			REVERB_ConcertHall = 4,
			REVERB_Cave = 5,
			REVERB_Hallway = 6,
			REVERB_StoneCorridor = 7,
			REVERB_Alley = 8,
			REVERB_Forest = 9,
			REVERB_City = 10,
			REVERB_Mountains = 11,
			REVERB_Quarry = 12,
			REVERB_Plain = 13,
			REVERB_ParkingLot = 14,
			REVERB_SewerPipe = 15,
			REVERB_Underwater = 16,
			REVERB_SmallRoom = 17,
			REVERB_MediumRoom = 18,
			REVERB_LargeRoom = 19,
			REVERB_MediumHall = 20,
			REVERB_LargeHall = 21,
			REVERB_Plate = 22,
			REVERB_MAX = 23,
		};
		struct InteriorSettings
		{
		public:
			ADD_BOOL(bIsWorldInfo, 0, 0x1)
			ADD_STRUCT(float, ExteriorVolume, 4)
			ADD_STRUCT(float, ExteriorTime, 8)
			ADD_STRUCT(float, ExteriorLPF, 12)
			ADD_STRUCT(float, ExteriorLPFTime, 16)
			ADD_STRUCT(float, InteriorVolume, 20)
			ADD_STRUCT(float, InteriorTime, 24)
			ADD_STRUCT(float, InteriorLPF, 28)
			ADD_STRUCT(float, InteriorLPFTime, 32)
		};
		struct ReverbSettings
		{
		public:
			ADD_BOOL(bApplyReverb, 0, 0x1)
			ADD_STRUCT(ReverbVolume::ReverbPreset, ReverbType, 4)
			ADD_STRUCT(float, Volume, 8)
			ADD_STRUCT(float, FadeTime, 12)
		};
		ADD_OBJECT(ReverbVolume, NextLowerPriorityVolume, 580)
		ADD_STRUCT(ReverbVolume::InteriorSettings, AmbientZoneSettings, 544)
		ADD_STRUCT(ReverbVolume::ReverbSettings, Settings, 528)
		ADD_BOOL(bEnabled, 524, 0x1)
		ADD_STRUCT(float, Priority, 520)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
