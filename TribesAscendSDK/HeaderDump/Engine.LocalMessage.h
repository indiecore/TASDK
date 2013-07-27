#pragma once
#include "Core.Object.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.PlayerController.h"
#include "Engine.HUD.h"
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
namespace UnrealScript
{
	class LocalMessage : public Object
	{
	public:
		ADD_BOOL(bBeep, 60, 0x10)
		ADD_STRUCT(float, Lifetime, 64)
		ADD_BOOL(bIsSpecial, 60, 0x1)
		ADD_BOOL(bIsUnique, 60, 0x2)
		ADD_BOOL(bCountInstances, 60, 0x20)
		ADD_BOOL(bIsPartiallyUnique, 60, 0x4)
		ADD_STRUCT(int, FontSize, 76)
		ADD_STRUCT(float, PosY, 72)
		ADD_STRUCT(Object::Color, DrawColor, 68)
		ADD_BOOL(bIsConsoleMessage, 60, 0x8)
		Object::Color GetConsoleColor(class PlayerReplicationInfo* RelatedPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetConsoleColor");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = RelatedPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[4];
		}
		bool PartiallyDuplicates(int Switch1, int Switch2, class Object* OptionalObject1, class Object* OptionalObject2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.PartiallyDuplicates");
			byte params[20] = { NULL };
			*(int*)&params[0] = Switch1;
			*(int*)&params[4] = Switch2;
			*(class Object**)&params[8] = OptionalObject1;
			*(class Object**)&params[12] = OptionalObject2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.ClientReceive");
			byte params[20] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetString");
			byte params[32] = { NULL };
			*(int*)&params[0] = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		Object::Color GetColor(int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetColor");
			byte params[20] = { NULL };
			*(int*)&params[0] = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Color*)&params[16];
		}
		float GetPos(int Switch, class HUD* myHUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetPos");
			byte params[12] = { NULL };
			*(int*)&params[0] = Switch;
			*(class HUD**)&params[4] = myHUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		int GetFontSize(int Switch, class PlayerReplicationInfo* RelatedPRI1, class PlayerReplicationInfo* RelatedPRI2, class PlayerReplicationInfo* LocalPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetFontSize");
			byte params[20] = { NULL };
			*(int*)&params[0] = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI2;
			*(class PlayerReplicationInfo**)&params[12] = LocalPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		float GetLifeTime(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetLifeTime");
			byte params[8] = { NULL };
			*(int*)&params[0] = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool IsConsoleMessage(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.IsConsoleMessage");
			byte params[8] = { NULL };
			*(int*)&params[0] = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
