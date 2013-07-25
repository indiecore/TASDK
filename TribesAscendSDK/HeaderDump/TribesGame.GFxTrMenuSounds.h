#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class GFxTrMenuSounds : public Object
	{
	public:
		void SoundToolTip(bool bOpened)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.SoundToolTip");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bOpened;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SoundXPGain(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.SoundXPGain");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SoundSkillType(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.SoundSkillType");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SoundClassType(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.SoundClassType");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SoundPurchaseSkill()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.SoundPurchaseSkill");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SoundSelectedQueue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.SoundSelectedQueue");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveQueue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.LeaveQueue");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PageForward()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.PageForward");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PageBack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.PageBack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassRollover()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.ClassRollover");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassSelected()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.ClassSelected");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassLocked()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.ClassLocked");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayMenuSound(byte MenuSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuSounds.PlayMenuSound");
			byte* params = (byte*)malloc(1);
			*params = MenuSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
