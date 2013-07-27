#pragma once
#include "Engine.AnimTree.h"
#include "Core.Object.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.AnimSet.h"
#include "Engine.PhysicsAsset.h"
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
	class TrDeviceContentData : public Object
	{
	public:
		ADD_OBJECT(ScriptClass, m_TrDeviceClass, 88)
		ADD_STRUCT(ScriptArray<class AnimSet*>, m_AnimSets1p, 68)
		ADD_OBJECT(AnimSet, m_PaperDollAnimSet, 84)
		ADD_OBJECT(AnimTree, m_AnimTreeTemplate1p, 80)
		ADD_OBJECT(PhysicsAsset, m_PhysicsAsset1p, 64)
		ADD_OBJECT(SkeletalMesh, m_SkeletalMesh1p, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
