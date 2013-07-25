#pragma once
#include "TribesGame.TrDeviceContentData.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeviceContentData_Perk." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeviceContentData_Perk : public TrDeviceContentData
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, m_PerkMaterial)
	};
}
#undef ADD_OBJECT
