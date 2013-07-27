#pragma once
#include "Core.Object.h"
#include "Engine.StaticMesh.h"
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
	class SkeletalMeshSocket : public Object
	{
	public:
		ADD_OBJECT(StaticMesh, PreviewStaticMesh, 120)
		ADD_OBJECT(SkeletalMesh, PreviewSkelMesh, 112)
		ADD_STRUCT(Object::Vector, RelativeScale, 100)
		ADD_STRUCT(Object::Rotator, RelativeRotation, 88)
		ADD_STRUCT(Object::Vector, RelativeLocation, 76)
		ADD_STRUCT(ScriptName, BoneName, 68)
		ADD_STRUCT(ScriptName, SocketName, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
