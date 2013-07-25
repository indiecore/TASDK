#pragma once
#include "UTGame__UTHUDBase.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'WhiteLinearColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'TeamHUDColor'!
		ADD_VAR(::BoolProperty, bShowVehicleArmorCount, 0x40000)
		ADD_VAR(::FloatProperty, TX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TY, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'GoldLinearColor'!
		ADD_OBJECT(Pawn, PawnOwner)
		ADD_VAR(::FloatProperty, LastAmmoPickupTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastArmorPickupTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MessageOffset, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsFirstPlayer, 0x80000)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BkgTexColor'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'BkgTexCoords'!
		ADD_OBJECT(Texture2D, BkgTexture)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'SilverLinearColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'DMLinearColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'BlueLinearColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'RedLinearColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'AmmoBarColor'!
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'PawnDollBGCoords'!
		ADD_VAR(::StrProperty, PlaceMarks, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouHaveLost, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouHaveWon, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FireToRespawnMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeadMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SpectatorMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PressFireToBegin, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WaitingForMatch, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WarmupString, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'BlackBackgroundColor'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'NameplateRight'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'NameplateBubble'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'NameplateCenter'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'NameplateLeft'!
		ADD_VAR(::FloatProperty, NameplateBubbleWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NameplateWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageIndicatorSize, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'VehiclePosition'!
		ADD_VAR(::IntProperty, LastFragCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FragPulseTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'ScoringPosition'!
		ADD_VAR(::FloatProperty, PowerupTransitionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PowerupYPos, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'PowerupDims'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'MapPosition'!
		ADD_VAR(::FloatProperty, AmmoPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastAmmoCount, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, LastWeapon)
		ADD_VAR(::FloatProperty, AmmoTextOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AmmoTextOffsetX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'AmmoBGCoords'!
		ADD_VAR(::FloatProperty, AmmoBarOffsetY, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'AmmoPosition'!
		ADD_VAR(::FloatProperty, ArmorPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastArmorAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorTextY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorTextX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorIconY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorIconX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorBGOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArmorBGOffsetX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'ArmorBGCoords'!
		ADD_VAR(::FloatProperty, HealthPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthTextY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthTextX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthIconY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthIconX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthBGOffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthBGOffsetX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthOffsetX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'HealthBGCoords'!
		ADD_VAR(::FloatProperty, DollVisibility, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastDollUpdate, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'DollPosition'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'ClockPosition'!
		ADD_OBJECT(MaterialInstanceConstant, HitEffectMaterialInstance)
		ADD_OBJECT(MaterialEffect, HitEffect)
		ADD_VAR(::FloatProperty, HitEffectFadeTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MaxHitEffectColor'!
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'TeamTextColor'!
		ADD_VAR(::FloatProperty, HUDScaleY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HUDScaleX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBoxHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBoxWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponBarScale, 0xFFFFFFFF)
		ADD_OBJECT(UTPlayerReplicationInfo, CharPendingPRI)
		ADD_OBJECT(UTPlayerReplicationInfo, CharPRI)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'CharPortraitSize'!
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'GrayColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'LC_White'!
		ADD_OBJECT(Texture2D, UT3GHudTexture)
		ADD_OBJECT(Texture2D, TalkingTexture)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
