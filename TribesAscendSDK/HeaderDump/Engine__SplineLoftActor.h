#pragma once
#include "Engine__SplineActor.h"
#include "Engine__StaticMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SplineLoftActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SplineLoftActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SplineLoftActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SplineLoftActor : public SplineActor
	{
	public:
		ADD_VAR(::FloatProperty, MeshMaxDrawDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAcceptsLights, 0x2)
		ADD_VAR(::BoolProperty, bSmoothInterpRollAndScale, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'Offset'!
		ADD_STRUCT(::VectorProperty, WorldXDir, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Roll, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, DeformMesh)
		ADD_VAR(::FloatProperty, ScaleY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScaleX, 0xFFFFFFFF)
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
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
