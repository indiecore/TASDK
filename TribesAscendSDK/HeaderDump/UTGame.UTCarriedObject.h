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
		ADD_STRUCT(Rotator, GameObjRot3P, 616)
		ADD_STRUCT(Vector, GameObjOffset3P, 604)
		ADD_STRUCT(Rotator, GameObjRot1P, 640)
		ADD_STRUCT(Vector, GameObjOffset1P, 628)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36609);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43635);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldMinimapRenderFor(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43637);
			byte params[8] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void HighlightOnMinimap(int Switch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43640);
			byte params[4] = { NULL };
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetIconTexture()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43642);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
		void DrawIcon(class Canvas* Canvas, Vector IconLocation, float IconWidth, float IconAlpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43644);
			byte params[24] = { NULL };
			*(class Canvas**)params = Canvas;
			*(Vector*)&params[4] = IconLocation;
			*(float*)&params[16] = IconWidth;
			*(float*)&params[20] = IconAlpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43651);
			byte params[12] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderEnemyMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, class UTGameObjective* NearbyObjective)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43656);
			byte params[16] = { NULL };
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)&params[4] = Canvas;
			*(class UTPlayerController**)&params[8] = PlayerOwner;
			*(class UTGameObjective**)&params[12] = NearbyObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43666);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendFlagMessage(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43672);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Score()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43674);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Drop(class Controller* Killer, bool bNoThrow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43675);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(bool*)&params[4] = bNoThrow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43679);
			byte params[4] = { NULL };
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KismetSendHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43682);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43683);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43684);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastTakenFromBaseMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43686);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastTakenDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43688);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CalcSetHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43690);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43692);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* Position()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43697);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		bool ValidHolder(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43699);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43705);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43710);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43712);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43714);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotReachableBy(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43715);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43717);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UDKGameObjective* GetKismetEventObjective()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43720);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UDKGameObjective**)params;
		}
		void LogTaken(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43722);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogReturned(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43724);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogDropped(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43726);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckTouching()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43729);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoSendHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43733);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckFit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43761);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckPain()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43762);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
