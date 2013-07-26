#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FileWriter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FileWriter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FileWriter : public Info
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ArchivePtr, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Filename, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FileType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFlushEachWrite, 0x1)
		ADD_VAR(::BoolProperty, bWantsAsyncWrites, 0x2)
		bool OpenFile(ScriptArray<wchar_t> InFilename, byte InFileType, ScriptArray<wchar_t> InExtension, bool bUnique, bool bIncludeTimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileWriter.OpenFile");
			byte* params = (byte*)malloc(37);
			*(ScriptArray<wchar_t>*)params = InFilename;
			*(params + 12) = InFileType;
			*(ScriptArray<wchar_t>*)(params + 16) = InExtension;
			*(bool*)(params + 28) = bUnique;
			*(bool*)(params + 32) = bIncludeTimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		void CloseFile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileWriter.CloseFile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Logf(ScriptArray<wchar_t> logString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileWriter.Logf");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = logString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FileWriter.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
