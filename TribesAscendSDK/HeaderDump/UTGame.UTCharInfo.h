#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTCharInfo : public Object
	{
	public:
		struct CustomAIData
		{
		public:
			ADD_STRUCT(ScriptString*, FavoriteWeapon, 28)
			ADD_STRUCT(float, ReactionTime, 24)
			ADD_STRUCT(float, Jumpiness, 20)
			ADD_STRUCT(float, CombatStyle, 16)
			ADD_STRUCT(float, Aggressiveness, 12)
			ADD_STRUCT(float, Accuracy, 8)
			ADD_STRUCT(float, StrafingAbility, 4)
			ADD_STRUCT(float, Tactics, 0)
		};
		struct CharacterInfo
		{
		public:
			ADD_STRUCT(UTCharInfo::CustomAIData, AIData, 72)
			ADD_STRUCT(ScriptString*, Faction, 60)
			ADD_STRUCT(ScriptString*, PreviewImageMarkup, 48)
			ADD_STRUCT(ScriptString*, Description, 36)
			ADD_STRUCT(ScriptString*, CharName, 24)
			ADD_STRUCT(ScriptString*, FamilyID, 12)
			ADD_STRUCT(ScriptString*, CharID, 0)
		};
		ADD_STRUCT(ScriptArray<UTCharInfo::CharacterInfo>, Characters, 60)
		ADD_STRUCT(ScriptArray<ScriptClass*>, Families, 72)
		ADD_STRUCT(float, LOD3DisplayFactor, 92)
		ADD_STRUCT(float, LOD2DisplayFactor, 88)
		ADD_STRUCT(float, LOD1DisplayFactor, 84)
		ScriptClass* FindFamilyInfo(ScriptString* InFamilyID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42761);
			byte params[16] = { NULL };
			*(ScriptString**)params = InFamilyID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[12];
		}
		ScriptString* GetRandomCharClassName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43892);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_STRUCT
