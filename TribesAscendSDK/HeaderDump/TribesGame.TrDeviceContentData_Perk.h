#pragma once
#include "TribesGame.TrDeviceContentData.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrDeviceContentData_Perk : public TrDeviceContentData
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, m_PerkMaterial, 92)
	};
}
#undef ADD_OBJECT
