#pragma once
#include "UDKBase.UDKAnimNodeSeqWeap.h"
#include "Engine.AnimNodeBlendBase.h"
#include "UDKBase.UDKAnimBlendByWeapType.h"
#include "Engine.AnimNodeAimOffset.h"
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
	class UDKAnimNodeCopyBoneTranslation : public AnimNodeBlendBase
	{
	public:
		class BoneCopyInfo
		{
		public:
			ADD_STRUCT(int, DstBoneIndex, 20)
			ADD_STRUCT(int, SrcBoneIndex, 16)
			ADD_STRUCT(ScriptName, DstBoneName, 8)
			ADD_STRUCT(ScriptName, SrcBoneName, 0)
		};
		ADD_STRUCT(ScriptArray<UDKAnimNodeCopyBoneTranslation::BoneCopyInfo>, DefaultBoneCopyArray, 256)
		ADD_STRUCT(ScriptArray<UDKAnimNodeCopyBoneTranslation::BoneCopyInfo>, DualWieldBoneCopyArray, 268)
		ADD_STRUCT(ScriptArray<UDKAnimNodeCopyBoneTranslation::BoneCopyInfo>, ActiveBoneCopyArray, 280)
		ADD_STRUCT(ScriptArray<byte>, RequiredBones, 292)
		ADD_STRUCT(ScriptArray<class UDKAnimNodeSeqWeap*>, SeqWeaps, 304)
		ADD_STRUCT(ScriptArray<class UDKAnimBlendByWeapType*>, WeapTypeBlends, 316)
		ADD_STRUCT(ScriptName, OldAimProfileName, 248)
		ADD_OBJECT(AnimNodeAimOffset, CachedAimNode, 244)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
