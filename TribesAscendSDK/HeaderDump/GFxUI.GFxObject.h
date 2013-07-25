#pragma once
#include "Core.Object.h"
#include "Engine.TranslationContext.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.GFxObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxObject : public Object
	{
	public:
		ADD_VAR(::IntProperty, Value, 0xFFFFFFFF)
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* Get(ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.Get");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetBool(ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetBool");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetFloat(ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetFloat");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetString(ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		class GFxObject* GetObject(ScriptArray<wchar_t> Member, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetObject");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = Member;
			*(ScriptClass**)(params + 12) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 16);
			free(params);
			return returnVal;
		}
		void Set(ScriptArray<wchar_t> Member, 
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.Set");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Member;
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 12) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBool(ScriptArray<wchar_t> Member, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetBool");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Member;
			*(bool*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFloat(ScriptArray<wchar_t> Member, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetFloat");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Member;
			*(float*)(params + 12) = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetString(ScriptArray<wchar_t> Member, ScriptArray<wchar_t> S, class TranslationContext* InContext)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetString");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Member;
			*(ScriptArray<wchar_t>*)(params + 12) = S;
			*(class TranslationContext**)(params + 24) = InContext;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetObject(ScriptArray<wchar_t> Member, class GFxObject* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetObject");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Member;
			*(class GFxObject**)(params + 12) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFunction(ScriptArray<wchar_t> Member, class Object* context, ScriptName fname)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetFunction");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Member;
			*(class Object**)(params + 12) = context;
			*(ScriptName*)(params + 16) = fname;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> TranslateString(ScriptArray<wchar_t> StringToTranslate, class TranslationContext* InContext)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.TranslateString");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = StringToTranslate;
			*(class TranslationContext**)(params + 12) = InContext;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void* GetDisplayInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetDisplayInfo");
			byte* params = (byte*)malloc(44);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void**)params;
			free(params);
			return returnVal;
		}
		bool GetPosition(float& X, float& Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetPosition");
			byte* params = (byte*)malloc(12);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			X = *(float*)params;
			Y = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASColorTransform'!
void* GetColorTransform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetColorTransform");
			byte* params = (byte*)malloc(32);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASColorTransform'!
void**)params;
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* GetDisplayMatrix()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetDisplayMatrix");
			byte* params = (byte*)malloc(64);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
			return returnVal;
		}
		void SetDisplayInfo(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void* D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetDisplayInfo");
			byte* params = (byte*)malloc(44);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void**)params = D;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPosition(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetPosition");
			byte* params = (byte*)malloc(8);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetColorTransform(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASColorTransform'!
void* cxform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetColorTransform");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASColorTransform'!
void**)params = cxform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDisplayMatrix(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetDisplayMatrix");
			byte* params = (byte*)malloc(64);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDisplayMatrix3D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetDisplayMatrix3D");
			byte* params = (byte*)malloc(64);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVisible(bool Visible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetVisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = Visible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetText");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void SetText(ScriptArray<wchar_t> Text, class TranslationContext* InContext)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetText");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Text;
			*(class TranslationContext**)(params + 12) = InContext;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* GetElement(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElement");
			byte* params = (byte*)malloc(28);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		class GFxObject* GetElementObject(int Index, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementObject");
			byte* params = (byte*)malloc(12);
			*(int*)params = Index;
			*(ScriptClass**)(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetElementBool(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementBool");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetElementFloat(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementFloat");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetElementString(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementString");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetElement(int Index, 
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElement");
			byte* params = (byte*)malloc(28);
			*(int*)params = Index;
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 4) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementObject(int Index, class GFxObject* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementObject");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(class GFxObject**)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementBool(int Index, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementBool");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(bool*)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementFloat(int Index, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementFloat");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(float*)(params + 4) = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementString(int Index, ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementString");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void* GetElementDisplayInfo(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementDisplayInfo");
			byte* params = (byte*)malloc(48);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* GetElementDisplayMatrix(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementDisplayMatrix");
			byte* params = (byte*)malloc(68);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		void SetElementDisplayInfo(int Index, 
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void* D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementDisplayInfo");
			byte* params = (byte*)malloc(48);
			*(int*)params = Index;
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASDisplayInfo'!
void**)(params + 4) = D;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementDisplayMatrix(int Index, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementDisplayMatrix");
			byte* params = (byte*)malloc(68);
			*(int*)params = Index;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 16) = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementVisible(int Index, bool Visible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementVisible");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(bool*)(params + 4) = Visible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementPosition(int Index, float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementPosition");
			byte* params = (byte*)malloc(12);
			*(int*)params = Index;
			*(float*)(params + 4) = X;
			*(float*)(params + 8) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementColorTransform(int Index, 
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASColorTransform'!
void* cxform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementColorTransform");
			byte* params = (byte*)malloc(36);
			*(int*)params = Index;
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxObject.ASColorTransform'!
void**)(params + 4) = cxform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* GetElementMember(int Index, ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMember");
			byte* params = (byte*)malloc(40);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		class GFxObject* GetElementMemberObject(int Index, ScriptArray<wchar_t> Member, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberObject");
			byte* params = (byte*)malloc(24);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			*(ScriptClass**)(params + 16) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetElementMemberBool(int Index, ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberBool");
			byte* params = (byte*)malloc(20);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		float GetElementMemberFloat(int Index, ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberFloat");
			byte* params = (byte*)malloc(20);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetElementMemberString(int Index, ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberString");
			byte* params = (byte*)malloc(28);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetElementMember(int Index, ScriptArray<wchar_t> Member, 
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMember");
			byte* params = (byte*)malloc(40);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementMemberObject(int Index, ScriptArray<wchar_t> Member, class GFxObject* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberObject");
			byte* params = (byte*)malloc(20);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			*(class GFxObject**)(params + 16) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementMemberBool(int Index, ScriptArray<wchar_t> Member, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberBool");
			byte* params = (byte*)malloc(20);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			*(bool*)(params + 16) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementMemberFloat(int Index, ScriptArray<wchar_t> Member, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberFloat");
			byte* params = (byte*)malloc(20);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			*(float*)(params + 16) = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetElementMemberString(int Index, ScriptArray<wchar_t> Member, ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberString");
			byte* params = (byte*)malloc(28);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			*(ScriptArray<wchar_t>*)(params + 16) = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActionScriptSetFunction(ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptSetFunction");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActionScriptSetFunctionOn(class GFxObject* Target, ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptSetFunctionOn");
			byte* params = (byte*)malloc(16);
			*(class GFxObject**)params = Target;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* Invoke(ScriptArray<wchar_t> Member, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* args)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.Invoke");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = Member;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = args;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 24);
			free(params);
			return returnVal;
		}
		void ActionScriptVoid(ScriptArray<wchar_t> method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptVoid");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = method;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int ActionScriptInt(ScriptArray<wchar_t> method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptInt");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = method;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		float ActionScriptFloat(ScriptArray<wchar_t> method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptFloat");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = method;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> ActionScriptString(ScriptArray<wchar_t> method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = method;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		class GFxObject* ActionScriptObject(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptObject");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 12);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* ActionScriptArray(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptArray");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		void GotoAndPlay(ScriptArray<wchar_t> frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndPlay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GotoAndPlayI(int frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndPlayI");
			byte* params = (byte*)malloc(4);
			*(int*)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GotoAndStop(ScriptArray<wchar_t> frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndStop");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GotoAndStopI(int frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndStopI");
			byte* params = (byte*)malloc(4);
			*(int*)params = frame;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* CreateEmptyMovieClip(ScriptArray<wchar_t> instancename, int Depth, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.CreateEmptyMovieClip");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = instancename;
			*(int*)(params + 12) = Depth;
			*(ScriptClass**)(params + 16) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 20);
			free(params);
			return returnVal;
		}
		class GFxObject* AttachMovie(ScriptArray<wchar_t> symbolname, ScriptArray<wchar_t> instancename, int Depth, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.AttachMovie");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = symbolname;
			*(ScriptArray<wchar_t>*)(params + 12) = instancename;
			*(int*)(params + 24) = Depth;
			*(ScriptClass**)(params + 28) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 32);
			free(params);
			return returnVal;
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool WidgetUnloaded(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.WidgetUnloaded");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
