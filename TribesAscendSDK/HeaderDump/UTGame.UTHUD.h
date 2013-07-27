#pragma once
#include "Engine.MaterialInstanceConstant.h"
#include "UTGame.UTHUDBase.h"
#include "Engine.Texture2D.h"
#include "Engine.Font.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Core.Object.h"
#include "Engine.UIRoot.h"
#include "UTGame.UTWeapon.h"
#include "Engine.MaterialEffect.h"
#include "Engine.Material.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.HUD.h"
#include "Engine.UIInteraction.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Canvas.h"
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
	class UTHUD : public UTHUDBase
	{
	public:
		class DamageInfo
		{
		public:
			ADD_OBJECT(MaterialInstanceConstant, MatConstant, 8)
			ADD_STRUCT(float, FadeValue, 4)
			ADD_STRUCT(float, FadeTime, 0)
		};
		ADD_OBJECT(Texture2D, AltHudTexture, 1528)
		ADD_STRUCT(Object::LinearColor, WhiteLinearColor, 2612)
		ADD_STRUCT(Object::LinearColor, TeamHUDColor, 1664)
		ADD_BOOL(bShowVehicleArmorCount, 1584, 0x40000)
		ADD_STRUCT(float, TX, 2540)
		ADD_STRUCT(float, TY, 2544)
		ADD_STRUCT(Object::LinearColor, GoldLinearColor, 2628)
		ADD_OBJECT(Pawn, PawnOwner, 1572)
		ADD_STRUCT(float, LastAmmoPickupTime, 1560)
		ADD_STRUCT(float, LastArmorPickupTime, 1568)
		ADD_STRUCT(float, MessageOffset, 1844)
		ADD_BOOL(bIsFirstPlayer, 1584, 0x80000)
		ADD_STRUCT(ScriptArray<class Font*>, HudFonts, 1588)
		ADD_STRUCT(ScriptArray<UTHUD::DamageInfo>, DamageData, 1916)
		ADD_STRUCT(Object::Color, BkgTexColor, 2680)
		ADD_STRUCT(UIRoot::TextureCoordinates, BkgTexCoords, 2664)
		ADD_OBJECT(Texture2D, BkgTexture, 2660)
		ADD_STRUCT(Object::LinearColor, SilverLinearColor, 2644)
		ADD_STRUCT(Object::LinearColor, DMLinearColor, 2596)
		ADD_STRUCT(Object::LinearColor, BlueLinearColor, 2580)
		ADD_STRUCT(Object::LinearColor, RedLinearColor, 2564)
		ADD_STRUCT(Object::LinearColor, AmmoBarColor, 2548)
		ADD_STRUCT(float, THeight, 2536)
		ADD_STRUCT(float, BootHeight, 2532)
		ADD_STRUCT(float, BootWidth, 2528)
		ADD_STRUCT(float, BootY, 2524)
		ADD_STRUCT(float, BootX, 2520)
		ADD_STRUCT(float, HelmetHeight, 2516)
		ADD_STRUCT(float, HelmetWidth, 2512)
		ADD_STRUCT(float, HelmetY, 2508)
		ADD_STRUCT(float, HelmetX, 2504)
		ADD_STRUCT(float, ThighHeight, 2500)
		ADD_STRUCT(float, ThighWidth, 2496)
		ADD_STRUCT(float, ThighY, 2492)
		ADD_STRUCT(float, ThighX, 2488)
		ADD_STRUCT(float, VestHeight, 2484)
		ADD_STRUCT(float, VestWidth, 2480)
		ADD_STRUCT(float, VestY, 2476)
		ADD_STRUCT(float, VestX, 2472)
		ADD_STRUCT(float, DollHeight, 2468)
		ADD_STRUCT(float, DollWidth, 2464)
		ADD_STRUCT(float, DollOffsetY, 2460)
		ADD_STRUCT(float, DollOffsetX, 2456)
		ADD_STRUCT(UIRoot::TextureCoordinates, PawnDollBGCoords, 2440)
		ADD_STRUCT(ScriptString*, PlaceMarks, 2392)
		ADD_STRUCT(ScriptString*, YouHaveLost, 2380)
		ADD_STRUCT(ScriptString*, YouHaveWon, 2368)
		ADD_STRUCT(ScriptString*, FireToRespawnMessage, 2356)
		ADD_STRUCT(ScriptString*, DeadMessage, 2344)
		ADD_STRUCT(ScriptString*, SpectatorMessage, 2332)
		ADD_STRUCT(ScriptString*, PressFireToBegin, 2320)
		ADD_STRUCT(ScriptString*, WaitingForMatch, 2308)
		ADD_STRUCT(ScriptString*, WarmupString, 2296)
		ADD_STRUCT(Object::LinearColor, BlackBackgroundColor, 2280)
		ADD_STRUCT(UIRoot::TextureCoordinates, NameplateRight, 2264)
		ADD_STRUCT(UIRoot::TextureCoordinates, NameplateBubble, 2248)
		ADD_STRUCT(UIRoot::TextureCoordinates, NameplateCenter, 2232)
		ADD_STRUCT(UIRoot::TextureCoordinates, NameplateLeft, 2216)
		ADD_STRUCT(float, NameplateBubbleWidth, 2212)
		ADD_STRUCT(float, NameplateWidth, 2208)
		ADD_STRUCT(float, DamageIndicatorSize, 2204)
		ADD_STRUCT(Object::Vector2D, VehiclePosition, 2196)
		ADD_STRUCT(int, LastFragCount, 2192)
		ADD_STRUCT(float, FragPulseTime, 2188)
		ADD_STRUCT(Object::Vector2D, ScoringPosition, 2180)
		ADD_STRUCT(float, PowerupTransitionTime, 2176)
		ADD_STRUCT(float, PowerupYPos, 2172)
		ADD_STRUCT(Object::Vector2D, PowerupDims, 2164)
		ADD_STRUCT(Object::Vector2D, MapPosition, 2156)
		ADD_STRUCT(float, AmmoPulseTime, 2152)
		ADD_STRUCT(int, LastAmmoCount, 2148)
		ADD_OBJECT(UTWeapon, LastWeapon, 2144)
		ADD_STRUCT(float, AmmoTextOffsetY, 2140)
		ADD_STRUCT(float, AmmoTextOffsetX, 2136)
		ADD_STRUCT(UIRoot::TextureCoordinates, AmmoBGCoords, 2120)
		ADD_STRUCT(float, AmmoBarOffsetY, 2116)
		ADD_STRUCT(Object::Vector2D, AmmoPosition, 2108)
		ADD_STRUCT(float, ArmorPulseTime, 2104)
		ADD_STRUCT(int, LastArmorAmount, 2100)
		ADD_STRUCT(float, ArmorTextY, 2096)
		ADD_STRUCT(float, ArmorTextX, 2092)
		ADD_STRUCT(float, ArmorIconY, 2088)
		ADD_STRUCT(float, ArmorIconX, 2084)
		ADD_STRUCT(float, ArmorBGOffsetY, 2080)
		ADD_STRUCT(float, ArmorBGOffsetX, 2076)
		ADD_STRUCT(UIRoot::TextureCoordinates, ArmorBGCoords, 2060)
		ADD_STRUCT(float, HealthPulseTime, 2056)
		ADD_STRUCT(int, LastHealth, 2052)
		ADD_STRUCT(float, HealthTextY, 2048)
		ADD_STRUCT(float, HealthTextX, 2044)
		ADD_STRUCT(float, HealthIconY, 2040)
		ADD_STRUCT(float, HealthIconX, 2036)
		ADD_STRUCT(float, HealthBGOffsetY, 2032)
		ADD_STRUCT(float, HealthBGOffsetX, 2028)
		ADD_STRUCT(float, HealthOffsetX, 2024)
		ADD_STRUCT(UIRoot::TextureCoordinates, HealthBGCoords, 2008)
		ADD_STRUCT(float, DollVisibility, 2004)
		ADD_STRUCT(float, LastDollUpdate, 2000)
		ADD_STRUCT(Object::Vector2D, DollPosition, 1992)
		ADD_STRUCT(Object::Vector2D, ClockPosition, 1984)
		ADD_OBJECT(MaterialInstanceConstant, HitEffectMaterialInstance, 1980)
		ADD_OBJECT(MaterialEffect, HitEffect, 1976)
		ADD_STRUCT(float, HitEffectFadeTime, 1972)
		ADD_STRUCT(Object::LinearColor, MaxHitEffectColor, 1956)
		ADD_STRUCT(float, HitEffectIntensity, 1952)
		ADD_STRUCT(ScriptName, FadeParamName, 1944)
		ADD_STRUCT(ScriptName, PositionalParamName, 1936)
		ADD_STRUCT(float, FadeTime, 1932)
		ADD_OBJECT(Material, BaseMaterial, 1928)
		ADD_STRUCT(int, MaxNoOfIndicators, 1912)
		ADD_STRUCT(float, FullHeight, 1908)
		ADD_STRUCT(float, FullWidth, 1904)
		ADD_STRUCT(float, SafeRegionPct, 1900)
		ADD_OBJECT(Weapon, LastSelectedWeapon, 1896)
		ADD_STRUCT(float, OrderUpdateTime, 1892)
		ADD_STRUCT(ScriptString*, DisplayedOrders, 1880)
		ADD_STRUCT(float, MapDefaultSize, 1876)
		ADD_OBJECT(Texture2D, MapBackground, 1872)
		ADD_STRUCT(float, LastWeaponBarDrawnTime, 1840)
		ADD_STRUCT(float, SelectedWeaponAmmoOffsetX, 1836)
		ADD_STRUCT(float, WeaponAmmoOffsetY, 1832)
		ADD_STRUCT(float, WeaponAmmoOffsetX, 1828)
		ADD_STRUCT(float, WeaponAmmoThickness, 1824)
		ADD_STRUCT(float, WeaponAmmoLength, 1820)
		ADD_STRUCT(float, WeaponYOffset, 1816)
		ADD_STRUCT(float, WeaponYScale, 1812)
		ADD_STRUCT(float, SelectedBoxScale, 1808)
		ADD_STRUCT(float, WeaponXOffset, 1804)
		ADD_STRUCT(float, WeaponBarXOffset, 1800)
		ADD_STRUCT(float, WeaponScaleSpeed, 1796)
		ADD_STRUCT(int, BouncedWeapon, 1792)
		ADD_STRUCT(float, LastHUDUpdateTime, 1788)
		ADD_STRUCT(float, EmptyWeaponAlpha, 1784)
		ADD_STRUCT(float, OffWeaponAlpha, 1780)
		ADD_STRUCT(float, SelectedWeaponAlpha, 1776)
		ADD_STRUCT(float, BounceWeaponScale, 1772)
		ADD_STRUCT(float, SelectedWeaponScale, 1768)
		ADD_STRUCT(float, CurrentWeaponScale, 1728)
		ADD_OBJECT(UTWeapon, WeaponList, 1688)
		ADD_STRUCT(float, WeaponBarY, 1684)
		ADD_STRUCT(Object::Color, TeamTextColor, 1680)
		ADD_STRUCT(float, HUDScaleY, 1660)
		ADD_STRUCT(float, HUDScaleX, 1656)
		ADD_STRUCT(float, WeaponBoxHeight, 1652)
		ADD_STRUCT(float, WeaponBoxWidth, 1648)
		ADD_STRUCT(float, WeaponBarScale, 1644)
		ADD_OBJECT(UTPlayerReplicationInfo, CharPendingPRI, 1640)
		ADD_OBJECT(UTPlayerReplicationInfo, CharPRI, 1636)
		ADD_STRUCT(Object::Vector2D, CharPortraitSize, 1628)
		ADD_STRUCT(float, CharPortraitSlideTransitionTime, 1624)
		ADD_STRUCT(float, CharPortraitSlideTime, 1620)
		ADD_STRUCT(float, CharPortraitTime, 1616)
		ADD_STRUCT(float, CharPortraitXPerc, 1612)
		ADD_STRUCT(float, CharPortraitYPerc, 1608)
		ADD_OBJECT(MaterialInstanceConstant, CharPortraitMI, 1604)
		ADD_OBJECT(Material, CharPortraitMaterial, 1600)
		ADD_BOOL(bShowVehicle, 1584, 0x20000)
		ADD_BOOL(bShowLeaderboard, 1584, 0x10000)
		ADD_BOOL(bHasLeaderboard, 1584, 0x8000)
		ADD_BOOL(bShowFragCount, 1584, 0x4000)
		ADD_BOOL(bShowScoring, 1584, 0x2000)
		ADD_BOOL(bDisplayingPowerups, 1584, 0x1000)
		ADD_BOOL(bShowPowerups, 1584, 0x800)
		ADD_BOOL(bShowMap, 1584, 0x400)
		ADD_BOOL(bHasMap, 1584, 0x200)
		ADD_BOOL(bShowAmmo, 1584, 0x100)
		ADD_BOOL(bShowDoll, 1584, 0x80)
		ADD_BOOL(bShowClock, 1584, 0x40)
		ADD_BOOL(bFadeOutHitEffect, 1584, 0x20)
		ADD_BOOL(bNoWeaponNumbers, 1584, 0x10)
		ADD_BOOL(bOnlyShowWeaponBarIfChanging, 1584, 0x8)
		ADD_BOOL(bShowWeaponbar, 1584, 0x4)
		ADD_BOOL(bHudMessageRendered, 1584, 0x2)
		ADD_BOOL(bShowAllAI, 1584, 0x1)
		ADD_OBJECT(UTPlayerReplicationInfo, UTOwnerPRI, 1580)
		ADD_OBJECT(UTPawn, UTPawnOwner, 1576)
		ADD_STRUCT(float, LastHealthPickupTime, 1564)
		ADD_STRUCT(Object::Color, GrayColor, 1556)
		ADD_STRUCT(Object::LinearColor, LC_White, 1540)
		ADD_OBJECT(Texture2D, UT3GHudTexture, 1536)
		ADD_OBJECT(Texture2D, TalkingTexture, 1532)
		ADD_OBJECT(ScriptClass, WeaponSwitchMessage, 1524)
		void DrawTileCentered(class Texture2D* Tex, float XL, float YL, float U, float V, float UL, float VL, Object::LinearColor C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawTileCentered");
			byte params[44] = { NULL };
			*(class Texture2D**)&params[0] = Tex;
			*(float*)&params[4] = XL;
			*(float*)&params[8] = YL;
			*(float*)&params[12] = U;
			*(float*)&params[16] = V;
			*(float*)&params[20] = UL;
			*(float*)&params[24] = VL;
			*(Object::LinearColor*)&params[28] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDisplayedOrders(ScriptString* OrderText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.SetDisplayedOrders");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = OrderText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Message(class PlayerReplicationInfo* PRI, ScriptString* msg, ScriptName MsgType, float Lifetime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.Message");
			byte params[28] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			*(ScriptString**)&params[4] = msg;
			*(ScriptName*)&params[16] = MsgType;
			*(float*)&params[24] = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector2D ResolveHUDPosition(Object::Vector2D Position, float Width, float Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.ResolveHUDPosition");
			byte params[24] = { NULL };
			*(Object::Vector2D*)&params[0] = Position;
			*(float*)&params[8] = Width;
			*(float*)&params[12] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[16];
		}
		void GetScreenCoords(float PosY, float& ScreenX, float& ScreenY, HUD::HudLocalizedMessage& InMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.GetScreenCoords");
			byte params[76] = { NULL };
			*(float*)&params[0] = PosY;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(HUD::HudLocalizedMessage*)&params[12] = InMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ScreenX = *(float*)&params[4];
			ScreenY = *(float*)&params[8];
			InMessage = *(HUD::HudLocalizedMessage*)&params[12];
		}
		void DrawMessageText(HUD::HudLocalizedMessage LocalMessage, float ScreenX, float ScreenY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawMessageText");
			byte params[72] = { NULL };
			*(HUD::HudLocalizedMessage*)&params[0] = LocalMessage;
			*(float*)&params[64] = ScreenX;
			*(float*)&params[68] = ScreenY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class LocalPlayer**)&params[0] = LP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LP = *(class LocalPlayer**)&params[0];
			return *(class UIInteraction**)&params[4];
		}
		void StartMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.StartMusic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetTeamColor(int TeamIndex, Object::LinearColor& ImageColor, Object::Color& TextColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.GetTeamColor");
			byte params[24] = { NULL };
			*(int*)&params[0] = TeamIndex;
			*(Object::LinearColor*)&params[4] = ImageColor;
			*(Object::Color*)&params[20] = TextColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImageColor = *(Object::LinearColor*)&params[4];
			TextColor = *(Object::Color*)&params[20];
		}
		void DisplayHit(Object::Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayHit");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitDir;
			*(int*)&params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlashDamage(float FlashPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.FlashDamage");
			byte params[4] = { NULL };
			*(float*)&params[0] = FlashPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void DrawBackground(float X, float Y, float Width, float Height, Object::LinearColor DrawColor, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawBackground");
			byte params[36] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Width;
			*(float*)&params[12] = Height;
			*(Object::LinearColor*)&params[16] = DrawColor;
			*(class Canvas**)&params[32] = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawBeaconBackground(float X, float Y, float Width, float Height, Object::LinearColor DrawColor, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawBeaconBackground");
			byte params[36] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Width;
			*(float*)&params[12] = Height;
			*(Object::LinearColor*)&params[16] = DrawColor;
			*(class Canvas**)&params[32] = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawHealth(float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas, byte Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawHealth");
			byte params[25] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Width;
			*(float*)&params[12] = MaxWidth;
			*(float*)&params[16] = Height;
			*(class Canvas**)&params[20] = DrawCanvas;
			params[24] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawBarGraph(float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas, Object::Color BarColor, Object::Color BackColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawBarGraph");
			byte params[32] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Width;
			*(float*)&params[12] = MaxWidth;
			*(float*)&params[16] = Height;
			*(class Canvas**)&params[20] = DrawCanvas;
			*(Object::Color*)&params[24] = BarColor;
			*(Object::Color*)&params[28] = BackColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.FormatTime");
			byte params[16] = { NULL };
			*(int*)&params[0] = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		class Font* GetFontSizeIndex(int FontSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.GetFontSizeIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = FontSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)&params[4];
		}
		void ShowPortrait(class UTPlayerReplicationInfo* ShowPRI, float PortraitDuration, bool bOverrideCurrentSpeaker)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.ShowPortrait");
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = ShowPRI;
			*(float*)&params[4] = PortraitDuration;
			*(bool*)&params[8] = bOverrideCurrentSpeaker;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HidePortrait()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.HidePortrait");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayPortrait(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayPortrait");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayHUDMessage(ScriptString* Message, float XOffsetPct, float YOffsetPct)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayHUDMessage");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(float*)&params[12] = XOffsetPct;
			*(float*)&params[16] = YOffsetPct;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class UTWeapon**)&params[0] = Weapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void DisplayFragCount(Object::Vector2D pos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayFragCount");
			byte params[8] = { NULL };
			*(Object::Vector2D*)&params[0] = pos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawNameplateBackground(Object::Vector2D pos, float WordWidth, Object::LinearColor NameplateColor, float WordHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DrawNameplateBackground");
			byte params[32] = { NULL };
			*(Object::Vector2D*)&params[0] = pos;
			*(float*)&params[8] = WordWidth;
			*(Object::LinearColor*)&params[12] = NameplateColor;
			*(float*)&params[28] = WordHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayLeaderBoard(Object::Vector2D pos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayLeaderBoard");
			byte params[8] = { NULL };
			*(Object::Vector2D*)&params[0] = pos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayConsoleMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUD.DisplayConsoleMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
