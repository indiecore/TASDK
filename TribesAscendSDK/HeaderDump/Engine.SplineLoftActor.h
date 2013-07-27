#pragma once
#include "Engine.SplineActor.h"
#include "Engine.MaterialInterface.h"
#include "Core.Object.h"
#include "Engine.StaticMesh.h"
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
	class SplineLoftActor : public SplineActor
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, SplineMeshComps, 564)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, DeformMeshMaterials, 580)
		ADD_STRUCT(float, MeshMaxDrawDistance, 624)
		ADD_BOOL(bAcceptsLights, 616, 0x2)
		ADD_BOOL(bSmoothInterpRollAndScale, 616, 0x1)
		ADD_STRUCT(Object::Vector2D, Offset, 608)
		ADD_STRUCT(Object::Vector, WorldXDir, 596)
		ADD_STRUCT(float, Roll, 592)
		ADD_OBJECT(StaticMesh, DeformMesh, 576)
		ADD_STRUCT(float, ScaleY, 560)
		ADD_STRUCT(float, ScaleX, 556)
		void ClearLoftMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineLoftActor.ClearLoftMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSplineParams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineLoftActor.UpdateSplineParams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
