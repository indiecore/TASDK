#pragma once
#include "TribesGame.TrObject.h"
#include "GFxUI.GFxObject.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrFriendManager : public TrObject
	{
	public:
		enum EOnlineState : byte
		{
			EOS_OFFLINE = 0,
			EOS_ONLINE = 1,
			EOS_INGAME = 2,
			EOS_MAX = 3,
		};
		class FriendStruct
		{
		public:
			ADD_STRUCT(ScriptString*, PlayerName, 4)
			ADD_STRUCT(TrFriendManager::EOnlineState, OnlineState, 16)
			ADD_STRUCT(int, PlayerID, 0)
		};
		ADD_BOOL(AddFriendSuccess, 72, 0x1)
		ADD_STRUCT(ScriptString*, RecentlyAddedFriend, 76)
		ADD_STRUCT(ScriptArray<TrFriendManager::FriendStruct>, FriendsList, 96)
		ADD_STRUCT(ScriptArray<TrFriendManager::FriendStruct>, FollowersList, 108)
		ADD_STRUCT(ScriptArray<TrFriendManager::FriendStruct>, IgnoredList, 120)
		ADD_OBJECT(GFxObject, GFxList, 92)
		ADD_STRUCT(int, GFxCount, 88)
		ADD_STRUCT(int, PrevBlockedCount, 68)
		ADD_STRUCT(int, PrevFollowerCount, 64)
		ADD_STRUCT(int, PrevFriendCount, 60)
		void RequestFriendsList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.RequestFriendsList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFriend(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.AddFriend");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool JoinFriend(ScriptString* PlayerName, ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.JoinFriend");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void IgnoreFriend(ScriptString* PlayerName, bool bIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.IgnoreFriend");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(bool*)&params[12] = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFriend(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.RemoveFriend");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Update()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.Update");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromList(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.RemoveFromList");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetOnlineFriendCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetOnlineFriendCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetInGameFriendCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetInGameFriendCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetOnlineFollowerCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetOnlineFollowerCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool IsFriend(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.IsFriend");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetFriendListIndex(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.GetFriendListIndex");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void AddFriendScoreboard(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFriendManager.AddFriendScoreboard");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
