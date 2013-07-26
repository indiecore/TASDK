#pragma once
#include "Engine.SequenceOp.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Sequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Sequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Sequence : public SequenceOp
	{
	public:
		ADD_VAR(::FloatProperty, DefaultViewZoom, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DefaultViewY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DefaultViewX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, LogFile, 0xFFFFFFFF)
		void FindSeqObjectsByClass(ScriptClass* DesiredClass, bool bRecursive, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutputObjects)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.FindSeqObjectsByClass");
			byte* params = (byte*)malloc(20);
			*(ScriptClass**)params = DesiredClass;
			*(bool*)(params + 4) = bRecursive;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = OutputObjects;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutputObjects = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
		}
		void FindSeqObjectsByName(ScriptArray<wchar_t> SeqObjName, bool bCheckComment, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutputObjects, bool bRecursive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.FindSeqObjectsByName");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = SeqObjName;
			*(bool*)(params + 12) = bCheckComment;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = OutputObjects;
			*(bool*)(params + 28) = bRecursive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutputObjects = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.SetEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
