#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Engine.ApexGenericAsset.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleTypeDataApex : public ParticleModuleTypeDataBase
	{
	public:
		ADD_OBJECT(ApexGenericAsset, ApexEmitter, 76)
		ADD_OBJECT(ApexGenericAsset, ApexIOFX, 72)
	};
}
#undef ADD_OBJECT
