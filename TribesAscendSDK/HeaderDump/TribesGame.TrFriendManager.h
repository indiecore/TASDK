#pragma once
#include "TribesGame.TrObject.h"
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrFriendManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrFriendManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrFriendManager : public TrObject
	{
	public:
		ADD_VAR(::BoolProperty, AddFriendSuccess, 0x1)
		ADD_VAR(::StrProperty, RecentlyAddedFriend, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, GFxList)
		ADD_VAR(::IntProperty, GFxCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevBlockedCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevFollowerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevFriendCount, 0xFFFFFFFF)
		void RequestFriendsList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.RequestFriendsList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFriend(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.AddFriend");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool JoinFriend(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.JoinFriend");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void IgnoreFriend(ScriptArray<wchar_t> PlayerName, bool bIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.IgnoreFriend");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(bool*)(params + 12) = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveFriend(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.RemoveFriend");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Update()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.Update");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromList(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.RemoveFromList");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetOnlineFriendCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetOnlineFriendCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetInGameFriendCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetInGameFriendCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetOnlineFollowerCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetOnlineFollowerCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool IsFriend(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.IsFriend");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetFriendListIndex(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetFriendListIndex");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddFriendScoreboard(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.AddFriendScoreboard");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
