#pragma once
#include "Core.Object.h"
#include "GFxUI.GFxMoviePlayer.h"
#include "Engine.TranslationContext.h"
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
	class GFxObject : public Object
	{
	public:
		class ASDisplayInfo
		{
		public:
			ADD_BOOL(hasVisible, 40, 0x800)
			ADD_BOOL(hasAlpha, 40, 0x400)
			ADD_BOOL(hasZScale, 40, 0x200)
			ADD_BOOL(hasYScale, 40, 0x100)
			ADD_BOOL(hasXScale, 40, 0x80)
			ADD_BOOL(hasYRotation, 40, 0x40)
			ADD_BOOL(hasXRotation, 40, 0x20)
			ADD_BOOL(hasRotation, 40, 0x10)
			ADD_BOOL(hasZ, 40, 0x8)
			ADD_BOOL(hasY, 40, 0x4)
			ADD_BOOL(hasX, 40, 0x2)
			ADD_BOOL(Visible, 40, 0x1)
			ADD_STRUCT(float, Alpha, 36)
			ADD_STRUCT(float, ZScale, 32)
			ADD_STRUCT(float, YScale, 28)
			ADD_STRUCT(float, XScale, 24)
			ADD_STRUCT(float, YRotation, 20)
			ADD_STRUCT(float, XRotation, 16)
			ADD_STRUCT(float, Rotation, 12)
			ADD_STRUCT(float, Z, 8)
			ADD_STRUCT(float, Y, 4)
			ADD_STRUCT(float, X, 0)
		};
		class ASColorTransform
		{
		public:
			ADD_STRUCT(Object::LinearColor, Add, 16)
			ADD_STRUCT(Object::LinearColor, Multiply, 0)
		};
		ADD_STRUCT(ScriptArray<GFxMoviePlayer::GFxWidgetBinding>, SubWidgetBindings, 108)
		ADD_STRUCT(int, Value, 60)
		GFxMoviePlayer::ASValue Get(ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.Get");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[12];
		}
		bool GetBool(ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetBool");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		float GetFloat(ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetFloat");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		ScriptString* GetString(ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetString");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		class GFxObject* GetObject(ScriptString* Member, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetObject");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(ScriptClass**)&params[12] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[16];
		}
		void Set(ScriptString* Member, GFxMoviePlayer::ASValue Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.Set");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(GFxMoviePlayer::ASValue*)&params[12] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBool(ScriptString* Member, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetBool");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(bool*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFloat(ScriptString* Member, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetFloat");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(float*)&params[12] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetString(ScriptString* Member, ScriptString* S, class TranslationContext* InContext)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetString");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(ScriptString**)&params[12] = S;
			*(class TranslationContext**)&params[24] = InContext;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetObject(ScriptString* Member, class GFxObject* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetObject");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(class GFxObject**)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFunction(ScriptString* Member, class Object* context, ScriptName fname)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetFunction");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(class Object**)&params[12] = context;
			*(ScriptName*)&params[16] = fname;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* TranslateString(ScriptString* StringToTranslate, class TranslationContext* InContext)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.TranslateString");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = StringToTranslate;
			*(class TranslationContext**)&params[12] = InContext;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		GFxObject::ASDisplayInfo GetDisplayInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetDisplayInfo");
			byte params[44] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxObject::ASDisplayInfo*)&params[0];
		}
		bool GetPosition(float& X, float& Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetPosition");
			byte params[12] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			X = *(float*)&params[0];
			Y = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		GFxObject::ASColorTransform GetColorTransform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetColorTransform");
			byte params[32] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxObject::ASColorTransform*)&params[0];
		}
		Object::Matrix GetDisplayMatrix()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetDisplayMatrix");
			byte params[64] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[0];
		}
		void SetDisplayInfo(GFxObject::ASDisplayInfo D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetDisplayInfo");
			byte params[44] = { NULL };
			*(GFxObject::ASDisplayInfo*)&params[0] = D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPosition(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetPosition");
			byte params[8] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetColorTransform(GFxObject::ASColorTransform cxform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetColorTransform");
			byte params[32] = { NULL };
			*(GFxObject::ASColorTransform*)&params[0] = cxform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDisplayMatrix(Object::Matrix M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetDisplayMatrix");
			byte params[64] = { NULL };
			*(Object::Matrix*)&params[0] = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDisplayMatrix3D(Object::Matrix M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetDisplayMatrix3D");
			byte params[64] = { NULL };
			*(Object::Matrix*)&params[0] = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVisible(bool Visible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetVisible");
			byte params[4] = { NULL };
			*(bool*)&params[0] = Visible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetText");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void SetText(ScriptString* Text, class TranslationContext* InContext)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetText");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Text;
			*(class TranslationContext**)&params[12] = InContext;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxMoviePlayer::ASValue GetElement(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElement");
			byte params[28] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[4];
		}
		class GFxObject* GetElementObject(int Index, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementObject");
			byte params[12] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptClass**)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[8];
		}
		bool GetElementBool(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementBool");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetElementFloat(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementFloat");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		ScriptString* GetElementString(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementString");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void SetElement(int Index, GFxMoviePlayer::ASValue Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElement");
			byte params[28] = { NULL };
			*(int*)&params[0] = Index;
			*(GFxMoviePlayer::ASValue*)&params[4] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementObject(int Index, class GFxObject* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementObject");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(class GFxObject**)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementBool(int Index, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementBool");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(bool*)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementFloat(int Index, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementFloat");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(float*)&params[4] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementString(int Index, ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementString");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxObject::ASDisplayInfo GetElementDisplayInfo(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementDisplayInfo");
			byte params[48] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxObject::ASDisplayInfo*)&params[4];
		}
		Object::Matrix GetElementDisplayMatrix(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementDisplayMatrix");
			byte params[68] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[16];
		}
		void SetElementDisplayInfo(int Index, GFxObject::ASDisplayInfo D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementDisplayInfo");
			byte params[48] = { NULL };
			*(int*)&params[0] = Index;
			*(GFxObject::ASDisplayInfo*)&params[4] = D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementDisplayMatrix(int Index, Object::Matrix M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementDisplayMatrix");
			byte params[68] = { NULL };
			*(int*)&params[0] = Index;
			*(Object::Matrix*)&params[16] = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementVisible(int Index, bool Visible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementVisible");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(bool*)&params[4] = Visible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementPosition(int Index, float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementPosition");
			byte params[12] = { NULL };
			*(int*)&params[0] = Index;
			*(float*)&params[4] = X;
			*(float*)&params[8] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementColorTransform(int Index, GFxObject::ASColorTransform cxform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementColorTransform");
			byte params[36] = { NULL };
			*(int*)&params[0] = Index;
			*(GFxObject::ASColorTransform*)&params[4] = cxform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxMoviePlayer::ASValue GetElementMember(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMember");
			byte params[40] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[16];
		}
		class GFxObject* GetElementMemberObject(int Index, ScriptString* Member, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberObject");
			byte params[24] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			*(ScriptClass**)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[20];
		}
		bool GetElementMemberBool(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberBool");
			byte params[20] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		float GetElementMemberFloat(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberFloat");
			byte params[20] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		ScriptString* GetElementMemberString(int Index, ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GetElementMemberString");
			byte params[28] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		void SetElementMember(int Index, ScriptString* Member, GFxMoviePlayer::ASValue Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMember");
			byte params[40] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			*(GFxMoviePlayer::ASValue*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberObject(int Index, ScriptString* Member, class GFxObject* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberObject");
			byte params[20] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			*(class GFxObject**)&params[16] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberBool(int Index, ScriptString* Member, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberBool");
			byte params[20] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			*(bool*)&params[16] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberFloat(int Index, ScriptString* Member, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberFloat");
			byte params[20] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			*(float*)&params[16] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetElementMemberString(int Index, ScriptString* Member, ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.SetElementMemberString");
			byte params[28] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = Member;
			*(ScriptString**)&params[16] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActionScriptSetFunction(ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptSetFunction");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActionScriptSetFunctionOn(class GFxObject* Target, ScriptString* Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptSetFunctionOn");
			byte params[16] = { NULL };
			*(class GFxObject**)&params[0] = Target;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxMoviePlayer::ASValue Invoke(ScriptString* Member, ScriptArray<GFxMoviePlayer::ASValue> args)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.Invoke");
			byte params[48] = { NULL };
			*(ScriptString**)&params[0] = Member;
			*(ScriptArray<GFxMoviePlayer::ASValue>*)&params[12] = args;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[24];
		}
		void ActionScriptVoid(ScriptString* method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptVoid");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int ActionScriptInt(ScriptString* method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptInt");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		float ActionScriptFloat(ScriptString* method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptFloat");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		ScriptString* ActionScriptString(ScriptString* method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptString");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		class GFxObject* ActionScriptObject(ScriptString* Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptObject");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[12];
		}
		ScriptArray<class GFxObject*> ActionScriptArray(ScriptString* Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.ActionScriptArray");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class GFxObject*>*)&params[12];
		}
		void GotoAndPlay(ScriptString* frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndPlay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GotoAndPlayI(int frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndPlayI");
			byte params[4] = { NULL };
			*(int*)&params[0] = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GotoAndStop(ScriptString* frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndStop");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GotoAndStopI(int frame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.GotoAndStopI");
			byte params[4] = { NULL };
			*(int*)&params[0] = frame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* CreateEmptyMovieClip(ScriptString* instancename, int Depth, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.CreateEmptyMovieClip");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = instancename;
			*(int*)&params[12] = Depth;
			*(ScriptClass**)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[20];
		}
		class GFxObject* AttachMovie(ScriptString* symbolname, ScriptString* instancename, int Depth, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.AttachMovie");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = symbolname;
			*(ScriptString**)&params[12] = instancename;
			*(int*)&params[24] = Depth;
			*(ScriptClass**)&params[28] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[32];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.WidgetInitialized");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool WidgetUnloaded(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxObject.WidgetUnloaded");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
