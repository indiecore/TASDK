#pragma once
#include "UTGame__UTInventory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrInventory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrInventory : public UTInventory
	{
	public:
		ADD_VAR(::FloatProperty, m_fMaxPickupSpeed, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'DropFrom'
	};
}
#undef ADD_VAR
