#pragma once
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "Engine.UIDataStore_OnlineGameSettings.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
#include "UTGame.UTUIDataStore_StringList.h"
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
	class GFxUDKFrontEnd_LaunchGame : public GFxUDKFrontEnd_Screen
	{
	public:
		static const float MarkupForNoMapImage;
		struct Option
		{
		public:
			ADD_STRUCT(ScriptString*, OptionDesc, 24)
			ADD_STRUCT(ScriptString*, OptionLabel, 12)
			ADD_STRUCT(ScriptString*, OptionName, 0)
		};
		ADD_STRUCT(ScriptArray<GFxUDKFrontEnd_LaunchGame::Option>, ListOptions, 292)
		ADD_OBJECT(GFxObject, MutatorsLabelTxt, 380)
		ADD_OBJECT(GFxObject, RespawnLabelTxt, 376)
		ADD_OBJECT(GFxObject, TimeLabelTxt, 372)
		ADD_OBJECT(GFxObject, ScoreLabelTxt, 368)
		ADD_OBJECT(GFxObject, OpponentsLabelTxt, 364)
		ADD_OBJECT(GFxObject, BotLvlLabelTxt, 360)
		ADD_OBJECT(GFxObject, MapLabelTxt, 356)
		ADD_OBJECT(GFxObject, MutatorsTxt, 352)
		ADD_OBJECT(GFxObject, RespawnTxt, 348)
		ADD_OBJECT(GFxObject, MapTxt, 344)
		ADD_OBJECT(GFxObject, TimeTxt, 340)
		ADD_OBJECT(GFxObject, ScoreTxt, 336)
		ADD_OBJECT(GFxObject, OpponentsTxt, 332)
		ADD_OBJECT(GFxObject, BotLvlTxt, 328)
		ADD_OBJECT(GFxObject, GameTitleTxt, 324)
		ADD_OBJECT(GFxObject, MapNameTxt, 320)
		ADD_OBJECT(GFxObject, MapImageMC, 316)
		ADD_OBJECT(GFxObject, MenuMC, 312)
		ADD_OBJECT(GFxObject, ListDataProvider, 308)
		ADD_OBJECT(GFxClikWidget, ListMC, 304)
		ADD_STRUCT(ScriptString*, DefaultGameModePrefixes, 280)
		ADD_STRUCT(ScriptString*, DefaultMapImage, 268)
		ADD_STRUCT(ScriptString*, DefaultGameModeSettings, 256)
		ADD_STRUCT(ScriptString*, DefaultGameMode, 244)
		ADD_STRUCT(ScriptString*, DefaultMapName, 232)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore, 228)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore, 224)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore, 220)
		ScriptString* GetGameModeFriendlyString(ScriptString* InGameMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38192);
			byte params[24] = { NULL };
			*(ScriptString**)params = InGameMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38240);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38242);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38248);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38250);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameSettingsPanel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38252);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayOpenAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38253);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCloseAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38254);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartGame_Confirm()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38255);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnListItemPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38263);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListChange(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38267);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38269);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38272);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38278);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		ScriptString* GetStringFromMarkup(ScriptString* MarkupString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38284);
			byte params[24] = { NULL };
			*(ScriptString**)params = MarkupString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
	};
	const float GFxUDKFrontEnd_LaunchGame::MarkupForNoMapImage = "UDKFrontEnd.gm_map_none"f;
}
#undef ADD_STRUCT
#undef ADD_OBJECT
