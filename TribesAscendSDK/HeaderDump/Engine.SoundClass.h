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
namespace UnrealScript
{
	class SoundClass : public Object
	{
	public:
		struct SoundClassEditorData
		{
		public:
			ADD_STRUCT(int, NodePosY, 4)
			ADD_STRUCT(int, NodePosX, 0)
		};
		struct SoundClassProperties
		{
		public:
			ADD_BOOL(bBassBoost, 28, 0x40)
			ADD_BOOL(bCenterChannelOnly, 28, 0x20)
			ADD_BOOL(bReverb, 28, 0x10)
			ADD_BOOL(bIsMusic, 28, 0x8)
			ADD_BOOL(bIsUISound, 28, 0x4)
			ADD_BOOL(bAlwaysPlay, 28, 0x2)
			ADD_BOOL(bApplyEffects, 28, 0x1)
			ADD_STRUCT(float, RadioFilterVolumeThreshold, 24)
			ADD_STRUCT(float, RadioFilterVolume, 20)
			ADD_STRUCT(float, VoiceCenterChannelVolume, 16)
			ADD_STRUCT(float, LFEBleed, 12)
			ADD_STRUCT(float, StereoBleed, 8)
			ADD_STRUCT(float, Pitch, 4)
			ADD_STRUCT(float, Volume, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptName>, ChildClassNames, 92)
		ADD_STRUCT(int, MenuID, 108)
		ADD_BOOL(bIsChild, 104, 0x1)
		ADD_STRUCT(SoundClass::SoundClassProperties, Properties, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
