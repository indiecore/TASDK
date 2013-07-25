#pragma once
#include "UTGame.UTMutator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMutator_FriendlyFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTMutator_FriendlyFire : public UTMutator
	{
	public:
		ADD_VAR(::FloatProperty, FriendlyFireScale, 0xFFFFFFFF)
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_FriendlyFire.MutatorIsAllowed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void InitMutator(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_FriendlyFire.InitMutator");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
	};
}
#undef ADD_VAR
