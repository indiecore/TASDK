#pragma once
#include "Engine.GameViewportClient.h"
#include "Engine.Player.h"
#include "Engine.Actor.h"
#include "Engine.PostProcessChain.h"
#include "Core.Object.h"
#include "Engine.TranslationContext.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.PostProcessVolume.h"
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
	class LocalPlayer : public Player
	{
	public:
		class PostProcessSettingsOverride
		{
		public:
			ADD_STRUCT(float, BlendStartTime, 240)
			ADD_STRUCT(float, BlendOutDuration, 236)
			ADD_STRUCT(float, BlendInDuration, 232)
			ADD_STRUCT(float, CurrentBlendOutTime, 228)
			ADD_STRUCT(float, CurrentBlendInTime, 224)
			ADD_BOOL(bBlendingOut, 220, 0x2)
			ADD_BOOL(bBlendingIn, 220, 0x1)
			ADD_STRUCT(PostProcessVolume::PostProcessSettings, Settings, 0)
		};
		class CurrentPostProcessVolumeInfo
		{
		public:
			ADD_STRUCT(float, LastBlendTime, 228)
			ADD_STRUCT(float, BlendStartTime, 224)
			ADD_OBJECT(PostProcessVolume, LastVolumeUsed, 220)
			ADD_STRUCT(PostProcessVolume::PostProcessSettings, LastSettings, 0)
		};
		class SynchronizedActorVisibilityHistory
		{
		public:
			ADD_STRUCT(Object::Pointer, CriticalSection, 4)
			ADD_STRUCT(Object::Pointer, State, 0)
		};
		ADD_STRUCT(int, ControllerId, 96)
		ADD_OBJECT(GameViewportClient, ViewportClient, 100)
		ADD_STRUCT(Object::Vector2D, Size, 112)
		ADD_STRUCT(Object::Vector2D, Origin, 104)
		ADD_STRUCT(ScriptArray<class PostProcessChain*>, PlayerPostProcessChains, 124)
		ADD_STRUCT(ScriptArray<LocalPlayer::PostProcessSettingsOverride>, ActivePPOverrides, 624)
		ADD_OBJECT(TranslationContext, TagContext, 656)
		ADD_BOOL(bSentSplitJoin, 652, 0x2)
		ADD_BOOL(bWantToResetToMapDefaultPP, 652, 0x1)
		ADD_STRUCT(ScriptString*, LastMap, 640)
		ADD_STRUCT(Object::EAspectRatioAxisConstraint, AspectRatioAxisConstraint, 636)
		ADD_STRUCT(LocalPlayer::CurrentPostProcessVolumeInfo, LevelPPInfo, 392)
		ADD_STRUCT(LocalPlayer::CurrentPostProcessVolumeInfo, CurrentPPInfo, 160)
		ADD_STRUCT(Object::Vector, LastViewLocation, 148)
		ADD_STRUCT(LocalPlayer::SynchronizedActorVisibilityHistory, ActorVisibilityHistory, 140)
		ADD_STRUCT(Object::Pointer, ViewState, 136)
		ADD_OBJECT(PostProcessChain, PlayerPostProcess, 120)
		bool SpawnPlayActor(ScriptString* URL, ScriptString*& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.SpawnPlayActor");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = URL;
			*(ScriptString**)&params[12] = OutError;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutError = *(ScriptString**)&params[12];
			return *(bool*)&params[24];
		}
		void SendSplitJoin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.SendSplitJoin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetActorVisibility(class Actor* TestActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetActorVisibility");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = TestActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OverridePostProcessSettings(PostProcessVolume::PostProcessSettings OverrideSettings, float BlendInTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.OverridePostProcessSettings");
			byte params[224] = { NULL };
			*(PostProcessVolume::PostProcessSettings*)&params[0] = OverrideSettings;
			*(float*)&params[220] = BlendInTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPostProcessSettingsOverride(float BlendOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.ClearPostProcessSettingsOverride");
			byte params[4] = { NULL };
			*(float*)&params[0] = BlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetControllerId(int NewControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.SetControllerId");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TranslationContext* GetTranslationContext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetTranslationContext");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TranslationContext**)&params[0];
		}
		bool InsertPostProcessingChain(class PostProcessChain* InChain, int InIndex, bool bInClone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.InsertPostProcessingChain");
			byte params[16] = { NULL };
			*(class PostProcessChain**)&params[0] = InChain;
			*(int*)&params[4] = InIndex;
			*(bool*)&params[8] = bInClone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RemovePostProcessingChain(int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.RemovePostProcessingChain");
			byte params[8] = { NULL };
			*(int*)&params[0] = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool RemoveAllPostProcessingChains()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.RemoveAllPostProcessingChains");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class PostProcessChain* GetPostProcessChain(int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetPostProcessChain");
			byte params[8] = { NULL };
			*(int*)&params[0] = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PostProcessChain**)&params[4];
		}
		void TouchPlayerPostProcessChain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.TouchPlayerPostProcessChain");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeProject(Object::Vector2D RelativeScreenPos, Object::Vector& WorldOrigin, Object::Vector& WorldDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.DeProject");
			byte params[32] = { NULL };
			*(Object::Vector2D*)&params[0] = RelativeScreenPos;
			*(Object::Vector*)&params[8] = WorldOrigin;
			*(Object::Vector*)&params[20] = WorldDirection;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WorldOrigin = *(Object::Vector*)&params[8];
			WorldDirection = *(Object::Vector*)&params[20];
		}
		OnlineSubsystem::UniqueNetId GetUniqueNetId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetUniqueNetId");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::UniqueNetId*)&params[0];
		}
		ScriptString* GetNickname()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetNickname");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
