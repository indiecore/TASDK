#pragma once
#include "UTGame__UTPawn.h"
#include "UTGame__UTWeaponAttachment.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTBeamWeaponAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTBeamWeaponAttachment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTBeamWeaponAttachment : public UTWeaponAttachment
	{
	public:
		ADD_VAR(::NameProperty, EndPointParamName, 0xFFFFFFFF)
		ADD_OBJECT(UTPawn, PawnOwner)
		ADD_VAR(::NameProperty, BeamSockets, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, BeamTemplate)
		void AddBeamEmitter()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeaponAttachment.AddBeamEmitter");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideEmitter(int Index, bool bHide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeaponAttachment.HideEmitter");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(bool*)(params + 4) = bHide;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateBeam(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBeamWeaponAttachment.UpdateBeam");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
