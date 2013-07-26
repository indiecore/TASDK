#pragma once
#include "Engine.InterpTrackInstProperty.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackInstVectorProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstVectorProp : public InterpTrackInstProperty
	{
	public:
		ADD_STRUCT(::VectorProperty, ResetVector, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VectorProp, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
