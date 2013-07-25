#pragma once
#include "TribesGame.TrHelpTextManager.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHelpTextManager_Training." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrHelpTextManager_Training : public TrHelpTextManager
	{
	public:
		ADD_VAR(::StrProperty, m_TrainingHelpTextExample1, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CurrentHelpTextTrainingType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextExample1MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextExample2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextExample2MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiMessage1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSki1MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiMessage2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSki2MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiMessage3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSki3MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiMessage4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSki4MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiMessage5, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSki5MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdvMessage1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdv1MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdvMessage2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdv2MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdvMessage3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdv3MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdvMessage4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdv4MenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdvMessage5, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_TrainingHelpTextSkiAdv5MenuTitle, 0xFFFFFFFF)
		void InitHelpTextManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager_Training.InitHelpTextManager");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTypesToRemoveOnTimers(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager_Training.UpdateTypesToRemoveOnTimers");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckDestroy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager_Training.CheckDestroy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool RequestHelpText(byte RequestedType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager_Training.RequestHelpText");
			byte* params = (byte*)malloc(5);
			*params = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RemoveHelpText(byte TypeToRemove, float Time, bool bDoNotSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager_Training.RemoveHelpText");
			byte* params = (byte*)malloc(9);
			*params = TypeToRemove;
			*(float*)(params + 4) = Time;
			*(bool*)(params + 8) = bDoNotSuppress;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RequestHelpText_Training(byte RequestedType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager_Training.RequestHelpText_Training");
			byte* params = (byte*)malloc(1);
			*params = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager_Training.UpdateHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
