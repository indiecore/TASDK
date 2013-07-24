#pragma once
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
	};
}
#undef ADD_VAR
