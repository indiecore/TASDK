#pragma once
#include "Core__Object.h"
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
		ADD_OBJECT(AnimSet, m_PaperDollAnimSet)
		ADD_OBJECT(AnimTree, m_AnimTreeTemplate1p)
		ADD_OBJECT(PhysicsAsset, m_PhysicsAsset1p)
		ADD_OBJECT(SkeletalMesh, m_SkeletalMesh1p)
	};
}
#undef ADD_OBJECT
