#pragma once
#include "TribesGame__TrProj_Mine.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_ArmoredClaymore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_ArmoredClaymore : public TrProj_Mine
	{
	public:
		ADD_VAR(::FloatProperty, DetonationSpeed, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'MeetsDetonationRequirements'
	};
}
#undef ADD_VAR
