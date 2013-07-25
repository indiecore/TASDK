#pragma once
#include "Engine__Actor.h"
#include "Engine__MaterialInstanceConstant.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrStealthResidue." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrStealthResidue : public Actor
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, m_MeshMaterial)
		// Here lies the not-yet-implemented method 'PreBeginPlay'
	};
}
#undef ADD_OBJECT
