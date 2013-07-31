#pragma once
#include "Core.Object.h"
#include "TribesGame.GFxTrMenuMoviePlayer.h"
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
	class TrUser : public Object
	{
	public:
		struct NewItem
		{
		public:
			ADD_STRUCT(int, ItemId, 8)
			ADD_STRUCT(int, Type, 4)
			ADD_STRUCT(int, ClassId, 0)
		};
		ADD_BOOL(m_DidLogin, 80, 0x1)
		ADD_STRUCT(int, m_ClassId, 76)
		ADD_STRUCT(ScriptString*, CurrencyName, 64)
		ADD_BOOL(m_SeenNewItemsMain, 80, 0x20)
		ADD_STRUCT(ScriptString*, m_Username, 96)
		ADD_STRUCT(ScriptString*, m_Password, 108)
		ADD_BOOL(m_ChoseRegion, 80, 0x2)
		ADD_BOOL(m_ChoseRegion2, 80, 0x4)
		ADD_BOOL(m_SeenNewBundlesMain, 80, 0x40)
		ADD_STRUCT(ScriptArray<TrUser::NewItem>, NewItems, 120)
		ADD_STRUCT(ScriptArray<TrUser::NewItem>, NewBundles, 132)
		ADD_STRUCT(ScriptArray<TrUser::NewItem>, SeenNewItems, 144)
		ADD_STRUCT(ScriptArray<int>, FavServers, 156)
		ADD_OBJECT(GFxTrMenuMoviePlayer, MainMenu, 168)
		ADD_STRUCT(ScriptString*, m_GameType, 84)
		ADD_BOOL(m_SeenNewGametype, 80, 0x10)
		ADD_BOOL(m_SeenClanTags, 80, 0x8)
		ADD_STRUCT(int, CurrencyCode, 60)
		bool NeedsToSeeNewItemsClass(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56835);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NeedsToSeeNewItemsType(int ClassId, int Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56851);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool NeedToSeeNewBundle(int ItemId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57849);
			byte params[8] = { NULL };
			*(int*)params = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NeedsToSeeClanTags()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58115);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool NeedToSeeAnyNewItem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58259);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsFavoriteServer(int ServerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58555);
			byte params[8] = { NULL };
			*(int*)params = ServerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NeedsToSeeNewItem(int EquipId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58652);
			byte params[8] = { NULL };
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* DecryptPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59483);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* EncryptPassword(ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113426);
			byte params[24] = { NULL };
			*(ScriptString**)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void Initialize(class GFxTrMenuMoviePlayer* Movie)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113429);
			byte params[4] = { NULL };
			*(class GFxTrMenuMoviePlayer**)params = Movie;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveCredentials(ScriptString* NewUserName, ScriptString* NewPassword)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113431);
			byte params[24] = { NULL };
			*(ScriptString**)params = NewUserName;
			*(ScriptString**)&params[12] = NewPassword;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveClassId(int NewClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113434);
			byte params[4] = { NULL };
			*(int*)params = NewClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveGameType(ScriptString* NewGameType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113436);
			byte params[12] = { NULL };
			*(ScriptString**)params = NewGameType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveDidLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113438);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SaveChoseRegion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113439);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewGametype()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113440);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewItemsMain()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113441);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewBundlesMain()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113442);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenClanTags()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113443);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewBundle(int ItemId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113444);
			byte params[4] = { NULL };
			*(int*)params = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeenNewItemsClass(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113447);
			byte params[4] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeenNewItemsType(int ClassId, int Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113450);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NeedsToSeeNewBundle(int ItemId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113461);
			byte params[8] = { NULL };
			*(int*)params = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetFavoriteServer(int ServerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(113472);
			byte params[4] = { NULL };
			*(int*)params = ServerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
