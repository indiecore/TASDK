#pragma once
#include "Engine.StaticMeshComponent.h"
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
	class SplineMeshComponent : public StaticMeshComponent
	{
	public:
		class SplineMeshParams
		{
		public:
			ADD_STRUCT(Object::Vector2D, EndOffset, 80)
			ADD_STRUCT(float, EndRoll, 76)
			ADD_STRUCT(Object::Vector2D, EndScale, 68)
			ADD_STRUCT(Object::Vector, EndTangent, 56)
			ADD_STRUCT(Object::Vector, EndPos, 44)
			ADD_STRUCT(Object::Vector2D, StartOffset, 36)
			ADD_STRUCT(float, StartRoll, 32)
			ADD_STRUCT(Object::Vector2D, StartScale, 24)
			ADD_STRUCT(Object::Vector, StartTangent, 12)
			ADD_STRUCT(Object::Vector, StartPos, 0)
		};
		ADD_BOOL(bSmoothInterpRollScale, 708, 0x1)
		ADD_STRUCT(Object::Vector, SplineXDir, 696)
		ADD_STRUCT(SplineMeshComponent::SplineMeshParams, SplineParams, 608)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
