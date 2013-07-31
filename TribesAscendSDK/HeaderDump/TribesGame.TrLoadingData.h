#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrLoadingData : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, CTFTips, 204)
		ADD_STRUCT(ScriptArray<ScriptString*>, TDMTips, 216)
		ADD_STRUCT(ScriptArray<ScriptString*>, RabbitTips, 228)
		ADD_STRUCT(ScriptArray<ScriptString*>, ArenaTips, 240)
		ADD_STRUCT(ScriptArray<ScriptString*>, GenericTips, 252)
		ADD_STRUCT(ScriptArray<ScriptString*>, CaHTips, 264)
		ADD_STRUCT(ScriptString*, RulesForBlitz, 192)
		ADD_STRUCT(ScriptString*, RulesForCaH, 180)
		ADD_STRUCT(ScriptString*, RulesForDaD, 168)
		ADD_STRUCT(ScriptString*, RulesForArena, 156)
		ADD_STRUCT(ScriptString*, RulesForRabbit, 144)
		ADD_STRUCT(ScriptString*, RulesForTDM, 132)
		ADD_STRUCT(ScriptString*, RulesForCTF, 120)
		ADD_STRUCT(ScriptString*, GameType, 108)
		ADD_STRUCT(ScriptString*, MapName, 96)
		ADD_STRUCT(ScriptString*, MapURL, 84)
		ADD_STRUCT(ScriptString*, Rules, 72)
		ADD_STRUCT(ScriptString*, Tip, 60)
		ScriptString* GetRandomTip(int GameIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98606);
			byte params[16] = { NULL };
			*(int*)params = GameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98609);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDataFields()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98610);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
