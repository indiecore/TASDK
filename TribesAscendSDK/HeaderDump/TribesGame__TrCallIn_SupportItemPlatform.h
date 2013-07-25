#pragma once
#include "Engine__Actor.h"
#include "TribesGame__TrGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_SupportItemPlatform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_SupportItemPlatform." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_SupportItemPlatform : public Actor
	{
	public:
		ADD_OBJECT(TrGameObjective, r_DeployedItem)
		ADD_VAR(::ByteProperty, DefenderTeamIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ItemAttachPointName, 0xFFFFFFFF)
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_SupportItemPlatform.GetBoundingCylinder");
			byte* params = (byte*)malloc(8);
			*(float*)params = CollisionRadius;
			*(float*)(params + 4) = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)(params + 4);
			free(params);
		}
		void Init(class Actor* DeployableOwner, ScriptClass* GameObjectiveClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_SupportItemPlatform.Init");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = DeployableOwner;
			*(ScriptClass**)(params + 4) = GameObjectiveClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte ScriptGetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_SupportItemPlatform.ScriptGetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void HideMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_SupportItemPlatform.HideMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_SupportItemPlatform.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
