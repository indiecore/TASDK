#pragma once
#include "Engine.ParticleModuleLocationBase.h"
#include "Engine.SkeletalMesh.h"
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
	class ParticleModuleLocationBoneSocket : public ParticleModuleLocationBase
	{
	public:
		enum ELocationBoneSocketSource : byte
		{
			BONESOCKETSOURCE_Bones = 0,
			BONESOCKETSOURCE_Sockets = 1,
			BONESOCKETSOURCE_MAX = 2,
		};
		enum ELocationBoneSocketSelectionMethod : byte
		{
			BONESOCKETSEL_Sequential = 0,
			BONESOCKETSEL_Random = 1,
			BONESOCKETSEL_RandomExhaustive = 2,
			BONESOCKETSEL_MAX = 3,
		};
		struct LocationBoneSocketInfo
		{
		public:
			ADD_STRUCT(Vector, Offset, 8)
			ADD_STRUCT(ScriptName, BoneSocketName, 0)
		};
		ADD_STRUCT(ScriptArray<ParticleModuleLocationBoneSocket::LocationBoneSocketInfo>, SourceLocations, 88)
		ADD_OBJECT(SkeletalMesh, EditorSkelMesh, 112)
		ADD_STRUCT(ScriptName, SkelMeshActorParamName, 104)
		ADD_BOOL(bOrientMeshEmitters, 100, 0x2)
		ADD_BOOL(bUpdatePositionEachFrame, 100, 0x1)
		ADD_STRUCT(Vector, UniversalOffset, 76)
		ADD_STRUCT(ParticleModuleLocationBoneSocket::ELocationBoneSocketSelectionMethod, SelectionMethod, 73)
		ADD_STRUCT(ParticleModuleLocationBoneSocket::ELocationBoneSocketSource, SourceType, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
