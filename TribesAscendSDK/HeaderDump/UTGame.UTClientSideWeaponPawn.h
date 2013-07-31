#pragma once
#include "UTGame.UTWeaponPawn.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTClientSideWeaponPawn : public UTWeaponPawn
	{
	public:
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44063);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44064);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44066);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44068);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
