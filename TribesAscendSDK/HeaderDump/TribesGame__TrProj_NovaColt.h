#pragma once
#include "TribesGame__TrProjectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_NovaColt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_NovaColt : public TrProjectile
	{
	public:
		ADD_VAR(::IntProperty, m_nNumberBounces, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nBouncesAllowed, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
