#pragma once
#include "Engine.UIDataStore.h"
#include "Engine.UIDynamicFieldProvider.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_Registry : public UIDataStore
	{
	public:
		ADD_OBJECT(UIDynamicFieldProvider, RegistryDataProvider, 120)
		class UIDynamicFieldProvider* GetDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_Registry.GetDataProvider");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIDynamicFieldProvider**)&params[0];
		}
	};
}
#undef ADD_OBJECT
