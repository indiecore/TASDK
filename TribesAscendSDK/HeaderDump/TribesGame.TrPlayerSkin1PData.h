#pragma once
#include "Core.Object.h"
#include "Engine.SkeletalMesh.h"
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
	class TrPlayerSkin1PData : public Object
	{
	public:
		ADD_OBJECT(SkeletalMesh, m_FirstPersonBodyMesh, 68)
		ADD_OBJECT(SkeletalMesh, m_FirstPersonHandsMesh, 72)
		ADD_STRUCT(int, m_nClassId, 64)
		ADD_STRUCT(int, m_nSkinId, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
