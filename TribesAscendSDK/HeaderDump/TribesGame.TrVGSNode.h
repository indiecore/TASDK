#pragma once
#include "Core.Object.h"
#include "TribesGame.TrPlayerInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVGSNode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrVGSNode : public Object
	{
	public:
		ADD_VAR(::BoolProperty, m_bDrawHeader, 0x10)
		ADD_VAR(::StrProperty, m_MenuString, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_KeyBind, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIgnoreCaH, 0x8)
		ADD_VAR(::BoolProperty, m_bIgnoreArena, 0x4)
		ADD_VAR(::BoolProperty, m_bIgnoreTeamRabbit, 0x2)
		ADD_VAR(::BoolProperty, m_bIgnoreCTF, 0x1)
		ScriptClass* ProcessKeyInput(ScriptName Key, class TrPlayerInput* PlayerInput, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.ProcessKeyInput");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = Key;
			*(class TrPlayerInput**)(params + 8) = PlayerInput;
			*(ScriptClass**)(params + 12) = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 16);
			free(params);
			return returnVal;
		}
		bool VerifyVGSCommandEntry(byte Command, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.VerifyVGSCommandEntry");
			byte* params = (byte*)malloc(9);
			*params = Command;
			*(ScriptClass**)(params + 4) = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool VerifyVGSChild(ScriptClass* VGSNodeClass, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.VerifyVGSChild");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = VGSNodeClass;
			*(ScriptClass**)(params + 4) = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetGametypeSpecificCommands(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& outGametypeSpecificCommands, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.GetGametypeSpecificCommands");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = outGametypeSpecificCommands;
			*(ScriptClass**)(params + 12) = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			outGametypeSpecificCommands = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void GetGametypeSpecificChildrenNodes(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& outVGSNodeChildrenClasses, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.GetGametypeSpecificChildrenNodes");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = outVGSNodeChildrenClasses;
			*(ScriptClass**)(params + 12) = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			outVGSNodeChildrenClasses = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
