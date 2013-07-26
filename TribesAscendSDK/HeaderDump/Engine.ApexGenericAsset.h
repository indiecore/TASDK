#pragma once
#include "Engine.ApexAsset.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ApexGenericAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexGenericAsset : public ApexAsset
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, MApexAsset, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
