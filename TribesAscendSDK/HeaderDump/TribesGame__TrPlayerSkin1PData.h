#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPlayerSkin1PData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPlayerSkin1PData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerSkin1PData : public Object
	{
	public:
		ADD_OBJECT(SkeletalMesh, m_FirstPersonBodyMesh)
		ADD_OBJECT(SkeletalMesh, m_FirstPersonHandsMesh)
		ADD_VAR(::IntProperty, m_nClassId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nSkinId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
