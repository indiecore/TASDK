#pragma once
#include "Core__Object.h"
#include "Engine__IniLocPatcher.h"
#include "Engine__OnlineGameSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineSubsystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineSubsystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.OnlineSubsystem." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystem : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FTickableObject'!
		ADD_VAR(::StrProperty, IniLocPatcherClassName, 0xFFFFFFFF)
		ADD_OBJECT(IniLocPatcher, Patcher)
		ADD_VAR(::BoolProperty, bUseBuildIdOverride, 0x1)
		ADD_VAR(::IntProperty, BuildIdOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AsyncMinCompletionTime, 0xFFFFFFFF)
		void SetDebugSpewLevel(int DebugSpewLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetDebugSpewLevel");
			byte* params = (byte*)malloc(4);
			*(int*)params = DebugSpewLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DumpVoiceRegistration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.DumpVoiceRegistration");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpSessionState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.DumpSessionState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DumpGameSettings(class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.DumpGameSettings");
			byte* params = (byte*)malloc(4);
			*(class OnlineGameSettings**)params = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetNumSupportedLogins()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.GetNumSupportedLogins");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetBuildUniqueId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.GetBuildUniqueId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool StringToUniqueNetId(ScriptArray<wchar_t> UniqueNetIdString, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void*& out_UniqueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.StringToUniqueNetId");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = UniqueNetIdString;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 12) = out_UniqueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_UniqueId = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> UniqueNetIdToString(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void*& IdToConvert)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.UniqueNetIdToString");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = IdToConvert;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			IdToConvert = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		class Object* GetNamedInterface(ScriptName InterfaceName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.GetNamedInterface");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InterfaceName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Object**)(params + 8);
			free(params);
			return returnVal;
		}
		void SetNamedInterface(ScriptName InterfaceName, class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetNamedInterface");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InterfaceName;
			*(class Object**)(params + 8) = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetGameChatInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetGameChatInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetTitleFileInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetTitleFileInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetPartyChatInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetPartyChatInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetNewsInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetNewsInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetStatsInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetStatsInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetVoiceInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetVoiceInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetContentInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetContentInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetGameInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetGameInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetSystemInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetSystemInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetPlayerInterfaceEx(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetPlayerInterfaceEx");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetPlayerInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetPlayerInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetAccountInterface(class Object* NewInterface)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.SetAccountInterface");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = NewInterface;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Exit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.Exit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PostInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.PostInit");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSubsystem.Init");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
