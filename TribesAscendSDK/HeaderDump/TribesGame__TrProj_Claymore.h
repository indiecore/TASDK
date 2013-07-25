#pragma once
#include "TribesGame__TrProj_Mine.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Claymore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_Claymore : public TrProj_Mine
	{
	public:
		ADD_VAR(::FloatProperty, m_fScalarAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDetonationAngle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
