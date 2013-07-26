#pragma once
#include "Engine.GameViewportClient.h"
#include "Engine.Player.h"
#include "Core.Object.Pointer.h"
#include "Engine.LocalPlayer.CurrentPostProcessVolumeInfo.h"
#include "Core.Object.Vector2D.h"
#include "Engine.TranslationContext.h"
#include "Core.Object.Vector.h"
#include "Engine.LocalPlayer.SynchronizedActorVisibilityHistory.h"
#include "Engine.PostProcessChain.h"
#include "Engine.Actor.h"
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LocalPlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LocalPlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LocalPlayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LocalPlayer : public Player
	{
	public:
		ADD_VAR(::IntProperty, ControllerId, 0xFFFFFFFF)
		ADD_OBJECT(GameViewportClient, ViewportClient)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Size, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, Origin, 0xFFFFFFFF)
		ADD_OBJECT(TranslationContext, TagContext)
		ADD_VAR(::BoolProperty, bSentSplitJoin, 0x2)
		ADD_VAR(::BoolProperty, bWantToResetToMapDefaultPP, 0x1)
		ADD_VAR(::StrProperty, LastMap, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AspectRatioAxisConstraint, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<CurrentPostProcessVolumeInfo>, LevelPPInfo, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<CurrentPostProcessVolumeInfo>, CurrentPPInfo, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastViewLocation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<SynchronizedActorVisibilityHistory>, ActorVisibilityHistory, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ViewState, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, PlayerPostProcess)
		bool SpawnPlayActor(ScriptArray<wchar_t> URL, ScriptArray<wchar_t>& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.SpawnPlayActor");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = URL;
			*(ScriptArray<wchar_t>*)(params + 12) = OutError;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutError = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void SendSplitJoin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.SendSplitJoin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetActorVisibility(class Actor* TestActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetActorVisibility");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = TestActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OverridePostProcessSettings(PostProcessSettings OverrideSettings, float BlendInTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.OverridePostProcessSettings");
			byte* params = (byte*)malloc(224);
			*(PostProcessSettings*)params = OverrideSettings;
			*(float*)(params + 220) = BlendInTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPostProcessSettingsOverride(float BlendOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.ClearPostProcessSettingsOverride");
			byte* params = (byte*)malloc(4);
			*(float*)params = BlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetControllerId(int NewControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.SetControllerId");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TranslationContext* GetTranslationContext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetTranslationContext");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TranslationContext**)params;
			free(params);
			return returnVal;
		}
		bool InsertPostProcessingChain(class PostProcessChain* InChain, int InIndex, bool bInClone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.InsertPostProcessingChain");
			byte* params = (byte*)malloc(16);
			*(class PostProcessChain**)params = InChain;
			*(int*)(params + 4) = InIndex;
			*(bool*)(params + 8) = bInClone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RemovePostProcessingChain(int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.RemovePostProcessingChain");
			byte* params = (byte*)malloc(8);
			*(int*)params = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RemoveAllPostProcessingChains()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.RemoveAllPostProcessingChains");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class PostProcessChain* GetPostProcessChain(int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetPostProcessChain");
			byte* params = (byte*)malloc(8);
			*(int*)params = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PostProcessChain**)(params + 4);
			free(params);
			return returnVal;
		}
		void TouchPlayerPostProcessChain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.TouchPlayerPostProcessChain");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeProject(Vector2D RelativeScreenPos, Vector& WorldOrigin, Vector& WorldDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.DeProject");
			byte* params = (byte*)malloc(32);
			*(Vector2D*)params = RelativeScreenPos;
			*(Vector*)(params + 8) = WorldOrigin;
			*(Vector*)(params + 20) = WorldDirection;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			WorldOrigin = *(Vector*)(params + 8);
			WorldDirection = *(Vector*)(params + 20);
			free(params);
		}
		UniqueNetId GetUniqueNetId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetUniqueNetId");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(UniqueNetId*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetNickname()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LocalPlayer.GetNickname");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
