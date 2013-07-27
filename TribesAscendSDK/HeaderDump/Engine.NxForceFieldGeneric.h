#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.h"
#include "Engine.ForceFieldShape.h"
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
	class NxForceFieldGeneric : public NxForceField
	{
	public:
		enum FFG_ForceFieldCoordinates : byte
		{
			FFG_CARTESIAN = 0,
			FFG_SPHERICAL = 1,
			FFG_CYLINDRICAL = 2,
			FFG_TOROIDAL = 3,
			FFG_MAX = 4,
		};
		ADD_STRUCT(Object::Pointer, LinearKernel, 712)
		ADD_STRUCT(float, TorusRadius, 708)
		ADD_STRUCT(Object::Vector, FalloffQuadratic, 696)
		ADD_STRUCT(Object::Vector, FalloffLinear, 684)
		ADD_STRUCT(Object::Vector, Noise, 672)
		ADD_STRUCT(Object::Vector, VelocityTarget, 660)
		ADD_STRUCT(Object::Vector, VelocityMultiplierZ, 648)
		ADD_STRUCT(Object::Vector, VelocityMultiplierY, 636)
		ADD_STRUCT(Object::Vector, VelocityMultiplierX, 624)
		ADD_STRUCT(Object::Vector, PositionTarget, 612)
		ADD_STRUCT(Object::Vector, PositionMultiplierZ, 600)
		ADD_STRUCT(Object::Vector, PositionMultiplierY, 588)
		ADD_STRUCT(Object::Vector, PositionMultiplierX, 576)
		ADD_STRUCT(Object::Vector, Constant, 564)
		ADD_STRUCT(NxForceFieldGeneric::FFG_ForceFieldCoordinates, Coordinates, 560)
		ADD_OBJECT(ForceFieldShape, Shape, 540)
		ADD_STRUCT(float, RoughExtentZ, 556)
		ADD_STRUCT(float, RoughExtentY, 552)
		ADD_STRUCT(float, RoughExtentX, 548)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceFieldGeneric.DoInitRBPhys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
