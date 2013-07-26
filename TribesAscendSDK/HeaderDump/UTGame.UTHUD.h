#pragma once
#include "Engine.MaterialInstanceConstant.h"
#include "Core.Object.Color.h"
#include "UTGame.UTHUDBase.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.Font.h"
#include "Engine.Texture2D.h"
#include "Core.Object.LinearColor.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "UTGame.UTWeapon.h"
#include "Engine.MaterialEffect.h"
#include "Engine.Material.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Canvas.h"
#include "Engine.HUD.HudLocalizedMessage.h"
#include "Engine.UIInteraction.h"
#include "Engine.LocalPlayer.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTHUD : public UTHUDBase
	{
	public:
		ADD_OBJECT(Texture2D, AltHudTexture)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, WhiteLinearColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, TeamHUDColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowVehicleArmorCount, 0x40000)
		ADD_VAR(::FloatProperty, TX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TY, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, GoldLinearColor, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, PawnOwner)
		ADD_VAR(::FloatProperty, LastAmmoPickupTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastArmorPickupTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MessageOffset, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsFirstPlayer, 0x80000)
		ADD_STRUCT(::NonArithmeticProperty<Color>, BkgTexColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, BkgTexCoords, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, BkgTexture)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, SilverLinearColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, DMLinearColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, BlueLinearColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, RedLinearColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, AmmoBarColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, THeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BootHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BootWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BootY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BootX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HelmetHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HelmetWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HelmetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HelmetX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ThighHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ThighWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ThighY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ThighX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VestHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VestWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VestY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VestX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DollHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DollWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DollOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DollOffsetX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, PawnDollBGCoords, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlaceMarks, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouHaveLost, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouHaveWon, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FireToRespawnMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeadMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpectatorMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PressFireToBegin, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WaitingForMatch, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WarmupString, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, BlackBackgroundColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, NameplateRight, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, NameplateBubble, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, NameplateCenter, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, NameplateLeft, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NameplateBubbleWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NameplateWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageIndicatorSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, VehiclePosition, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastFragCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FragPulseTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, ScoringPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PowerupTransitionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PowerupYPos, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, PowerupDims, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, MapPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AmmoPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastAmmoCount, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, LastWeapon)
		ADD_VAR(::FloatProperty, AmmoTextOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AmmoTextOffsetX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, AmmoBGCoords, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AmmoBarOffsetY, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, AmmoPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastArmorAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorTextY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorTextX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorIconY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorIconX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorBGOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorBGOffsetX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, ArmorBGCoords, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthTextY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthTextX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthIconY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthIconX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthBGOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthBGOffsetX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthOffsetX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TextureCoordinates>, HealthBGCoords, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DollVisibility, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDollUpdate, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, DollPosition, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, ClockPosition, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, HitEffectMaterialInstance)
		ADD_OBJECT(MaterialEffect, HitEffect)
		ADD_VAR(::FloatProperty, HitEffectFadeTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, MaxHitEffectColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HitEffectIntensity, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FadeParamName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PositionalParamName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeTime, 0xFFFFFFFF)
		ADD_OBJECT(Material, BaseMaterial)
		ADD_VAR(::IntProperty, MaxNoOfIndicators, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FullHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FullWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SafeRegionPct, 0xFFFFFFFF)
		ADD_OBJECT(Weapon, LastSelectedWeapon)
		ADD_VAR(::FloatProperty, OrderUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DisplayedOrders, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MapDefaultSize, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, MapBackground)
		ADD_VAR(::FloatProperty, LastWeaponBarDrawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelectedWeaponAmmoOffsetX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponAmmoOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponAmmoOffsetX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponAmmoThickness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponAmmoLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponYOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponYScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelectedBoxScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponXOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBarXOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponScaleSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BouncedWeapon, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHUDUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmptyWeaponAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffWeaponAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelectedWeaponAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BounceWeaponScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SelectedWeaponScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentWeaponScale, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, WeaponList)
		ADD_VAR(::FloatProperty, WeaponBarY, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, TeamTextColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HUDScaleY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HUDScaleX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBoxHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBoxWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBarScale, 0xFFFFFFFF)
		ADD_OBJECT(UTPlayerReplicationInfo, CharPendingPRI)
		ADD_OBJECT(UTPlayerReplicationInfo, CharPRI)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, CharPortraitSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharPortraitSlideTransitionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharPortraitSlideTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharPortraitTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharPortraitXPerc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CharPortraitYPerc, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, CharPortraitMI)
		ADD_OBJECT(Material, CharPortraitMaterial)
		ADD_VAR(::BoolProperty, bShowVehicle, 0x20000)
		ADD_VAR(::BoolProperty, bShowLeaderboard, 0x10000)
		ADD_VAR(::BoolProperty, bHasLeaderboard, 0x8000)
		ADD_VAR(::BoolProperty, bShowFragCount, 0x4000)
		ADD_VAR(::BoolProperty, bShowScoring, 0x2000)
		ADD_VAR(::BoolProperty, bDisplayingPowerups, 0x1000)
		ADD_VAR(::BoolProperty, bShowPowerups, 0x800)
		ADD_VAR(::BoolProperty, bShowMap, 0x400)
		ADD_VAR(::BoolProperty, bHasMap, 0x200)
		ADD_VAR(::BoolProperty, bShowAmmo, 0x100)
		ADD_VAR(::BoolProperty, bShowDoll, 0x80)
		ADD_VAR(::BoolProperty, bShowClock, 0x40)
		ADD_VAR(::BoolProperty, bFadeOutHitEffect, 0x20)
		ADD_VAR(::BoolProperty, bNoWeaponNumbers, 0x10)
		ADD_VAR(::BoolProperty, bOnlyShowWeaponBarIfChanging, 0x8)
		ADD_VAR(::BoolProperty, bShowWeaponbar, 0x4)
		ADD_VAR(::BoolProperty, bHudMessageRendered, 0x2)
		ADD_VAR(::BoolProperty, bShowAllAI, 0x1)
		ADD_OBJECT(UTPlayerReplicationInfo, UTOwnerPRI)
		ADD_OBJECT(UTPawn, UTPawnOwner)
		ADD_VAR(::FloatProperty, LastHealthPickupTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, GrayColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, LC_White, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, UT3GHudTexture)
		ADD_OBJECT(Texture2D, TalkingTexture)
		ADD_OBJECT(ScriptClass, WeaponSwitchMessage)
		void DrawTileCentered(class Texture2D* Tex, float XL, float YL, float U, float V, float UL, float VL, LinearColor C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawTileCentered");
			byte* params = (byte*)malloc(44);
			*(class Texture2D**)params = Tex;
			*(float*)(params + 4) = XL;
			*(float*)(params + 8) = YL;
			*(float*)(params + 12) = U;
			*(float*)(params + 16) = V;
			*(float*)(params + 20) = UL;
			*(float*)(params + 24) = VL;
			*(LinearColor*)(params + 28) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDisplayedOrders(ScriptArray<wchar_t> OrderText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.SetDisplayedOrders");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = OrderText;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Message(class PlayerReplicationInfo* PRI, ScriptArray<wchar_t> msg, ScriptName MsgType, float Lifetime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.Message");
			byte* params = (byte*)malloc(28);
			*(class PlayerReplicationInfo**)params = PRI;
			*(ScriptArray<wchar_t>*)(params + 4) = msg;
			*(ScriptName*)(params + 16) = MsgType;
			*(float*)(params + 24) = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector2D ResolveHUDPosition(Vector2D Position, float Width, float Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.ResolveHUDPosition");
			byte* params = (byte*)malloc(24);
			*(Vector2D*)params = Position;
			*(float*)(params + 8) = Width;
			*(float*)(params + 12) = Height;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector2D*)(params + 16);
			free(params);
			return returnVal;
		}
		void GetScreenCoords(float PosY, float& ScreenX, float& ScreenY, HudLocalizedMessage& InMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.GetScreenCoords");
			byte* params = (byte*)malloc(76);
			*(float*)params = PosY;
			*(float*)(params + 4) = ScreenX;
			*(float*)(params + 8) = ScreenY;
			*(HudLocalizedMessage*)(params + 12) = InMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ScreenX = *(float*)(params + 4);
			ScreenY = *(float*)(params + 8);
			InMessage = *(HudLocalizedMessage*)(params + 12);
			free(params);
		}
		void DrawMessageText(HudLocalizedMessage LocalMessage, float ScreenX, float ScreenY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawMessageText");
			byte* params = (byte*)malloc(72);
			*(HudLocalizedMessage*)params = LocalMessage;
			*(float*)(params + 64) = ScreenX;
			*(float*)(params + 68) = ScreenY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawGameHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawGameHud");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawMicIcon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawMicIcon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayLocalMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayLocalMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawLivingHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawLivingHud");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawPostGameHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawPostGameHud");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayWeaponBar()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayWeaponBar");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayMap");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawAIOverlays()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawAIOverlays");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UIInteraction* GetUIController(class LocalPlayer*& LP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.GetUIController");
			byte* params = (byte*)malloc(8);
			*(class LocalPlayer**)params = LP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			LP = *(class LocalPlayer**)params;
			auto returnVal = *(class UIInteraction**)(params + 4);
			free(params);
			return returnVal;
		}
		void StartMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.StartMusic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetTeamColor(int TeamIndex, LinearColor& ImageColor, Color& TextColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.GetTeamColor");
			byte* params = (byte*)malloc(24);
			*(int*)params = TeamIndex;
			*(LinearColor*)(params + 4) = ImageColor;
			*(Color*)(params + 20) = TextColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ImageColor = *(LinearColor*)(params + 4);
			TextColor = *(Color*)(params + 20);
			free(params);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayHit");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitDir;
			*(int*)(params + 12) = Damage;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlashDamage(float FlashPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.FlashDamage");
			byte* params = (byte*)malloc(4);
			*(float*)params = FlashPosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.UpdateDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawBackground(float X, float Y, float Width, float Height, LinearColor DrawColor, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawBackground");
			byte* params = (byte*)malloc(36);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			*(float*)(params + 8) = Width;
			*(float*)(params + 12) = Height;
			*(LinearColor*)(params + 16) = DrawColor;
			*(class Canvas**)(params + 32) = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawBeaconBackground(float X, float Y, float Width, float Height, LinearColor DrawColor, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawBeaconBackground");
			byte* params = (byte*)malloc(36);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			*(float*)(params + 8) = Width;
			*(float*)(params + 12) = Height;
			*(LinearColor*)(params + 16) = DrawColor;
			*(class Canvas**)(params + 32) = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawHealth(float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas, byte Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawHealth");
			byte* params = (byte*)malloc(25);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			*(float*)(params + 8) = Width;
			*(float*)(params + 12) = MaxWidth;
			*(float*)(params + 16) = Height;
			*(class Canvas**)(params + 20) = DrawCanvas;
			*(params + 24) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawBarGraph(float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas, Color BarColor, Color BackColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawBarGraph");
			byte* params = (byte*)malloc(32);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			*(float*)(params + 8) = Width;
			*(float*)(params + 12) = MaxWidth;
			*(float*)(params + 16) = Height;
			*(class Canvas**)(params + 20) = DrawCanvas;
			*(Color*)(params + 24) = BarColor;
			*(Color*)(params + 28) = BackColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		class Font* GetFontSizeIndex(int FontSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.GetFontSizeIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = FontSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)(params + 4);
			free(params);
			return returnVal;
		}
		void ShowPortrait(class UTPlayerReplicationInfo* ShowPRI, float PortraitDuration, bool bOverrideCurrentSpeaker)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.ShowPortrait");
			byte* params = (byte*)malloc(12);
			*(class UTPlayerReplicationInfo**)params = ShowPRI;
			*(float*)(params + 4) = PortraitDuration;
			*(bool*)(params + 8) = bOverrideCurrentSpeaker;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HidePortrait()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.HidePortrait");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayPortrait(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayPortrait");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayHUDMessage(ScriptArray<wchar_t> Message, float XOffsetPct, float YOffsetPct)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayHUDMessage");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = Message;
			*(float*)(params + 12) = XOffsetPct;
			*(float*)(params + 16) = YOffsetPct;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayClock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayClock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayPawnDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayPawnDoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayAmmo(class UTWeapon* Weapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayAmmo");
			byte* params = (byte*)malloc(4);
			*(class UTWeapon**)params = Weapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayPowerups()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayPowerups");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayScoring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayScoring");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayFragCount(Vector2D pos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayFragCount");
			byte* params = (byte*)malloc(8);
			*(Vector2D*)params = pos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawNameplateBackground(Vector2D pos, float WordWidth, LinearColor NameplateColor, float WordHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawNameplateBackground");
			byte* params = (byte*)malloc(32);
			*(Vector2D*)params = pos;
			*(float*)(params + 8) = WordWidth;
			*(LinearColor*)(params + 12) = NameplateColor;
			*(float*)(params + 28) = WordHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayLeaderBoard(Vector2D pos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayLeaderBoard");
			byte* params = (byte*)malloc(8);
			*(Vector2D*)params = pos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayConsoleMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayConsoleMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
