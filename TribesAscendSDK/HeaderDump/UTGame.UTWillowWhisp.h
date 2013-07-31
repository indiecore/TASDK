#pragma once
#include "UTGame.UTReplicatedEmitter.h"
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTWillowWhisp : public UTReplicatedEmitter
	{
	public:
		static const auto MAX_WAYPOINTS = 15;
		ADD_STRUCT(int, Position, 680)
		ADD_STRUCT(int, NumPoints, 676)
		ADD_STRUCT(Vector, WayPoints, 496)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50418);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50425);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50426);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50428);
			byte params[8] = { NULL };
			*(class ParticleSystem**)params = NewTemplate;
			*(bool*)&params[4] = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartNextPath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50431);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
