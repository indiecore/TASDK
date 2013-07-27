#pragma once
#include "Engine.AnimSequence.h"
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
	class AnimSet : public Object
	{
	public:
		struct AnimSetMeshLinkup
		{
		public:
			ADD_STRUCT(ScriptArray<int>, BoneToTrackTable, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptName>, TrackBoneNames, 64)
		ADD_STRUCT(ScriptArray<class AnimSequence*>, Sequences, 76)
		ADD_STRUCT(ScriptArray<AnimSet::AnimSetMeshLinkup>, LinkupCache, 148)
		ADD_STRUCT(ScriptArray<byte>, BoneUseAnimTranslation, 220)
		ADD_STRUCT(ScriptArray<byte>, ForceUseMeshTranslation, 232)
		ADD_STRUCT(ScriptArray<ScriptName>, UseTranslationBoneNames, 244)
		ADD_STRUCT(ScriptArray<ScriptName>, ForceMeshTranslationBoneNames, 256)
		ADD_STRUCT(ScriptName, BestRatioSkelMeshName, 276)
		ADD_STRUCT(ScriptName, PreviewSkelMeshName, 268)
		ADD_BOOL(bAnimRotationOnly, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
