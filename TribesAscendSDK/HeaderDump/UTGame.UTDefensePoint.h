#pragma once
#include "UTGame.UTBot.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "UDKBase.UDKScriptedNavigationPoint.h"
#include "UDKBase.UDKGameObjective.h"
#include "Engine.Texture2D.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTDefensePoint : public UDKScriptedNavigationPoint
	{
	public:
		enum EDefensePriority : byte
		{
			DEFPRI_Low = 0,
			DEFPRI_High = 1,
			DEFPRI_MAX = 2,
		};
		ADD_OBJECT(ScriptClass, WeaponPreference, 712)
		ADD_BOOL(bSniping, 708, 0x2)
		ADD_BOOL(bFirstScript, 708, 0x1)
		ADD_OBJECT(UDKGameObjective, DefendedObjective, 704)
		ADD_BOOL(bOnlyOnFoot, 708, 0x4)
		ADD_STRUCT(ScriptName, DefenseGroup, 716)
		ADD_OBJECT(UTDefensePoint, NextDefensePoint, 700)
		ADD_OBJECT(Controller, CurrentUser, 696)
		ADD_STRUCT(ScriptArray<class Texture2D*>, TeamSprites, 728)
		ADD_STRUCT(UTDefensePoint::EDefensePriority, DefensePriority, 724)
		ADD_BOOL(bOnlySkilled, 708, 0x8)
		class Actor* GetMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.GetMoveTarget");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		bool HigherPriorityThan(class UTDefensePoint* S, class UTBot* B, bool bAutoPointsInUse, bool bPrioritizeSameGroup, int& NumChecked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.HigherPriorityThan");
			byte params[24] = { NULL };
			*(class UTDefensePoint**)&params[0] = S;
			*(class UTBot**)&params[4] = B;
			*(bool*)&params[8] = bAutoPointsInUse;
			*(bool*)&params[12] = bPrioritizeSameGroup;
			*(int*)&params[16] = NumChecked;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NumChecked = *(int*)&params[16];
			return *(bool*)&params[20];
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDefensePoint.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
