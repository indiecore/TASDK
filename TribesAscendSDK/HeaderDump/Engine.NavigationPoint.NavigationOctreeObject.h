#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Box.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " NavigationPoint.NavigationOctreeObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty NavigationPoint.NavigationOctreeObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty NavigationPoint.NavigationOctreeObject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavigationOctreeObject
	{
	public:
		ADD_VAR(::ByteProperty, OwnerType, 0xFFFFFFFF)
		ADD_OBJECT(Object, Owner)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, OctreeNode, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BoxCenter, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Box>, BoundingBox, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
