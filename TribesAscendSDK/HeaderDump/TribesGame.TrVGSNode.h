#pragma once
#include "Core.Object.h"
#include "TribesGame.TrVGSCommandList.h"
#include "TribesGame.TrPlayerInput.h"
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
namespace UnrealScript
{
	class TrVGSNode : public Object
	{
	public:
		ADD_BOOL(m_bDrawHeader, 152, 0x10)
		ADD_STRUCT(ScriptString*, m_MenuString, 68)
		ADD_STRUCT(ScriptName, m_KeyBind, 60)
		ADD_STRUCT(ScriptArray<TrVGSCommandList::VGSCommandType>, m_Commands, 92)
		ADD_STRUCT(ScriptArray<ScriptClass*>, m_Children, 80)
		ADD_STRUCT(ScriptArray<TrVGSCommandList::VGSCommandType>, m_IgnoreCTFCommand, 104)
		ADD_STRUCT(ScriptArray<TrVGSCommandList::VGSCommandType>, m_IgnoreTeamRabbitCommand, 116)
		ADD_STRUCT(ScriptArray<TrVGSCommandList::VGSCommandType>, m_IgnoreArenaCommand, 128)
		ADD_STRUCT(ScriptArray<TrVGSCommandList::VGSCommandType>, m_IgnoreCaHCommand, 140)
		ADD_BOOL(m_bIgnoreCaH, 152, 0x8)
		ADD_BOOL(m_bIgnoreArena, 152, 0x4)
		ADD_BOOL(m_bIgnoreTeamRabbit, 152, 0x2)
		ADD_BOOL(m_bIgnoreCTF, 152, 0x1)
		ScriptClass* ProcessKeyInput(ScriptName Key, class TrPlayerInput* PlayerInput, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.ProcessKeyInput");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = Key;
			*(class TrPlayerInput**)&params[8] = PlayerInput;
			*(ScriptClass**)&params[12] = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[16];
		}
		bool VerifyVGSCommandEntry(TrVGSCommandList::VGSCommandType Command, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.VerifyVGSCommandEntry");
			byte params[9] = { NULL };
			*(TrVGSCommandList::VGSCommandType*)&params[0] = Command;
			*(ScriptClass**)&params[4] = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool VerifyVGSChild(ScriptClass* VGSNodeClass, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.VerifyVGSChild");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = VGSNodeClass;
			*(ScriptClass**)&params[4] = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void GetGametypeSpecificCommands(ScriptArray<TrVGSCommandList::VGSCommandType>& outGametypeSpecificCommands, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.GetGametypeSpecificCommands");
			byte params[16] = { NULL };
			*(ScriptArray<TrVGSCommandList::VGSCommandType>*)&params[0] = outGametypeSpecificCommands;
			*(ScriptClass**)&params[12] = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			outGametypeSpecificCommands = *(ScriptArray<TrVGSCommandList::VGSCommandType>*)&params[0];
		}
		void GetGametypeSpecificChildrenNodes(ScriptArray<ScriptClass*>& outVGSNodeChildrenClasses, ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVGSNode.GetGametypeSpecificChildrenNodes");
			byte params[16] = { NULL };
			*(ScriptArray<ScriptClass*>*)&params[0] = outVGSNodeChildrenClasses;
			*(ScriptClass**)&params[12] = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			outVGSNodeChildrenClasses = *(ScriptArray<ScriptClass*>*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
