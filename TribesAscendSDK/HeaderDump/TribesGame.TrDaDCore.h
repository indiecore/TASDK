#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "TribesGame.TrDaDShell.h"
#include "TribesGame.TrDaDCoreShield.h"
#include "Engine.MaterialInstanceConstant.h"
#include "TribesGame.TrDaDCapacitor.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
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
	class TrDaDCore : public TrGameObjective
	{
	public:
		ADD_OBJECT(TrDaDShell, m_Shell, 1392)
		ADD_OBJECT(TrDaDCoreShield, m_Shields, 1380)
		ADD_OBJECT(TrDaDCapacitor, m_Capacitors, 1368)
		ADD_STRUCT(float, m_fShieldBarPlacementY, 1364)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldBarMIC, 1360)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79558);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnShield(int ShieldIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79561);
			byte params[4] = { NULL };
			*(int*)params = ShieldIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCapacitorBlownUp(int CapacitorIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79563);
			byte params[4] = { NULL };
			*(int*)params = CapacitorIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCapacitorRestored(int CapacitorIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79568);
			byte params[4] = { NULL };
			*(int*)params = CapacitorIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79570);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCoreDestroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79585);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79586);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCeilPctScore()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79608);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
