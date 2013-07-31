#pragma once
#include "Engine.PostProcessEffect.h"
#include "Engine.MaterialInterface.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MaterialEffect : public PostProcessEffect
	{
	public:
		ADD_OBJECT(MaterialInterface, Material, 100)
	};
}
#undef ADD_OBJECT
