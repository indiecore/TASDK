#pragma once
#include "Engine.UIDataProvider_OnlinePlayerDataBase.h"
#include "Core.Object.Pointer.h"
#include "Engine.LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlinePartyChatList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_OnlinePartyChatList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlinePartyChatList : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_VAR(::StrProperty, IsPlayingThisGameCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IsInGameSessionCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IsTalkingCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IsInPartyVoiceCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IsLocalCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NatTypeCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NickNameCol, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementCellProvider, 0xFFFFFFFF)
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePartyChatList.OnRegister");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePartyChatList.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePartyChatList.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshMembersList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePartyChatList.RefreshMembersList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
