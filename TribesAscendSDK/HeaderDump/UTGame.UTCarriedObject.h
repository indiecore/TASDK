#pragma once
#include "UDKBase.UDKCarriedObject.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "UDKBase.UDKPlayerController.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.Texture2D.h"
#include "Engine.Pawn.h"
#include "Engine.SoundCue.h"
#include "Engine.UIRoot.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "Engine.PlayerController.h"
#include "Engine.Canvas.h"
#include "UTGame.UTMapInfo.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKGameObjective.h"
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
	class UTCarriedObject : public UDKCarriedObject
	{
	public:
		ADD_STRUCT(ScriptName, GameObjBone3P, 596)
		ADD_STRUCT(Object::Rotator, GameObjRot3P, 616)
		ADD_STRUCT(Object::Vector, GameObjOffset3P, 604)
		ADD_STRUCT(Object::Rotator, GameObjRot1P, 640)
		ADD_STRUCT(Object::Vector, GameObjOffset1P, 628)
		ADD_STRUCT(ScriptArray<class Controller*>, Assists, 560)
		ADD_STRUCT(ScriptArray<UDKPlayerController::ObjectiveAnnouncementInfo>, NeedToPickUpAnnouncements, 680)
		ADD_OBJECT(ForceFeedbackWaveform, PickUpWaveForm, 764)
		ADD_STRUCT(Object::LinearColor, GoldColor, 748)
		ADD_STRUCT(Object::LinearColor, BlueColor, 732)
		ADD_STRUCT(Object::LinearColor, RedColor, 716)
		ADD_STRUCT(int, LastSeeMessageIndex, 712)
		ADD_STRUCT(float, LastFlagSeeTime, 708)
		ADD_STRUCT(float, LastHighlightUpdate, 704)
		ADD_STRUCT(float, HighlightSpeed, 700)
		ADD_STRUCT(float, MaxHighlightScale, 696)
		ADD_STRUCT(float, HighlightScale, 692)
		ADD_STRUCT(float, DefaultHeight, 676)
		ADD_STRUCT(float, DefaultRadius, 672)
		ADD_OBJECT(Pawn, OldHolder, 664)
		ADD_OBJECT(SoundCue, ReturnedSound, 660)
		ADD_OBJECT(SoundCue, DroppedSound, 656)
		ADD_OBJECT(SoundCue, PickupSound, 652)
		ADD_OBJECT(Texture2D, IconTexture, 592)
		ADD_STRUCT(UIRoot::TextureCoordinates, IconCoords, 576)
		ADD_STRUCT(float, MapSize, 572)
		ADD_OBJECT(Controller, FirstTouch, 556)
		ADD_STRUCT(float, MaxDropTime, 552)
		ADD_STRUCT(float, TakenTime, 548)
		ADD_OBJECT(Pawn, Holder, 544)
		ADD_OBJECT(UTPlayerReplicationInfo, HolderPRI, 540)
		ADD_STRUCT(float, TossDistance, 536)
		ADD_BOOL(bUseTeamColorForIcon, 532, 0x4)
		ADD_BOOL(bLeavingDroppedState, 532, 0x2)
		ADD_BOOL(bLastSecondSave, 532, 0x1)
		bool FlagUse(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.FlagUse");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldMinimapRenderFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ShouldMinimapRenderFor");
			byte params[8] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void HighlightOnMinimap(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.HighlightOnMinimap");
			byte params[4] = { NULL };
			*(int*)&params[0] = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetIconTexture()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.GetIconTexture");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
		void DrawIcon(class Canvas* Canvas, Object::Vector IconLocation, float IconWidth, float IconAlpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.DrawIcon");
			byte params[24] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(Object::Vector*)&params[4] = IconLocation;
			*(float*)&params[16] = IconWidth;
			*(float*)&params[20] = IconAlpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.RenderMapIcon");
			byte params[12] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderEnemyMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, class UTGameObjective* NearbyObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.RenderEnemyMapIcon");
			byte params[16] = { NULL };
			*(class UTMapInfo**)&params[0] = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(class UTGameObjective**)&params[12] = NearbyObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.SetHolder");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendFlagMessage(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.SendFlagMessage");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Score()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Score");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Drop(class Controller* Killer, bool bNoThrow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Drop");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(bool*)&params[4] = bNoThrow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.SendHome");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Returner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KismetSendHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.KismetSendHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastReturnedMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastDroppedMessage");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastTakenFromBaseMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastTakenFromBaseMessage");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastTakenDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastTakenDroppedMessage");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CalcSetHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CalcSetHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ClearHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* Position()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Position");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		bool ValidHolder(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ValidHolder");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ClientReturnedHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotReachableBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.NotReachableBy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UDKGameObjective* GetKismetEventObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.GetKismetEventObjective");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UDKGameObjective**)&params[0];
		}
		void LogTaken(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.LogTaken");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogReturned(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.LogReturned");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogDropped(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.LogDropped");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckTouching()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CheckTouching");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoSendHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.AutoSendHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckFit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CheckFit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckPain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CheckPain");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
