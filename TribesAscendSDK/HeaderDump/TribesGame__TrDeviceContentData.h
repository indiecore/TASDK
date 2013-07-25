#pragma once
#include "Engine__AnimSet.h"
#include "Core__Object.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__AnimTree.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeviceContentData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeviceContentData : public Object
	{
	public:
		ADD_OBJECT(ScriptClass, m_TrDeviceClass)
		ADD_OBJECT(AnimSet, m_PaperDollAnimSet)
		ADD_OBJECT(AnimTree, m_AnimTreeTemplate1p)
		ADD_OBJECT(PhysicsAsset, m_PhysicsAsset1p)
		ADD_OBJECT(SkeletalMesh, m_SkeletalMesh1p)
	};
}
#undef ADD_OBJECT
