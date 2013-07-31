#pragma once
#include "TribesGame.TrGameObjective.h"
#include "Engine.Actor.h"
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
	class TrCallIn_SupportItemPlatform : public Actor
	{
	public:
		ADD_OBJECT(TrGameObjective, r_DeployedItem, 476)
		ADD_STRUCT(byte, DefenderTeamIndex, 496)
		ADD_STRUCT(ScriptName, ItemAttachPointName, 488)
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74134);
			byte params[8] = { NULL };
			*(float*)params = CollisionRadius;
			*(float*)&params[4] = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)&params[4];
		}
		void Init(class Actor* DeployableOwner, ScriptClass* GameObjectiveClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74137);
			byte params[8] = { NULL };
			*(class Actor**)params = DeployableOwner;
			*(ScriptClass**)&params[4] = GameObjectiveClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte ScriptGetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74140);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		void HideMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74142);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74144);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
