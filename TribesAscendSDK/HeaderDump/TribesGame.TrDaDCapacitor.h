#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "TribesGame.TrDaDCore.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Texture2D.h"
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
	class TrDaDCapacitor : public TrGameObjective
	{
	public:
		ADD_STRUCT(ScriptString*, StringC, 1404)
		ADD_STRUCT(ScriptString*, StringB, 1392)
		ADD_STRUCT(ScriptString*, StringA, 1380)
		ADD_STRUCT(int, m_CapacitorIndex, 1372)
		ADD_OBJECT(TrDaDCore, m_Core, 1368)
		ADD_STRUCT(float, m_fShieldBarPlacementY, 1364)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldBarMIC, 1360)
		void Init(class TrDaDCore* Core, int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79468);
			byte params[8] = { NULL };
			*(class TrDaDCore**)params = Core;
			*(int*)&params[4] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79471);
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
		ScriptString* GetScreenName(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79486);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79490);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79508);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
