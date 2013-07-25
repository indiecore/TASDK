#pragma once
#include "UDKBase__UDKScriptedNavigationPoint.h"
#include "Engine__Actor.h"
#include "UDKBase__UDKGameObjective.h"
#include "Engine__Controller.h"
#include "UTGame__UTBot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDefensePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDefensePoint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDefensePoint : public UDKScriptedNavigationPoint
	{
	public:
		ADD_OBJECT(ScriptClass, WeaponPreference)
		ADD_VAR(::BoolProperty, bSniping, 0x2)
		ADD_VAR(::BoolProperty, bFirstScript, 0x1)
		ADD_OBJECT(UDKGameObjective, DefendedObjective)
		ADD_VAR(::BoolProperty, bOnlyOnFoot, 0x4)
		ADD_VAR(::NameProperty, DefenseGroup, 0xFFFFFFFF)
		ADD_OBJECT(UTDefensePoint, NextDefensePoint)
		ADD_OBJECT(Controller, CurrentUser)
		ADD_VAR(::ByteProperty, DefensePriority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOnlySkilled, 0x8)
		class Actor* GetMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.GetMoveTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		bool HigherPriorityThan(class UTDefensePoint* S, class UTBot* B, bool bAutoPointsInUse, bool bPrioritizeSameGroup, int& NumChecked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.HigherPriorityThan");
			byte* params = (byte*)malloc(24);
			*(class UTDefensePoint**)params = S;
			*(class UTBot**)(params + 4) = B;
			*(bool*)(params + 8) = bAutoPointsInUse;
			*(bool*)(params + 12) = bPrioritizeSameGroup;
			*(int*)(params + 16) = NumChecked;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NumChecked = *(int*)(params + 16);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FreePoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.FreePoint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckForErrors()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.CheckForErrors");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
