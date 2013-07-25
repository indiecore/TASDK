#pragma once
#include "Core.Object.h"
#include "TribesGame.GFxTrMenuMoviePlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrUser." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrUser." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrUser : public Object
	{
	public:
		ADD_VAR(::BoolProperty, m_DidLogin, 0x1)
		ADD_VAR(::IntProperty, m_ClassId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CurrencyName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_SeenNewItemsMain, 0x20)
		ADD_VAR(::StrProperty, m_Username, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_Password, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_ChoseRegion, 0x2)
		ADD_VAR(::BoolProperty, m_ChoseRegion2, 0x4)
		ADD_VAR(::BoolProperty, m_SeenNewBundlesMain, 0x40)
		ADD_OBJECT(GFxTrMenuMoviePlayer, MainMenu)
		ADD_VAR(::StrProperty, m_GameType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_SeenNewGametype, 0x10)
		ADD_VAR(::BoolProperty, m_SeenClanTags, 0x8)
		ADD_VAR(::IntProperty, CurrencyCode, 0xFFFFFFFF)
		bool NeedsToSeeNewItemsClass(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.NeedsToSeeNewItemsClass");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NeedsToSeeNewItemsType(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.NeedsToSeeNewItemsType");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool NeedToSeeNewBundle(int ItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.NeedToSeeNewBundle");
			byte* params = (byte*)malloc(8);
			*(int*)params = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NeedsToSeeClanTags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.NeedsToSeeClanTags");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool NeedToSeeAnyNewItem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.NeedToSeeAnyNewItem");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsFavoriteServer(int ServerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.IsFavoriteServer");
			byte* params = (byte*)malloc(8);
			*(int*)params = ServerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NeedsToSeeNewItem(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.NeedsToSeeNewItem");
			byte* params = (byte*)malloc(8);
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> DecryptPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.DecryptPassword");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> EncryptPassword(ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.EncryptPassword");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void Initialize(class GFxTrMenuMoviePlayer* Movie)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.Initialize");
			byte* params = (byte*)malloc(4);
			*(class GFxTrMenuMoviePlayer**)params = Movie;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveCredentials(ScriptArray<wchar_t> NewUserName, ScriptArray<wchar_t> NewPassword)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SaveCredentials");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = NewUserName;
			*(ScriptArray<wchar_t>*)(params + 12) = NewPassword;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveClassId(int NewClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SaveClassId");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveGameType(ScriptArray<wchar_t> NewGameType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SaveGameType");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = NewGameType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveDidLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SaveDidLogin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SaveChoseRegion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SaveChoseRegion");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewGametype()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SeenNewGametype");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewItemsMain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SeenNewItemsMain");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewBundlesMain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SeenNewBundlesMain");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenClanTags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SeenClanTags");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SeenNewBundle(int ItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SeenNewBundle");
			byte* params = (byte*)malloc(4);
			*(int*)params = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeenNewItemsClass(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SeenNewItemsClass");
			byte* params = (byte*)malloc(4);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeenNewItemsType(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SeenNewItemsType");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NeedsToSeeNewBundle(int ItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.NeedsToSeeNewBundle");
			byte* params = (byte*)malloc(8);
			*(int*)params = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetFavoriteServer(int ServerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrUser.SetFavoriteServer");
			byte* params = (byte*)malloc(4);
			*(int*)params = ServerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
