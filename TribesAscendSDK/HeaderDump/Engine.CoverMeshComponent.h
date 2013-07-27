#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Engine.StaticMesh.h"
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
	class CoverMeshComponent : public StaticMeshComponent
	{
	public:
		struct CoverMeshes
		{
		public:
			ADD_OBJECT(StaticMesh, PlayerOnly, 40)
			ADD_OBJECT(StaticMesh, PopUp, 36)
			ADD_OBJECT(StaticMesh, SwatRight, 32)
			ADD_OBJECT(StaticMesh, SwatLeft, 28)
			ADD_OBJECT(StaticMesh, SlipRight, 24)
			ADD_OBJECT(StaticMesh, SlipLeft, 20)
			ADD_OBJECT(StaticMesh, Mantle, 16)
			ADD_OBJECT(StaticMesh, Climb, 12)
			ADD_OBJECT(StaticMesh, LeanRight, 8)
			ADD_OBJECT(StaticMesh, LeanLeft, 4)
			ADD_OBJECT(StaticMesh, Base, 0)
		};
		ADD_STRUCT(ScriptArray<CoverMeshComponent::CoverMeshes>, Meshes, 608)
		ADD_BOOL(bShowWhenNotSelected, 644, 0x1)
		ADD_OBJECT(StaticMesh, Disabled, 640)
		ADD_OBJECT(StaticMesh, AutoAdjustOff, 636)
		ADD_OBJECT(StaticMesh, AutoAdjustOn, 632)
		ADD_STRUCT(Vector, LocationOffset, 620)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
