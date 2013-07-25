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
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventory.DropFrom");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartLocation;
			*(Vector*)(params + 12) = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
