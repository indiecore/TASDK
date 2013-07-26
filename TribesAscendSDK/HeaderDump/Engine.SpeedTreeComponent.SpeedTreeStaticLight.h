#pragma once
#include "Core.Object.Guid.h"
#include "Engine.ShadowMap1D.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SpeedTreeComponent.SpeedTreeStaticLight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SpeedTreeComponent.SpeedTreeStaticLight." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SpeedTreeStaticLight
	{
	public:
		ADD_OBJECT(ShadowMap1D, BillboardShadowMap)
		ADD_OBJECT(ShadowMap1D, LeafCardShadowMap)
		ADD_OBJECT(ShadowMap1D, LeafMeshShadowMap)
		ADD_OBJECT(ShadowMap1D, FrondShadowMap)
		ADD_OBJECT(ShadowMap1D, BranchShadowMap)
		ADD_STRUCT(::NonArithmeticProperty<Guid>, Guid, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
