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
		struct ItemData
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
		ADD_STRUCT(Rotator, StartRotation, 620)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37640);
			byte params[8] = { NULL };
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConfigureInventory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37643);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCaptureKeys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37648);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartCloseAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37649);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnCloseAnimComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37650);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBG()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37652);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBorder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37653);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupArsenal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37654);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBackpack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37657);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37659);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopulateBackpackFake()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37660);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupArsenalButtons()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37662);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetupBackpackButtons()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37664);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchWeapon(byte Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37666);
			byte params[1] = { NULL };
			*params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusInSelection(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37668);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusOutSelection(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37671);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClickWeaponButton(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37674);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusUpdateInfo(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37677);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusArsenalTab(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37680);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusBackpackTab(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37682);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClickFakeItem(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37684);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInfo(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37688);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopulateArsenal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37691);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FakeUpdateEquippedWeapon(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37693);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateEquippedWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37696);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessTweenCallback(ScriptString* Callback, class GFxObject* TargetMC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37699);
			byte params[16] = { NULL };
			*(ScriptString**)params = Callback;
			*(class GFxObject**)&params[12] = TargetMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TweenTurbines(bool Toggle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37702);
			byte params[4] = { NULL };
			*(bool*)params = Toggle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FloatSelectionUp(class GFxObject* ButtonIconMC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37704);
			byte params[4] = { NULL };
			*(class GFxObject**)params = ButtonIconMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FloatSelectionDown(class GFxObject* ButtonIconMC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37706);
			byte params[4] = { NULL };
			*(class GFxObject**)params = ButtonIconMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePos()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37708);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateItemData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37719);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
