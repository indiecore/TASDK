#pragma once
#include "TribesGame.TrHelpTextManager.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrHelpTextManager_Training : public TrHelpTextManager
	{
	public:
		enum EHelpTextTrainingType : byte
		{
			HelpTextTraining_None = 0,
			HelpTextTraining_Example1 = 1,
			HelpTextTraining_Example2 = 2,
			HelpTextTraining_Ski1 = 3,
			HelpTextTraining_Ski2 = 4,
			HelpTextTraining_Ski3 = 5,
			HelpTextTraining_Ski4 = 6,
			HelpTextTraining_Ski5 = 7,
			HelpTextTraining_SkiAdv1 = 8,
			HelpTextTraining_SkiAdv2 = 9,
			HelpTextTraining_SkiAdv3 = 10,
			HelpTextTraining_SkiAdv4 = 11,
			HelpTextTraining_SkiAdv5 = 12,
			HelpTextTraining_MAX = 13,
		};
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextExample1, 1264)
		ADD_STRUCT(TrHelpTextManager_Training::EHelpTextTrainingType, m_CurrentHelpTextTrainingType, 1552)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextExample1MenuTitle, 1408)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextExample2, 1276)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextExample2MenuTitle, 1420)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiMessage1, 1288)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSki1MenuTitle, 1432)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiMessage2, 1300)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSki2MenuTitle, 1444)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiMessage3, 1312)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSki3MenuTitle, 1456)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiMessage4, 1324)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSki4MenuTitle, 1468)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiMessage5, 1336)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSki5MenuTitle, 1480)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdvMessage1, 1348)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdv1MenuTitle, 1492)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdvMessage2, 1360)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdv2MenuTitle, 1504)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdvMessage3, 1372)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdv3MenuTitle, 1516)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdvMessage4, 1384)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdv4MenuTitle, 1528)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdvMessage5, 1396)
		ADD_STRUCT(ScriptString*, m_TrainingHelpTextSkiAdv5MenuTitle, 1540)
		void InitHelpTextManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95425);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTypesToRemoveOnTimers(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95426);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckDestroy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95428);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool RequestHelpText(TrHelpTextManager::EHelpTextType RequestedType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95430);
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)params = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RemoveHelpText(TrHelpTextManager::EHelpTextType TypeToRemove, float Time, bool bDoNotSuppress)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95433);
			byte params[9] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)params = TypeToRemove;
			*(float*)&params[4] = Time;
			*(bool*)&params[8] = bDoNotSuppress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RequestHelpText_Training(TrHelpTextManager_Training::EHelpTextTrainingType RequestedType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95437);
			byte params[1] = { NULL };
			*(TrHelpTextManager_Training::EHelpTextTrainingType*)params = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(95440);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
