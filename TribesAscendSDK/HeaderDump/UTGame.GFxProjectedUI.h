#pragma once
#include "UTGame.UTGFxTweenableMoviePlayer.h"
#include "UTGame.GFxUI_InventoryButton.h"
#include "GFxUI.GFxObject.h"
#include "Core.Object.h"
#include "GFxUI.GFxClikWidget.h"
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
	class GFxProjectedUI : public UTGFxTweenableMoviePlayer
	{
	public:
		class ItemData
		{
		public:
			ADD_STRUCT(byte, ItemFrame, 24)
			ADD_STRUCT(ScriptString*, ItemName, 12)
			ADD_STRUCT(ScriptString*, ItemInfo, 0)
		};
		ADD_STRUCT(ScriptArray<class GFxUI_InventoryButton*>, Buttons, 412)
		ADD_STRUCT(ScriptArray<GFxProjectedUI::ItemData>, Items, 424)
		ADD_STRUCT(ScriptString*, CancelString, 644)
		ADD_STRUCT(ScriptString*, AcceptString, 632)
		ADD_STRUCT(Object::Rotator, StartRotation, 620)
		ADD_OBJECT(ScriptClass, WeaponClass, 576)
		ADD_STRUCT(float, leftThreshold, 572)
		ADD_STRUCT(float, rightThreshold, 568)
		ADD_STRUCT(float, rotval, 564)
		ADD_STRUCT(float, Height, 560)
		ADD_STRUCT(float, Width, 556)
		ADD_STRUCT(float, Scale, 552)
		ADD_OBJECT(GFxObject, InfoTitle, 548)
		ADD_OBJECT(GFxObject, InfoText, 544)
		ADD_OBJECT(GFxObject, InfoIconItem, 540)
		ADD_OBJECT(GFxObject, InfoIconWeap, 536)
		ADD_OBJECT(GFxObject, InfoMC, 532)
		ADD_OBJECT(GFxObject, BG_Edge_RightBottom, 528)
		ADD_OBJECT(GFxObject, BG_Edge_RightMiddle, 524)
		ADD_OBJECT(GFxObject, BG_Edge_RightTop, 520)
		ADD_OBJECT(GFxObject, BG_Edge_LeftTop, 516)
		ADD_OBJECT(GFxObject, BG_Edge_LeftMiddle, 512)
		ADD_OBJECT(GFxObject, BG_Edge_LeftBottom, 508)
		ADD_OBJECT(GFxObject, BG_Optic4MC, 504)
		ADD_OBJECT(GFxObject, BG_Optic3MC, 500)
		ADD_OBJECT(GFxObject, BG_Optic2MC, 496)
		ADD_OBJECT(GFxObject, BG_Optic1MC, 492)
		ADD_OBJECT(GFxObject, BG_ArrowMC, 488)
		ADD_OBJECT(GFxObject, BG_LineMC, 484)
		ADD_OBJECT(GFxObject, StartUpTextMC, 480)
		ADD_OBJECT(GFxObject, CPCLogoMC, 476)
		ADD_OBJECT(GFxObject, BackgroundMC, 472)
		ADD_OBJECT(GFxObject, LeftArrow01, 468)
		ADD_OBJECT(GFxObject, LeftArrow02, 464)
		ADD_OBJECT(GFxObject, ArsenalTabMC, 460)
		ADD_OBJECT(GFxObject, BackpackTabMC, 456)
		ADD_BOOL(bInitialized, 452, 0x2)
		ADD_BOOL(bArsenalTabFocused, 452, 0x1)
		ADD_OBJECT(GFxObject, EquippedWeaponText2, 448)
		ADD_OBJECT(GFxObject, EquippedWeaponText1, 444)
		ADD_OBJECT(GFxObject, EquippedWeaponOutline, 440)
		ADD_OBJECT(GFxObject, EquippedWeapon, 436)
		ADD_OBJECT(GFxObject, ArsenalMC, 408)
		ADD_OBJECT(GFxObject, BackpackMC, 404)
		ADD_OBJECT(GFxObject, MainMC, 400)
		ADD_OBJECT(GFxObject, Window, 396)
		ADD_OBJECT(GFxObject, Root, 392)
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.Start");
			byte params[8] = { NULL };
			*(bool*)&params[0] = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConfigureInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.ConfigureInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCaptureKeys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.AddCaptureKeys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartCloseAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.StartCloseAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnCloseAnimComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnCloseAnimComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBG()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetupBG");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBorder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetupBorder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupArsenal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetupArsenal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBackpack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetupBackpack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetupInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopulateBackpackFake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.PopulateBackpackFake");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupArsenalButtons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetupArsenalButtons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBackpackButtons()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetupBackpackButtons");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchWeapon(byte Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SwitchWeapon");
			byte params[1] = { NULL };
			params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusInSelection(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnFocusInSelection");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusOutSelection(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnFocusOutSelection");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClickWeaponButton(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnClickWeaponButton");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusUpdateInfo(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnFocusUpdateInfo");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusArsenalTab(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnFocusArsenalTab");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusBackpackTab(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnFocusBackpackTab");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClickFakeItem(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.OnClickFakeItem");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInfo(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.SetInfo");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopulateArsenal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.PopulateArsenal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FakeUpdateEquippedWeapon(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.FakeUpdateEquippedWeapon");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateEquippedWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.UpdateEquippedWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessTweenCallback(ScriptString* Callback, class GFxObject* TargetMC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.ProcessTweenCallback");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Callback;
			*(class GFxObject**)&params[12] = TargetMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TweenTurbines(bool Toggle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.TweenTurbines");
			byte params[4] = { NULL };
			*(bool*)&params[0] = Toggle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FloatSelectionUp(class GFxObject* ButtonIconMC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.FloatSelectionUp");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = ButtonIconMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FloatSelectionDown(class GFxObject* ButtonIconMC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.FloatSelectionDown");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = ButtonIconMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePos()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.UpdatePos");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateItemData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxProjectedUI.CreateItemData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
