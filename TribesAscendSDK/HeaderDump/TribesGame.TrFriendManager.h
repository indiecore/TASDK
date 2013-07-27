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
		struct FriendStruct
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57686);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFriend(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57687);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool JoinFriend(ScriptString* PlayerName, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57689);
			byte params[28] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void IgnoreFriend(ScriptString* PlayerName, bool bIgnore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57693);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(bool*)&params[12] = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFriend(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57696);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Update()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57698);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromList(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57703);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetOnlineFriendCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57707);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetInGameFriendCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57712);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetOnlineFollowerCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57716);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool IsFriend(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57720);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetFriendListIndex(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57724);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void AddFriendScoreboard(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57728);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
