#pragma once
#include "Engine.Volume.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TestSplittingVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TestSplittingVolume : public Volume
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IInterface_NavMeshPathObject, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
