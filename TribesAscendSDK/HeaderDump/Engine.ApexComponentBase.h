#pragma once
#include "Engine.MeshComponent.h"
#include "Core.Object.Color.h"
#include "Engine.ApexAsset.h"
#include "Core.Object.RenderCommandFence_Mirror.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexComponentBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ApexComponentBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ApexComponentBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ApexComponentBase : public MeshComponent
	{
	public:
		ADD_VAR(::BoolProperty, bAssetChanged, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Color>, WireframeColor, 0xFFFFFFFF)
		ADD_OBJECT(ApexAsset, Asset)
		ADD_STRUCT(::NonArithmeticProperty<RenderCommandFence_Mirror>, ReleaseResourcesFence, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ComponentBaseResources, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
