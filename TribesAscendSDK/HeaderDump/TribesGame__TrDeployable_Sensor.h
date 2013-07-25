#pragma once
#include "TribesGame__TrDeployable.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployable_Sensor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployable_Sensor : public TrDeployable
	{
	public:
		ADD_VAR(::FloatProperty, m_fDetectionZOffset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
