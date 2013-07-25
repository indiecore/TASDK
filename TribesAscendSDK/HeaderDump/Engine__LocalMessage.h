#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "Core__Object.h"
#include "Engine__PlayerController.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LocalMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LocalMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LocalMessage : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bBeep, 0x10)
		ADD_VAR(::FloatProperty, Lifetime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsSpecial, 0x1)
		ADD_VAR(::BoolProperty, bIsUnique, 0x2)
		ADD_VAR(::BoolProperty, bCountInstances, 0x20)
		ADD_VAR(::BoolProperty, bIsPartiallyUnique, 0x4)
		ADD_VAR(::IntProperty, FontSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PosY, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DrawColor'!
		ADD_VAR(::BoolProperty, bIsConsoleMessage, 0x8)
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* GetConsoleColor(class PlayerReplicationInfo* RelatedPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetConsoleColor");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = RelatedPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		bool PartiallyDuplicates(int Switch1, int Switch2, class Object* OptionalObject1, class Object* OptionalObject2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.PartiallyDuplicates");
			byte* params = (byte*)malloc(20);
			*(int*)params = Switch1;
			*(int*)(params + 4) = Switch2;
			*(class Object**)(params + 8) = OptionalObject1;
			*(class Object**)(params + 12) = OptionalObject2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.ClientReceive");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetString");
			byte* params = (byte*)malloc(32);
			*(int*)params = Switch;
			*(bool*)(params + 4) = bPRI1HUD;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 20);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* GetColor(int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetColor");
			byte* params = (byte*)malloc(20);
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		float GetPos(int Switch, class HUD* myHUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetPos");
			byte* params = (byte*)malloc(12);
			*(int*)params = Switch;
			*(class HUD**)(params + 4) = myHUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetFontSize(int Switch, class PlayerReplicationInfo* RelatedPRI1, class PlayerReplicationInfo* RelatedPRI2, class PlayerReplicationInfo* LocalPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetFontSize");
			byte* params = (byte*)malloc(20);
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI1;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI2;
			*(class PlayerReplicationInfo**)(params + 12) = LocalPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		float GetLifeTime(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.GetLifeTime");
			byte* params = (byte*)malloc(8);
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsConsoleMessage(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalMessage.IsConsoleMessage");
			byte* params = (byte*)malloc(8);
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
